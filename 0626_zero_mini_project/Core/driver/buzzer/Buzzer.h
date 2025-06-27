/*
 * Buzzer.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_BUZZER_BUZZER_H_
#define DRIVER_BUZZER_BUZZER_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

typedef struct
{
	uint32_t DO;
	uint32_t DO_SHARP;
	uint32_t RE;
	uint32_t RE_SHARP;
	uint32_t MI;
	uint32_t FA;
	uint32_t FA_SHARP;
	uint32_t SOL;
	uint32_t SOL_SHARP;
	uint32_t LA;
	uint32_t LA_SHARP;
	uint32_t SI;
}Sound_TypeDef;


void Buzzer_Init(TIM_HandleTypeDef *htim, uint32_t channel);
void Buzzer_SetFreq(uint32_t freq);
void Buzzer_Start();
void Buzzer_Stop();

#endif /* DRIVER_BUZZER_BUZZER_H_ */
