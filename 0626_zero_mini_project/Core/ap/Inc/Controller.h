/*
 * Controller.h
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#ifndef AP_CONTROLLER_H_
#define AP_CONTROLLER_H_

#include "stopWatch.h"
#include "timeWatch.h"
#include "Model_Watch.h"
#include <string.h>

enum {STOPWATCH_RUN_STOP, STOPWATCH_CLEAR};
enum {NO_CONTROL, LCD_MODE, RUN_STOP, MODE, SPEED, ULTRA, SONG};
enum {LCD_OFF=0, RUN_DIST, CAL_SPEED, SONG_TITLE, WARNING};

typedef struct{
	watch_t current_time;
	watch_t running_time;
	uint8_t speed;
	double distance;
	double calories;
	uint8_t runstop;
	uint8_t lcd_mode;
	uint8_t song;
	uint8_t ultra;
	char uartRxData;
} C2P_Data;

typedef struct {
	int id;
	int ultra_data;
	int lcd_data;
	int speed_data;
	int song_data;
	char uart_data;
}inputData_TypeDef;

extern inputData_TypeDef controlData;

void Controller_SetInputData(inputData_TypeDef inputData);
void Controller_Excute();
extern void Controller_OutData(C2P_Data *c2p_data);

#endif /* AP_CONTROLLER_H_ */
