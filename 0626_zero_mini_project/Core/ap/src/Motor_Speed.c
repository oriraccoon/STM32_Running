/*
 * Motor_Speed.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include "Motor_Speed.h"

void Motor_Init()
{
	DC_Motor_Init(&htim1, TIM_CHANNEL_2);
}

void Motor_Start(uint32_t speed)
{
	DC_Motor_SetFreq(speed);
	DC_Motor_Start();
}

void Motor_Stop()
{
	DC_Motor_Stop();
}
