/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_BUILTIN_Pin GPIO_PIN_13
#define LED_BUILTIN_GPIO_Port GPIOC
#define RDC80_X1_A_Pin GPIO_PIN_0
#define RDC80_X1_A_GPIO_Port GPIOA
#define RDC80_X1_B_Pin GPIO_PIN_1
#define RDC80_X1_B_GPIO_Port GPIOA
#define RDC80_X2_A_Pin GPIO_PIN_2
#define RDC80_X2_A_GPIO_Port GPIOA
#define RDC80_X2_B_Pin GPIO_PIN_3
#define RDC80_X2_B_GPIO_Port GPIOA
#define RDC80_Y1_A_Pin GPIO_PIN_4
#define RDC80_Y1_A_GPIO_Port GPIOA
#define RDC80_Y1_B_Pin GPIO_PIN_5
#define RDC80_Y1_B_GPIO_Port GPIOA
#define RDC80_Y2_A_Pin GPIO_PIN_6
#define RDC80_Y2_A_GPIO_Port GPIOA
#define RDC80_Y2_B_Pin GPIO_PIN_7
#define RDC80_Y2_B_GPIO_Port GPIOA
#define LIMIT_SW_Y2_Pin GPIO_PIN_0
#define LIMIT_SW_Y2_GPIO_Port GPIOB
#define LIMIT_SW_Y1_Pin GPIO_PIN_1
#define LIMIT_SW_Y1_GPIO_Port GPIOB
#define SW_B_Pin GPIO_PIN_10
#define SW_B_GPIO_Port GPIOB
#define SW_W_Pin GPIO_PIN_11
#define SW_W_GPIO_Port GPIOB
#define LED_R_Pin GPIO_PIN_12
#define LED_R_GPIO_Port GPIOB
#define A4988_DIR_Y_Pin GPIO_PIN_13
#define A4988_DIR_Y_GPIO_Port GPIOB
#define A4988_EN_Y1_Pin GPIO_PIN_14
#define A4988_EN_Y1_GPIO_Port GPIOB
#define A4988_EN_Y2_Pin GPIO_PIN_15
#define A4988_EN_Y2_GPIO_Port GPIOB
#define LIMIT_SW_X1_Pin GPIO_PIN_9
#define LIMIT_SW_X1_GPIO_Port GPIOA
#define LIMIT_SW_X1_EXTI_IRQn EXTI9_5_IRQn
#define LIMIT_SW_X2_Pin GPIO_PIN_10
#define LIMIT_SW_X2_GPIO_Port GPIOA
#define LIMIT_SW_X2_EXTI_IRQn EXTI15_10_IRQn
#define A4988_DIR_X_Pin GPIO_PIN_3
#define A4988_DIR_X_GPIO_Port GPIOB
#define A4988_EN_X1_Pin GPIO_PIN_4
#define A4988_EN_X1_GPIO_Port GPIOB
#define A4988_EN_X2_Pin GPIO_PIN_5
#define A4988_EN_X2_GPIO_Port GPIOB
#define A4988_STEP_Y_Pin GPIO_PIN_8
#define A4988_STEP_Y_GPIO_Port GPIOB
#define A4988_STEP_X_Pin GPIO_PIN_9
#define A4988_STEP_X_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
