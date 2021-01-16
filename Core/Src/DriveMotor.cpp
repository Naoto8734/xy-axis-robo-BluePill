/*
 * DriveMotor.cpp
 *
 *  Created on: Jan 16, 2021
 *      Author: naoto
 */

#include "DriveMotor.h"

DriveMotor::DriveMotor() {
	// TODO Auto-generated constructor st
}

DriveMotor::~DriveMotor() {
	// TODO Auto-generated destructor stub
}

void DriveMotor::toggleLed(void) {
	HAL_GPIO_TogglePin(LED_BUILTIN_GPIO_Port, LED_BUILTIN_Pin);
	HAL_Delay(1000);
}
