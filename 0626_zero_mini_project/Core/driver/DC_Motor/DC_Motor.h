/*
 * DC_Motor.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_DC_MOTOR_DC_MOTOR_H_
#define DRIVER_DC_MOTOR_DC_MOTOR_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

void DC_Motor_Init(TIM_HandleTypeDef *htim, uint32_t channel);
void DC_Motor_SetFreq(uint32_t freq);
void DC_Motor_Start();
void DC_Motor_Stop();

#endif /* DRIVER_DC_MOTOR_DC_MOTOR_H_ */
