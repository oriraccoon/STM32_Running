/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */

#include "Listener.h"
#include "usart.h"
#include <stdio.h>
#include <string.h>

static void Listener_CheckButton();
static void Listener_CheckUart();

static uint8_t rcvData = 0;
static Que_TypeDef uartRxQue;
static uint8_t toggleFlag = 0;

static int flag = 0;

inputData_TypeDef inputData = { 0 };

void Listener_Init() {
	Button_Init(&hBtnLcdMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnSpeedUp, GPIOA, GPIO_PIN_10);
	Button_Init(&hBtnSpeedDown, GPIOA, GPIO_PIN_7); // modify the pin number

	Que_Init(&uartRxQue);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // uart recv interrupt enable
}

void Listener_Excute() {
	Listener_CheckButton();
	Listener_CheckUart();
	Listener_CheckUltra();
}

void Listener_CheckButton() {
	static uint32_t prevChkBtnTime = 0;
	uint32_t curTick = HAL_GetTick();
	if (curTick - prevChkBtnTime < 80) {
		return;
	}
	prevChkBtnTime = curTick;

	if (Button_GetState(&hBtnLcdMode) == ACT_RELEASED) {
		inputData.id = LCD_MODE;
		if (inputData.lcd_data >= 3) {
			inputData.lcd_data = 1;
		} else {
			inputData.lcd_data++;
		}
		Controller_SetInputData(inputData);
	} else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED) {
		inputData.id = RUN_STOP;
		toggleFlag ^= 1;
		inputData.lcd_data = toggleFlag;
		inputData.speed_data = toggleFlag;
		Controller_SetInputData(inputData);
		inputData.id = NO_CONTROL;
	} else if (Button_GetState(&hBtnSpeedUp) == ACT_PUSHED) {
		inputData.id = SPEED;
		if (inputData.lcd_data != 0) {
			if (inputData.speed_data >= 9) {
				inputData.speed_data = 9;
			} else {
				inputData.speed_data++;
			}
		}
		Controller_SetInputData(inputData);
	} else if (Button_GetState(&hBtnSpeedDown) == ACT_PUSHED) {
		inputData.id = SPEED;
		if (inputData.lcd_data != 0) {
			if (inputData.speed_data == 1) {
				inputData.speed_data = 1;
			} else {
				inputData.speed_data--;
			}
		}
		Controller_SetInputData(inputData);
	}
}

void Listener_CheckUart() {
	if (isQueEmpty(&uartRxQue)) {
		return;
	}
	int uartRxData = deQue(&uartRxQue);

	inputData_TypeDef inputData;

	if (uartRxData == 'v') {
		flag = 1;
		inputData.id = SPEED;
		inputData.uart_data = 'v';
		inputData.lcd_data = 2;
		inputData.speed_data = 1;
		Controller_SetInputData(inputData);
	} else if (uartRxData == 's') {
		inputData.id = SONG;
		inputData.song_data = 1;
		flag = 2;
		inputData.uart_data = 's';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '1') {
		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 1;
		} else if (flag == 2) {
			inputData.id = SONG;
			inputData.song_data = 1;
		}
		inputData.uart_data = '1';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '2') {
		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 2;
		} else if (flag == 2) {
			inputData.id = SONG;
			inputData.song_data = 2;
		}
		inputData.uart_data = '2';

		Controller_SetInputData(inputData);
	} else if (uartRxData == '3') {
		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 3;
		} else if (flag == 2) {
			inputData.id = SONG;
			inputData.song_data = 3;
		}
		inputData.uart_data = '3';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '4') {
		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 4;
		}
		inputData.uart_data = '4';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '5') {

		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 5;
		}

		inputData.uart_data = '5';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '6') {

		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 6;
		}
		inputData.uart_data = '6';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '7') {

		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 7;
		}
		inputData.uart_data = '7';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '8') {

		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 8;
		}
		inputData.uart_data = '8';
		Controller_SetInputData(inputData);
	} else if (uartRxData == '9') {

		if (flag == 1) {
			inputData.id = SPEED;
			inputData.speed_data = 9;
		}
		inputData.uart_data = '9';
		Controller_SetInputData(inputData);
	}
}

void Listener_UartCallBack() {
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // interrupt enable
}

void Listener_CheckUltra() {
	int getDist = 0;
	getDist = ultra_execute();
	if (getDist) {
		inputData.ultra_data = getDist;
	}
	Controller_SetInputData(inputData);
}

