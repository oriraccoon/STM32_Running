/*
 * Buzzer.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include <DC_Motor.h>

static TIM_HandleTypeDef *hmotorTim;
static uint32_t motorTimChannel;

void DC_Motor_Init(TIM_HandleTypeDef *htim, uint32_t channel)
{
	hmotorTim = htim;
	motorTimChannel = channel;
}

void DC_Motor_SetFreq(uint32_t freq)
{
	if (freq < 1) {
		freq = 1;
	}
	else if (freq > 10000) {
		freq = 10000;
	}
	__HAL_TIM_SET_AUTORELOAD(hmotorTim, 1000000/freq-1);
	__HAL_TIM_SET_COMPARE(hmotorTim, motorTimChannel, 1000000/freq/2-1);
}

void DC_Motor_Start()
{
	HAL_TIM_PWM_Start(hmotorTim, motorTimChannel);
}
void DC_Motor_Stop()
{
	HAL_TIM_PWM_Stop(hmotorTim, motorTimChannel);
}
