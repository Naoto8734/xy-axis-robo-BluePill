/*
 * DriveMotor.h
 *
 *  Created on: Jan 16, 2021
 *      Author: naoto
 */

#ifndef DRIVEMOTOR_H_
#define DRIVEMOTOR_H_

#include "main.h"
#include <cstdint>

#define MOTOR_ROTATE_PULSE 200

typedef enum {
	MOTOR_X1 = 0x01U<<0, MOTOR_X2 = 0x01U<<1, MOTOR_Y1 = 0x01U<<2, MOTOR_Y2 = 0x01U<<3
} Drive_Motor_Select_TypeDef;

typedef enum {
	MOTOR_DIR_FORWARD = 0x00U, MOTOR_DIR_REVERSE = 0x01U
} Drive_Motor_Direction_TypeDef;

class DriveMotor {
	volatile uint32_t count_x1_ref;
	volatile uint32_t count_x1;
	volatile uint32_t count_x2_ref;
	volatile uint32_t count_x2;
	uint8_t state_enable;
public:
	void Init(void);
	void dm(uint32_t, Drive_Motor_Direction_TypeDef, Drive_Motor_Select_TypeDef, uint32_t);
	void dm_timer_CBF(void);
	void moveX(uint32_t, Drive_Motor_Direction_TypeDef);
};


#endif /* DRIVEMOTOR_H_ */
