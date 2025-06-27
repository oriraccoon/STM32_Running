/*
 * Ultra.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include "Ultra.h"

Ultra_TypeDef Ultra_Trig = {GPIOC, GPIO_PIN_2};
Ultra_TypeDef Ultra_Echo = {GPIOC, GPIO_PIN_3};

static void Ultra_Trig_Setup();

static int distance;

void delay_us(uint32_t num)
{
	htim4.Instance->CNT = 0;
	while(htim4.Instance->CNT < num);
}


void Ultra_Trig_Setup()
{
	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, RESET);
	delay_us(10);
	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, SET);
	delay_us(10);
	HAL_GPIO_WritePin(Ultra_Trig.GPIOx, Ultra_Trig.pinNum, RESET);

}

int Ultra_Start()
{
	Ultra_Trig_Setup();

	while(HAL_GPIO_ReadPin(Ultra_Echo.GPIOx, Ultra_Echo.pinNum) == 0)
	{
		if(htim4.Instance->CNT >= 300000) return -1;
	}

	htim4.Instance->CNT = 0;
	while(HAL_GPIO_ReadPin(Ultra_Echo.GPIOx, Ultra_Echo.pinNum) == 1)
	{
		if(htim4.Instance->CNT >= 30000) return -1;
	}

	if (htim4.Instance->CNT > 0) distance = htim4.Instance->CNT / 58;

	return distance;
}

