/*
 * Presenter.h
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#ifndef AP_PRESENTER_H_
#define AP_PRESENTER_H_

#include "Controller.h"
#include "FND.h"
#include "lcd.h"
#include "LedBar.h"
#include "Motor_Speed.h"
#include "Sound.h"



void Presenter_Init();
void Presenter_Excute();
void Presenter_OutData(C2P_Data c2p_data);
void Presenter_UartCallBack();
void Presenter_DispLEDMsbToggle();


#endif /* AP_PRESENTER_H_ */
