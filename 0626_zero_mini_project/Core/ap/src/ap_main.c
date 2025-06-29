/*
 * ap_main.c
 *
 *  Created on: Jun 19, 2025
 *      Author: rhoblack
 */

#include "ap_main.h"

int inde = 0;
int ind = 0;

C2P_Data c2p;
static int pre_song = 0;
static int ultraCnt=0;

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	Controller_OutData(&c2p);
	//ultra_execute();
	if(htim->Instance == TIM2) {
		FND_DispDataCallBack();

		TimeWatch_IncTimeCallBack();
		StopWatch_IncTimeCallBack();

	}

	if(htim->Instance == TIM5 && c2p.runstop && pre_song == c2p.song){ // buzzer
		if (ind >= 50) {
			if (c2p.song == 1){
				Buzzer_SetFreq(Song1[inde]);
				if (inde == 95){
					inde = 0;
				}
				else{
					inde ++;
				}
			}
			else if (c2p.song == 2){
				Buzzer_SetFreq(song2[inde]);
				if (inde == 15){
					inde = 0;
				}
				else{
					inde ++;
				}
			}
			else if (c2p.song == 3){
				Buzzer_SetFreq(song2[inde]);
				if (inde == 15){
					inde = 0;
				}
				else{
					inde ++;
				}
			}
			Buzzer_Start();
			ind = 0;
		}
		else if (ind >= 25)
		{
			Buzzer_Stop();
			ind += c2p.speed;
		}
		else ind += c2p.speed;
	}
	else if (c2p.runstop == 0 || pre_song != c2p.song){
		ind = 0;
		inde = 0;
		Buzzer_Stop();
		pre_song = c2p.song;
	}

	// LED MSB Toggle
	if (htim->Instance == TIM11) {
		Presenter_DispLEDMsbToggle();
	}

	if (htim->Instance == TIM10)
	{
		ultra_flag = 1;
	}

}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if (huart->Instance == USART2) {
		Listener_UartCallBack();
	}
}


int ap_main()
{
	HAL_TIM_Base_Start_IT(&htim2);
	HAL_TIM_Base_Start_IT(&htim5);
	HAL_TIM_Base_Start_IT(&htim10);
	HAL_TIM_Base_Start_IT(&htim11);

	while(1)
	{
		Listener_Excute();
		Controller_Excute();
		Presenter_Excute();
	}

	return 0;
}

void ap_init()
{
	Listener_Init();
	Presenter_Init();
}



