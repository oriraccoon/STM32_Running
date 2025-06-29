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

const int Song1[] = {
		// 운명 주제 (1~2번째 파트)
		392, 392, 392, 311,   // G4 G4 G4 Eb4
		349, 349, 349, 294,   // F4 F4 F4 D4
		392, 392, 392, 311,   // G4 G4 G4 Eb4
		349, 349, 349, 294,   // F4 F4 F4 D4
		392, 392, 784, 622,   // G4 G4 G5 Eb5
		587, 523, 494, 440,   // D5 C5 B4 A4
		392, 440, 392,        // G4 A4 G4

		// 🎶 세 번째 파트: 상승 후 하강
		392, 392, 392, 392,   // G4 G4 G4 G4
		440, 494, 523, 587,   // A4 B4 C5 D5
		622, 587, 523, 494,   // Eb5 D5 C5 B4
		440, 392, 349, 311,   // A4 G4 F4 Eb4
		294,                  // D4'
		392, 440, 466, 466, 466, 440, 392, 349,  // G4 A4 Bb4 Bb4 Bb4 A4 G4 F4
		392, 440, 466, 466, 466, 440, 392, 349,  // G4 A4 Bb4 Bb4 Bb4 A4 G4 F4
		311, 294, 392, 392, 440, 392, 349, 311, 294, 311, 294, 262,
		311, 294, 392, 392, 440, 466, 440, 392,
		294, 311, 349, 392, 349, 294, 311, 392,
		392, 349, 311, 294, 262, 392, 392
};

const int song2[]= {
		261, 261, 392, 392,
		440, 440, 392, 392,
		349, 349, 329, 329,
		294, 294, 261, 261
};

const int song3[] = {
		311, 311, 311, 311, 311, 311, 311, 311
};

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
	Buzzer_Stop() ;
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
	HAL_Delay(longGap);
	HAL_Delay(longGap);
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

