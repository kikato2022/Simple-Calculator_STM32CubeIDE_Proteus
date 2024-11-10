/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "lcd1602.h"
#include "key_matrix.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */
	char str0[10]="\0";
	char str1[10]="\0";
	char str2[10]="\0";

	char str[20]="\0";
  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  LCD_Init();  //初始化LCD1602
  LCD_ShowString(0,0,str);  //LCD 显示设定字符

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int num[3] = {0,0,0};
  int num_change_flag[3] = {0,0,0};

  int result = 0;
  int result_flag = 0;
  int invalid_input_flag = 0;

  char* op[2] = {"",""};
  int op_flag[2] = {0,0};

  int i = 0;


  while (1)
  {
	  int m = keyScan();
	  switch(m){
	  case 0:
		  result_flag = 0;
		  num[i] = num[i]*10+0;
		  num_change_flag[i] = 1;
		  break;
	  case 1:
		  result_flag = 0;
		  num[i] = num[i]*10+1;
		  num_change_flag[i] = 1;
		  break;
	  case 2:
		  result_flag = 0;
		  num[i] = num[i]*10+2;
		  num_change_flag[i] = 1;
		  break;
	  case 3:
		  result_flag = 0;
		  num[i] = num[i]*10+3;
		  num_change_flag[i] = 1;
		  break;
	  case 4:
		  result_flag = 0;
		  num[i] = num[i]*10+4;
		  num_change_flag[i] = 1;
		  break;
	  case 5:
		  result_flag = 0;
		  num[i] = num[i]*10+5;
		  num_change_flag[i] = 1;
		  break;
	  case 6:
		  result_flag = 0;
		  num[i] = num[i]*10+6;
		  num_change_flag[i] = 1;
		  break;
	  case 7:
		  result_flag = 0;
		  num[i] = num[i]*10+7;
		  num_change_flag[i] = 1;
		  break;
	  case 8:
		  result_flag = 0;
		  num[i] = num[i]*10+8;
		  num_change_flag[i] = 1;
		  break;
	  case 9:
		  result_flag = 0;
		  num[i] = num[i]*10+9;
		  num_change_flag[i] = 1;
		  break;
	  case 10: //CLR
		  num[0] = 0;
		  num[1] = 0;
		  num[2] = 0;
		  num_change_flag[0] = 0;
		  num_change_flag[1] = 0;
		  num_change_flag[2] = 0;

		  result = 0;
		  result_flag = 0;
		  invalid_input_flag = 0;

		  op[0] = "";
		  op[1] = "";
		  op_flag[0] = 0;
		  op_flag[0] = 0;

		  i=0;

		  LCD_Init();
		  break;
	  case 11: // *
		  result_flag = 0;
		  if(num_change_flag[0]==0) break;
		  if(num_change_flag[0]==1&&num_change_flag[1]==0){
			  i = 1;
			  op[0] = "*";
			  op_flag[0] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==0){
			  i = 2;
			  op[1] = "*";
			  op_flag[1] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==1){
			  break;
		  }
		  break;
	  case 12: // ÷
		  result_flag = 0;
		  if(num_change_flag[0]==0) break;
		  if(num_change_flag[0]==1&&num_change_flag[1]==0){
			  i = 1;
			  op[0] = "/";
			  op_flag[0] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==0){
			  i = 2;
			  op[1] = "/";
			  op_flag[1] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==1){
			  break;
		  }
		  break;
	  case 13: // +
		  result_flag = 0;
		  if(num_change_flag[0]==0) break;
		  if(num_change_flag[0]==1&&num_change_flag[1]==0){
			  i = 1;
			  op[0] = "+";
			  op_flag[0] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==0){
			  i = 2;
			  op[1] = "+";
			  op_flag[1] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==1){
			  break;
		  }
		  break;
	  case 14: // -
		  result_flag = 0;
		  if(num_change_flag[0]==0) break;
		  if(num_change_flag[0]==1&&num_change_flag[1]==0){
			  i = 1;
			  op[0] = "-";
			  op_flag[0] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==0){
			  i = 2;
			  op[1] = "-";
			  op_flag[1] = 1;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==1){
			  break;
		  }
		  break;
	  case 15: // =
		  LCD_Init();
		  result_flag = 1;
		  if(num_change_flag[0]==0){
			  ;
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==0){
			  result = num[0];
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==0){
			  if(!strcmp(op[0],"*")){
				  result = num[0]*num[1];
			  }else if(!strcmp(op[0],"/")){
				  if(num[1]==0) {
					  invalid_input_flag = 1;
					  break;
				  }
				  else result = num[0]/num[1];
			  }else if(!strcmp(op[0],"+")){
				  result = num[0]+num[1];
			  }else if(!strcmp(op[0],"-")){
				  result = num[0]-num[1];
			  }
		  }else if(num_change_flag[0]==1&&num_change_flag[1]==1&&num_change_flag[2]==1){
			  if((!strcmp(op[0],"*")||!strcmp(op[0],"/"))&&(!strcmp(op[1],"*")||!strcmp(op[1],"/"))){

				  if(!strcmp(op[0],"*")){
					  result = num[0]*num[1];
				  }else{
					  if(num[1]==0) {
						  invalid_input_flag = 1;
						  break;
					  }
					  else result = num[0]/num[1];
				  }

				  if(!strcmp(op[1],"*")){
					  result = result*num[2];
				  }else{
					  if(num[2]==0) {
						  invalid_input_flag = 1;
						  break;
					  }
					  else result = result/num[2];
				  }
			  }else if((!strcmp(op[0],"+")||!strcmp(op[0],"-"))&&(!strcmp(op[1],"+")||!strcmp(op[1],"-"))){
				  if(!strcmp(op[0],"+")){
					  result = num[0]+num[1];
				  }else{
					  result = num[0]-num[1];
				  }

				  if(!strcmp(op[1],"+")){
					  result = result+num[2];
				  }else{
					  result = result-num[2];
				  }
			  }else if((!strcmp(op[0],"*")||!strcmp(op[0],"/"))&&(!strcmp(op[1],"+")||!strcmp(op[1],"-"))){
				  if((!strcmp(op[0],"*")||!strcmp(op[0],"/"))){
					  if(!strcmp(op[0],"*")){
						  result = num[0]*num[1];
					  }else{
						  if(num[1]==0) {
							  invalid_input_flag = 1;
							  break;
						  }
						  else result = num[0]/num[1];
					  }
				  }
				  if(!strcmp(op[1],"+")){
					  result = result+num[2];
				  }else{
					  result = result-num[2];
				  }

			  }else if((!strcmp(op[0],"+")||!strcmp(op[0],"-"))&&(!strcmp(op[1],"*")||!strcmp(op[1],"/"))){
				  if((!strcmp(op[1],"*")||!strcmp(op[1],"/"))){
					  if(!strcmp(op[1],"*")){
						  result = num[1]*num[2];
					  }else{
						  if(num[2]==0) {
							  invalid_input_flag = 1;
							  break;
						  }
						  else result = num[1]/num[2];
					  }
				  }
				  if(!strcmp(op[0],"+")){
					  result = result+num[0];
				  }else{
					  result = num[0]-result;
				  }
			  }
		  }

		  if(invalid_input_flag==0) {
			  num[0] = result;
			  num[1] = 0;
			  num[2] = 0;
			  num_change_flag[0] = 1;
			  num_change_flag[1] = 0;
			  num_change_flag[2] = 0;

			  op[0] = "";
			  op[1] = "";
			  op_flag[0] = 0;
			  op_flag[0] = 0;

			  i=0;
		  }
		  break;
	  }


	  memset(str, '\0', sizeof(str));

	  if(result_flag){
		  if(invalid_input_flag) strcpy(str, "invalid input!");
		  else{
			  itoa(result, str, 10);
		  }
	  }else{
		  itoa(num[0], str0, 10);
		  itoa(num[1], str1, 10);
		  itoa(num[2], str2, 10);

		  if(num_change_flag[0])
			  strcat(str, str0);
		  if(op_flag[0])
			  strcat(str,op[0]);
		  if(num_change_flag[1])
			  strcat(str, str1);
		  if(op_flag[1])
			  strcat(str,op[1]);
		  if(num_change_flag[2])
			  strcat(str, str2);
	  }






	  //if(op_flag) strcat(str,op);
	  //if(flag[1]&&change_flag[1]) strcat(str,str2);
	  //itoa(num[0], str, 10);
//	  int len = strlen(str);
//	  itoa(len,str,10);
	  LCD_ShowString(0,0,str);  //LCD 显示设定字符
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};
/* USER CODE BEGIN MX_GPIO_Init_1 */
/* USER CODE END MX_GPIO_Init_1 */

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, X0_Pin|X1_Pin|X2_Pin|RS_Pin
                          |RW_Pin|E_Pin|X3_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : D0_Pin D1_Pin D2_Pin D3_Pin
                           D4_Pin D5_Pin D6_Pin D7_Pin */
  GPIO_InitStruct.Pin = D0_Pin|D1_Pin|D2_Pin|D3_Pin
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : X0_Pin X1_Pin X2_Pin RS_Pin
                           RW_Pin E_Pin X3_Pin */
  GPIO_InitStruct.Pin = X0_Pin|X1_Pin|X2_Pin|RS_Pin
                          |RW_Pin|E_Pin|X3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : Y0_Pin */
  GPIO_InitStruct.Pin = Y0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(Y0_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : Y1_Pin Y2_Pin Y3_Pin */
  GPIO_InitStruct.Pin = Y1_Pin|Y2_Pin|Y3_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

/* USER CODE BEGIN MX_GPIO_Init_2 */
/* USER CODE END MX_GPIO_Init_2 */
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
