/*
 * Ultra.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include "Ultra.h"
int ultra_flag = 0;

Ultra_TypeDef Ultra_Trig = { GPIOC, GPIO_PIN_2 };
Ultra_TypeDef Ultra_Echo = { GPIOC, GPIO_PIN_3 };

typedef enum {
	TRIG_IDLE, TRIG_LOW, TRIG_HIGH, TRIG_DONE
} TrigState;
static TrigState trigState = TRIG_IDLE;
static int distance = 0;
static uint32_t echoStart = 0;
static uint32_t echoEnd = 0;
static int d = 15;

int ultra_trig_set() {
	__HAL_TIM_SET_COUNTER(&htim10, 0);

	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, GPIO_PIN_RESET);
	__HAL_TIM_SET_COUNTER(&htim10, 0);
	while ( __HAL_TIM_GET_COUNTER(&htim10) < 10) {
	}
	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, GPIO_PIN_SET);
	__HAL_TIM_SET_COUNTER(&htim10, 0);
	while (__HAL_TIM_GET_COUNTER(&htim10) < 10) {
	}
	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, GPIO_PIN_RESET);
	return 1;
}

int ultra_start() {
	__HAL_TIM_SET_COUNTER(&htim10, 0);
	while (HAL_GPIO_ReadPin(Ultra_Echo.GPIOx, Ultra_Echo.pinNum)
			== GPIO_PIN_RESET) {
	}
	echoStart = __HAL_TIM_GET_COUNTER(&htim10);
	while (HAL_GPIO_ReadPin(Ultra_Echo.GPIOx, Ultra_Echo.pinNum) == GPIO_PIN_SET) {
	}
	echoEnd = __HAL_TIM_GET_COUNTER(&htim10);

	uint32_t diff =
			(echoEnd >= echoStart) ?
					(echoEnd - echoStart) : (0xFFFF - echoStart + echoEnd);
	distance = diff / 58;

	return distance;  // 측정 성공
}

uint8_t ultra_execute() {
	static int intrCnt = 0;
	if (!ultra_flag)
		return 0;
	ultra_flag = 0;
	intrCnt++;
	if (intrCnt < 10) {
		return 0;
	}
	intrCnt = 0;
	if (ultra_trig_set()) {
		d = ultra_start();  // 거리 측정 시작
		if (d != -1) {
			return d;
		}
	}
	return 0;
}
