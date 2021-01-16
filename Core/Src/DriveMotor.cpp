/*
 * DriveMotor.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: naoto
 */

#include "DriveMotor.h"

void DriveMotor::Init(void) {
	//A4988 EN PIN initialize => GPIO_PIN_SET:HIGH (Motor power OFF)
	HAL_GPIO_WritePin(A4988_EN_X1_GPIO_Port, A4988_EN_X1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(A4988_EN_X2_GPIO_Port, A4988_EN_X2_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(A4988_EN_Y1_GPIO_Port, A4988_EN_Y1_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(A4988_EN_Y2_GPIO_Port, A4988_EN_Y2_Pin, GPIO_PIN_SET);
	//A4988 DIR PIN initialize => 0
	HAL_GPIO_WritePin(A4988_DIR_X_GPIO_Port, A4988_DIR_X_Pin, GPIO_PIN_RESET);
	HAL_GPIO_WritePin(A4988_DIR_Y_GPIO_Port, A4988_DIR_Y_Pin, GPIO_PIN_RESET);
	//A4988 STEP PIN initialize => 1
	HAL_GPIO_WritePin(A4988_STEP_X_GPIO_Port, A4988_STEP_X_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(A4988_STEP_Y_GPIO_Port, A4988_STEP_Y_Pin, GPIO_PIN_SET);

	this->state_enable = 0;
	this->count_x1_ref = 0;
	this->count_x1 = 0;
	this->count_x2_ref = 0;
	this->count_x2 = 0;
	this->count_y1_ref = 0;
	this->count_y1 = 0;
	this->count_y2_ref = 0;
	this->count_y2 = 0;
}

void DriveMotor::dm(uint32_t pulse, Drive_Motor_Direction_TypeDef dir,
		Drive_Motor_Select_TypeDef select, uint32_t speed) {
	//Todo:speedの調整を効くようにする。
	switch (select) {
	case MOTOR_X1:
		if (dir == MOTOR_DIR_FORWARD)
			HAL_GPIO_WritePin(A4988_DIR_X_GPIO_Port, A4988_DIR_X_Pin,
					GPIO_PIN_RESET);
		if (dir == MOTOR_DIR_REVERSE)
			HAL_GPIO_WritePin(A4988_DIR_X_GPIO_Port, A4988_DIR_X_Pin,
					GPIO_PIN_SET);
		this->state_enable += MOTOR_X1;
		this->count_x1_ref = pulse;
		this->count_x1 = 0;
		HAL_GPIO_WritePin(A4988_EN_X1_GPIO_Port, A4988_EN_X1_Pin,
				GPIO_PIN_RESET);
		break;
	case MOTOR_X2:
		if (dir == MOTOR_DIR_FORWARD)
			HAL_GPIO_WritePin(A4988_DIR_X_GPIO_Port, A4988_DIR_X_Pin,
					GPIO_PIN_RESET);
		if (dir == MOTOR_DIR_REVERSE)
			HAL_GPIO_WritePin(A4988_DIR_X_GPIO_Port, A4988_DIR_X_Pin,
					GPIO_PIN_SET);
		this->state_enable += MOTOR_X2;
		this->count_x2_ref = pulse;
		this->count_x2 = 0;
		HAL_GPIO_WritePin(A4988_EN_X2_GPIO_Port, A4988_EN_X2_Pin,
				GPIO_PIN_RESET);
		break;
	case MOTOR_Y1:
		if (dir == MOTOR_DIR_FORWARD)
			HAL_GPIO_WritePin(A4988_DIR_Y_GPIO_Port, A4988_DIR_Y_Pin,
					GPIO_PIN_RESET);
		if (dir == MOTOR_DIR_REVERSE)
			HAL_GPIO_WritePin(A4988_DIR_Y_GPIO_Port, A4988_DIR_Y_Pin,
					GPIO_PIN_SET);
		this->state_enable += MOTOR_Y1;
		this->count_y1_ref = pulse;
		this->count_y1 = 0;
		HAL_GPIO_WritePin(A4988_EN_Y1_GPIO_Port, A4988_EN_Y1_Pin,
				GPIO_PIN_RESET);
		break;
	case MOTOR_Y2:
		if (dir == MOTOR_DIR_FORWARD)
			HAL_GPIO_WritePin(A4988_DIR_Y_GPIO_Port, A4988_DIR_Y_Pin,
					GPIO_PIN_RESET);
		if (dir == MOTOR_DIR_REVERSE)
			HAL_GPIO_WritePin(A4988_DIR_Y_GPIO_Port, A4988_DIR_Y_Pin,
					GPIO_PIN_SET);
		this->state_enable += MOTOR_Y2;
		this->count_y2_ref = pulse;
		this->count_y2 = 0;
		HAL_GPIO_WritePin(A4988_EN_Y2_GPIO_Port, A4988_EN_Y2_Pin,
				GPIO_PIN_RESET);
		break;
	default:
		//error
		break;
	}
}

void DriveMotor::dm_timer_CBF(void) {
	if (this->state_enable != 0x00) {
		HAL_GPIO_TogglePin(A4988_STEP_X_GPIO_Port, A4988_STEP_X_Pin);
		HAL_GPIO_TogglePin(A4988_STEP_Y_GPIO_Port, A4988_STEP_Y_Pin);
	}

	if ((this->state_enable >> 0) & 0x01 == 0x01) {
		this->count_x1++;
		if (this->count_x1 > this->count_x1_ref * 2) {
			//規定の回転数になったため、停止する。
			HAL_GPIO_WritePin(A4988_EN_X1_GPIO_Port, A4988_EN_X1_Pin,
					GPIO_PIN_SET);
			this->state_enable -= MOTOR_X1;
			this->count_x1 = 0;
			this->count_x1_ref = 0;
		}
	}
	if ((this->state_enable >> 1) & 0x01 == 0x01) {
		this->count_x2++;
		if (this->count_x2 > this->count_x2_ref * 2) {
			//規定の回転数になったため、停止する。
			HAL_GPIO_WritePin(A4988_EN_X2_GPIO_Port, A4988_EN_X2_Pin,
					GPIO_PIN_SET);
			this->state_enable -= MOTOR_X2;
			this->count_x2 = 0;
			this->count_x2_ref = 0;
		}
	}
	if ((this->state_enable >> 2) & 0x01 == 0x01) {
		this->count_y1++;
		if (this->count_y1 > this->count_y1_ref * 2) {
			//規定の回転数になったため、停止する。
			HAL_GPIO_WritePin(A4988_EN_Y1_GPIO_Port, A4988_EN_Y1_Pin,
					GPIO_PIN_SET);
			this->state_enable -= MOTOR_Y1;
			this->count_y1 = 0;
			this->count_y1_ref = 0;
		}
	}
	if ((this->state_enable >> 3) & 0x01 == 0x01) {
		this->count_y2++;
		if (this->count_y2 > this->count_y2_ref * 2) {
			//規定の回転数になったため、停止する。
			HAL_GPIO_WritePin(A4988_EN_Y2_GPIO_Port, A4988_EN_Y2_Pin,
					GPIO_PIN_SET);
			this->state_enable -= MOTOR_Y2;
			this->count_y2 = 0;
			this->count_y2_ref = 0;
		}
	}
}

void DriveMotor::moveX(uint32_t pulse, Drive_Motor_Direction_TypeDef dir) {
	this->dm(pulse, dir, MOTOR_X1, 0);
	this->dm(pulse, dir, MOTOR_X2, 0);
}

void DriveMotor::moveY(uint32_t pulse, Drive_Motor_Direction_TypeDef dir) {
	this->dm(pulse, dir, MOTOR_Y1, 0);
	this->dm(pulse, dir, MOTOR_Y2, 0);
}
