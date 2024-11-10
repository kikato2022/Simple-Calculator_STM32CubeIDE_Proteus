/*
 * key_matrix.h
 *
 *  Created on: Nov 8, 2024
 *      Author: Admin
 */

#ifndef KEY_MATRIX_KEY_MATRIX_H_
#define KEY_MATRIX_KEY_MATRIX_H_
#include "main.h"

// 说明：行(x),列(Y)
/******************************************
X0_Y0 1		X0_Y1 2		X0_Y2 3		X0_Y3 A
X1_Y0 4		X1_Y1 5		X1_Y2 6		X1_Y3 B
X2_Y0 7		X2_Y1 8		X2_Y2 9		X2_Y3 C
X3_Y0 D		X3_Y1 0		X3_Y2 E		X3_Y3 F
******************************************/



#define Y0	HAL_GPIO_ReadPin(Y0_GPIO_Port, Y0_Pin)
#define Y1	HAL_GPIO_ReadPin(Y1_GPIO_Port, Y1_Pin)
#define Y2	HAL_GPIO_ReadPin(Y2_GPIO_Port, Y2_Pin)
#define Y3	HAL_GPIO_ReadPin(Y3_GPIO_Port, Y3_Pin)

#define X0_DOWN HAL_GPIO_WritePin(X0_GPIO_Port , X0_Pin , GPIO_PIN_RESET)
#define X0_UP 	HAL_GPIO_WritePin(X0_GPIO_Port , X0_Pin , GPIO_PIN_SET)
#define X1_DOWN HAL_GPIO_WritePin(X1_GPIO_Port , X1_Pin , GPIO_PIN_RESET)
#define X1_UP 	HAL_GPIO_WritePin(X1_GPIO_Port , X1_Pin , GPIO_PIN_SET)
#define X2_DOWN HAL_GPIO_WritePin(X2_GPIO_Port , X2_Pin , GPIO_PIN_RESET)
#define X2_UP 	HAL_GPIO_WritePin(X2_GPIO_Port , X2_Pin , GPIO_PIN_SET)
#define X3_DOWN HAL_GPIO_WritePin(X3_GPIO_Port , X3_Pin , GPIO_PIN_RESET)
#define X3_UP 	HAL_GPIO_WritePin(X3_GPIO_Port , X3_Pin , GPIO_PIN_SET)

int keyScan(void);

#endif /* KEY_MATRIX_KEY_MATRIX_H_ */
