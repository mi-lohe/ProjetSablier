/*
 * servo.c
 *
 *  Created on: 15 f�vr. 2021
 *      Author: brassemi
 */

#include "stm32f1_gpio.h"
#include "macro_types.h"
#include "config.h"
#include "stm32f1_timer.h"

#define PERIOD_TIMER 10 //ms

static uint16_t current_position;


void SERVO_init(void)
{
//initialisation et lancement du timer1 � une p�riode de 10 ms
TIMER_run_us(TIMER1_ID, PERIOD_TIMER*1000, FALSE); //10000us = 10ms
//activation du signal PWM sur le canal 1 du timer 1 (broche PA8)
TIMER_enable_PWM(TIMER1_ID, TIM_CHANNEL_1, 150);
//rapport cyclique regl� pour une position servo de 50%
SERVO_set_position(50);
}

void SERVO_set_position(uint16_t position)
{
	static uint16_t duty;

	if(position > 100)
		position = 100; //Ecr�tage si l'utilisateur demande plus de 100%

	current_position = position;

	duty = position + 100;

	//TODO : mise � jour du rapport cyclique.

	TIMER_set_duty(TIMER1_ID, TIM_CHANNEL_1,duty);


//duty doit �tre exprim� ici de 100 � 200 (sur 1000) (pour un rapport cyclique
///de 10% � 20%, c�est-�-dire une dur�e de pulse de 1 � 2ms dans la p�riode de 10ms)
//Donc on additionne 100 � position.
}

uint16_t SERVO_get_position(void)
{

return current_position;

}









