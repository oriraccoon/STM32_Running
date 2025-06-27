/*
 * Listener.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */


#include "Listener.h"
#include "usart.h"

static void Listener_CheckButton();
static void Listener_CheckUart();
static void Listener_CheckUltra();

static uint8_t rcvData = 0;
static Que_TypeDef uartRxQue;

inputData_TypeDef inputData = {0};

void Listener_Init()
{
	Button_Init(&hBtnLcdMode, GPIOB, GPIO_PIN_5);
	Button_Init(&hBtnRunStop, GPIOB, GPIO_PIN_3);
	Button_Init(&hBtnSpeedUp, GPIOA, GPIO_PIN_10);
	Button_Init(&hBtnSpeedDown, GPIOA, GPIO_PIN_10); // modify the pin number

	Que_Init(&uartRxQue);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // uart recv interrupt enable
}

void Listener_Excute()
{
	Listener_CheckButton();
	Listener_CheckUart();
	Listener_CheckUltra();
}

void Listener_CheckButton()
{
	static uint32_t prevChkBtnTime = 0;
	uint32_t curTick = HAL_GetTick();
	if (curTick - prevChkBtnTime < 100) {
		return;
	}
	prevChkBtnTime = curTick;

	if (Button_GetState(&hBtnLcdMode) == ACT_RELEASED) {
		inputData.id = LCD_MODE;
		if (inputData.data >= 3){
			inputData.data = 1;
		}
		else{
			inputData.data ++;
		}
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnRunStop) == ACT_PUSHED) {
		inputData.id = RUN_STOP;
		inputData.data = 1;
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnSpeedUp) == ACT_PUSHED) {
		inputData.id = SPEED;
		if (inputData.data >= 9){
			inputData.data = 9;
		}
		else{
			inputData.data ++;
		}
		Controller_SetInputData(inputData);
	}
	else if (Button_GetState(&hBtnSpeedDown) == ACT_PUSHED) {
		inputData.id = SPEED;
		if (inputData.data == 0){
			inputData.data = 0;
		}
		else{
			inputData.data --;
		}
		Controller_SetInputData(inputData);
	}
}

void Listener_CheckUart()
{
	if (isQueEmpty(&uartRxQue)) {
		return;
	}
	int uartRxData = deQue(&uartRxQue);

	inputData_TypeDef inputData;

	if (uartRxData == 'v') {
		inputData.id = SPEED;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == 's') {
		inputData.id = SONG;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '1') {
		inputData.data = 1;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '2') {
		inputData.data = 2;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '3') {
		inputData.data = 3;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '4') {
		inputData.data = 4;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '5') {
		inputData.data = 5;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '6') {
		inputData.data = 6;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '7') {
		inputData.data = 7;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '8') {
		inputData.data = 8;
		Controller_SetInputData(inputData);
	}
	else if (uartRxData == '9') {
		inputData.data = 9;
		Controller_SetInputData(inputData);
	}
}

void Listener_UartCallBack()
{
	enQue(&uartRxQue, rcvData);
	HAL_UART_Receive_IT(&huart2, &rcvData, 1); // interrupt enable
}

void Listener_CheckUltra(){
	//inputData.data = Ultra_Start();
}

















