/*
 * Presenter.c
 *
 *  Created on: Jun 24, 2025
 *      Author: rhoblack
 */
#include "Presenter.h"
#include <string.h>
#include <stdio.h>
#include "usart.h"

static int onOffFlag = 0;
static int msb_pos = 0;
static int led_data = 0;
static int UartFlag = 1;

// fnd
static void Presenter_DispFnd_CurrentTime(watch_t current_time);

// uart
static void Presenter_DispMonitor(char uartRxData);
static void Presenter_DispMonitorInfo();
static void Presenter_DispMonitorSpeedInfo();
static void Presenter_DispMonitorSongInfo();
static void Presenter_DispMonitorDone();

// lcd
static void Presenter_DispLCD(uint8_t lcd_mode);
static void Presenter_DispLCD_RUN_DIST(watch_t running_time, double distance);
static void Presenter_DispLCD_CAL_SPEED(double calories, uint8_t speed);
static void Presenter_DispLCD_SONG_TITLE(uint8_t song);
static void Presenter_DispLCD_WARNING();

static uint8_t prev_lcd_mode = LCD_OFF;

// led
static void Presenter_DispLED_Dist(double dist);


// motor
static void Presenter_SpeedMotor(uint8_t speed);

// Controller to Presenter Data
static C2P_Data p_data;

// Initial Func
void Presenter_Init()
{
	LCD_Init(&hi2c1);
	Motor_Init();
	Sound_Init();
	Presenter_DispMonitorInfo();
}


// Behavior Func at ap_main.c
void Presenter_Excute()
{
	if (p_data.runstop == 1 && onOffFlag == 0) {
		onOffFlag = 1;
		//Sound_POWERON();
	}
	else if (p_data.runstop == 0 && onOffFlag == 1) {
		onOffFlag = 0;
		//Sound_POWEROFF();
	}
	Controller_OutData(&p_data);
	Presenter_DispLCD(p_data.lcd_mode);
	Presenter_DispMonitor(p_data.uartRxData);
	Presenter_DispFnd_CurrentTime(p_data.current_time);
	Presenter_DispLED_Dist(p_data.distance);
	Presenter_SpeedMotor(p_data.speed);
}

// LCD DISP
void Presenter_DispLCD(uint8_t lcd_mode)
{
	if (prev_lcd_mode != lcd_mode) {
		LCD_writeStringXY(0, 0, "                ");
		LCD_writeStringXY(1, 0, "                ");
	}
	switch (lcd_mode) {
	case LCD_OFF:
		break;
	case RUN_DIST:
		Presenter_DispLCD_RUN_DIST(p_data.running_time, p_data.distance);
		break;
	case CAL_SPEED:
		Presenter_DispLCD_CAL_SPEED(p_data.calories, p_data.speed);
		break;
	case SONG_TITLE:
		Presenter_DispLCD_SONG_TITLE(p_data.song);
		break;
	case WARNING:
		Presenter_DispLCD_WARNING();
		break;
	}
	prev_lcd_mode = lcd_mode;
}

// UART DISP
void Presenter_DispMonitor(char uartRxData)
{
	switch (uartRxData) {
	case 'v':
		if (UartFlag)
			Presenter_DispMonitorSpeedInfo();
		UartFlag = 0;
		break;
	case 's':
		if (UartFlag)
			Presenter_DispMonitorSongInfo();
		UartFlag = 0;
		break;
	case '1':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '2':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '3':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '4':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '5':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '6':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '7':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '8':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;
	case '9':
		if (UartFlag == 0){
			Presenter_DispMonitorDone();
			Presenter_DispMonitorInfo();
			UartFlag = 1;
		}
		break;

	default:

		break;
	}
}


// MOTOR RUN
void Presenter_SpeedMotor(uint8_t speed)
{
	if (speed == 0) Motor_Stop();
	else Motor_Start((5000-(speed*100)));
}

void Presenter_DispFnd_CurrentTime(watch_t current_time)
{
	FND_WriteData(current_time.hour*100 + current_time.min);

	FND_WriteDp(FND_DP_1000|FND_DP_10|FND_DP_1, FND_DP_OFF);

	if (current_time.msec < 500) {
		FND_WriteDp(FND_DP_100, FND_DP_ON);
	}
	else {
		FND_WriteDp(FND_DP_100, FND_DP_OFF);
	}
}


// UART Monitor Info(Speed, Song)
void Presenter_DispMonitorInfo() // start
{
	char str[60];
	strcpy(str,"Choose number\n1. Speed Setting(v)\t2. Choose Song(s)\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}
void Presenter_DispMonitorSpeedInfo()
{
	char str[50];
	strcpy(str,"Type 0~9 Speed:\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}
void Presenter_DispMonitorSongInfo()
{
	char str[50];
	strcpy(str,"Choose Song\n1. Beethoven\t2. Star\t3. Warning\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}
void Presenter_DispMonitorDone()
{
	char str[50];
	strcpy(str,"Complete\n");
	HAL_UART_Transmit(&huart2, (uint8_t *)str, strlen(str), 1000);
}


void Presenter_DispLCD_RUN_DIST(watch_t running_time, double distance)
{
		char str1[50];
		char str2[50];

		sprintf(str1, "RunTime:%02d:%02d:%02d", running_time.hour, running_time.min, running_time.sec);
		sprintf(str2, "distance:%.2fm", distance);

		LCD_writeStringXY(0, 0, str1);
		LCD_writeStringXY(1, 0, str2);
}


void Presenter_DispLCD_CAL_SPEED(double calories, uint8_t speed)
{
	char str1[50];
	char str2[50];

	sprintf(str1, "calories:%.2f", calories);
	sprintf(str2, "speed:%d", speed);

	LCD_writeStringXY(0, 0, str1);
	LCD_writeStringXY(1, 0, str2);

}

void Presenter_DispLCD_SONG_TITLE(uint8_t song)
{
	switch (song) {
	case 1:
		LCD_writeStringXY(0, 0, "Beethoven");
		break;
	case 2:
		LCD_writeStringXY(0, 0, "Star");
		break;
	case 3:
		LCD_writeStringXY(0, 0, "Warning");
		break;
	}
}

void Presenter_DispLCD_WARNING()
{
	char str1[50];
	LCD_writeStringXY(0, 0, "TOO FAR!!!");
}



// LED (Dist)
void Presenter_DispLED_Dist(double dist)
{
    static double sum = 0.0;
    static double prev = 0.0;
    static double prev2 = 0.0;
    prev += dist;
    prev2 = prev - prev2;

    sum += prev2;

    if(sum >= 50.0)
    {
        if(led_data == 0xff) led_data = 0;
        else led_data = (led_data << 1) + 1;
        sum -= 50.0;
    }

    for (int i = 6; i >= 0; i--) {
		if ((led_data >> i) & 1) {
			msb_pos = i+1;
			break;
		}
	}

    LedBar_Write(led_data);
}

// timer 사용해서 해야할듯
void Presenter_DispLEDMsbToggle()
{
	if (msb_pos == -1) return;

	led_data &= ~(1 << msb_pos);
}

