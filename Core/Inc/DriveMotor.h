/*
 * DriveMotor.h
 *
 *  Created on: Jan 16, 2021
 *      Author: naoto
 */

#ifndef DRIVEMOTOR_H_
#define DRIVEMOTOR_H_

#include "main.h"

class DriveMotor {
public:
	DriveMotor();
	virtual ~DriveMotor();
	void toggleLed(void);
};

#endif /* DRIVEMOTOR_H_ */
