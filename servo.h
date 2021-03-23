/*
 * servo.h
 *
 *  Created on: 15 févr. 2021
 *      Author: brassemi
 */

#ifndef SERVO_H_
#include "stm32f1xx_hal.h"

#include "stm32f1_uart.h"
#include "stm32f1_sys.h"

#include "sun_tracker.h"


#define SERVO_H_

void SERVO_init(void);
void SERVO_set_position(uint16_t);
uint16_t SERVO_get_position(void);


#endif /* SERVO_H_ */
