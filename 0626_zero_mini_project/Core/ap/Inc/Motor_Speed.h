/*
 * Motor_Speed.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef AP_INC_MOTOR_SPEED_H_
#define AP_INC_MOTOR_SPEED_H_

#include "DC_Motor.h"

void Motor_Init();
void Motor_Start(uint32_t speed);
void Motor_Stop();

#endif /* AP_INC_MOTOR_SPEED_H_ */
