/*
 * Controller.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */
#include "Controller.h"

static void Controller_Mode();
static void Time_curr();

inputData_TypeDef controlData = {0};
C2P_Data OutputData = {0};


void Controller_Excute()
{
	Controller_Mode();
}

void Controller_SetInputData(inputData_TypeDef inputData)
{
	if (inputData.id == LCD_MODE) {
		controlData.id = LCD_MODE;
	}
	else if (inputData.id == RUN_STOP) {
		controlData.id = RUN_STOP;
	}
	else if (inputData.id == SPEED) {
		controlData.id = SPEED;
	}
	else if(inputData.id == ULTRA){
		controlData.id = ULTRA;
	}
	else if(inputData.id == SONG){
		controlData.id = SONG;
	}
	controlData.data = inputData.data;
}

void Controller_Mode()
{
	Time_curr();
	switch(controlData.id)
	{
	case RUN_STOP:
		OutputData.runstop ^= 1;
		break;

	case LCD_MODE:
		OutputData.lcd_mode = controlData.data;
		break;

	case SPEED:
		OutputData.speed = controlData.data;
		break;

	case ULTRA:
		if (controlData.data > 100){
			OutputData.lcd_mode = WARNING;
			OutputData.song = 3;
		}
		break;

	case SONG:
		OutputData.song = controlData.data;
		break;
	}
}


void Time_curr(){
	uint8_t met;
	OutputData.running_time = StopWatch_Excute();
	OutputData.current_time = TimeWatch_Excute();
	OutputData.distance = (OutputData.current_time.hour - OutputData.running_time.hour)*OutputData.speed + OutputData.speed* (OutputData.current_time.min - OutputData.running_time.min)/60;

	switch(OutputData.speed){
	case 1:
		met = 15;
		break;
	case 2:
		met = 20;
		break;
	case 3:
		met = 28;
		break;
	case 4:
		met = 33;
		break;
	case 5:
		met = 38;
		break;
	case 6:
		met = 43;
		break;
	case 7:
		met = 60;
		break;
	case 8:
		met = 83;
		break;
	case 9:
		met = 98;
		break;
	}
	OutputData.calories = met * 72 * OutputData.distance /10;
}
