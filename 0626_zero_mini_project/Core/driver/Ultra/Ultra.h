/*
 * Ultra.h
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#ifndef DRIVER_ULTRA_ULTRA_H_
#define DRIVER_ULTRA_ULTRA_H_

#include "stm32f4xx_hal.h"
#include "tim.h"

#include "LedBar.h" // dbg



typedef struct {
	GPIO_TypeDef *GPIOx;
	uint32_t pinNum;
}Ultra_TypeDef;
extern int ultra_flag;
uint8_t ultra_execute();
/*
extern Ultra_TypeDef Ultra_Trig;


void delay_us(uint32_t num);
int Ultra_Start();
*/
#endif /* DRIVER_ULTRA_ULTRA_H_ */
