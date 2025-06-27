/*
 * Sound.c
 *
 *  Created on: Jun 26, 2025
 *      Author: kccistc
 */

#include "Sound.h"

void Sound_Init()
{
	Buzzer_Init(&htim3, TIM_CHANNEL_1);
}

void Sound_POWERON()
{
	Buzzer_SetFreq(OCT5.DO);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.MI);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.SOL);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.SI);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_Stop();
}

void Sound_POWEROFF()
{
	Buzzer_SetFreq(OCT5.SI);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.SOL);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.MI);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_SetFreq(OCT5.DO);
	Buzzer_Start();
	HAL_Delay(200);
	Buzzer_Stop();
}

void Sound_Beethoven5()
{
    // 짧은음 길이, 긴음 길이
    int shortDelay = 150;
    int shortGap = 50;
    int longDelay = 500;
    int longGap = 300;

    // 첫 번째 패턴: SOL SOL SOL MI♭
    Buzzer_SetFreq(OCT4.SOL);
    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_SetFreq(OCT4.RE_SHARP);  // MI♭는 RE#로 동일하게 처리
    Buzzer_Start();
    HAL_Delay(longDelay);
    Buzzer_Stop();
    HAL_Delay(longGap);

    // 두 번째 패턴: FA FA FA RE
    Buzzer_SetFreq(OCT4.FA);
    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_Start();
    HAL_Delay(shortDelay);
    Buzzer_Stop();
    HAL_Delay(shortGap);

    Buzzer_SetFreq(OCT4.RE);
    Buzzer_Start();
    HAL_Delay(longDelay);
    Buzzer_Stop();
}

void PlayNote(uint32_t freq, int duration)
{
    Buzzer_SetFreq(freq);
    Buzzer_Start();
    HAL_Delay(duration);
    Buzzer_Stop();
    HAL_Delay(50); // note gap
}

void Sound_MerryChristmasMrLawrence()
{
    int noteDuration = 300;

    // 사용: OCT4, OCT5
    PlayNote(OCT5.MI, noteDuration);           // E
    PlayNote(OCT5.RE, noteDuration);    // G#
    PlayNote(OCT5.MI, noteDuration);           // A
    PlayNote(OCT5.LA, noteDuration);           // B
    PlayNote(OCT5.MI, noteDuration);     // C#
    PlayNote(OCT5.RE, noteDuration);           // B
    PlayNote(OCT5.MI, noteDuration);           // A
    PlayNote(OCT5.RE, noteDuration);    // G#
    PlayNote(OCT5.MI, noteDuration);           // A
    PlayNote(OCT5.LA, noteDuration);           // B
    PlayNote(OCT5.MI, noteDuration);     // C#
    PlayNote(OCT5.RE, noteDuration);           // E
    PlayNote(OCT5.MI, noteDuration);           // D
    PlayNote(OCT5.RE, noteDuration);     // C#
}

