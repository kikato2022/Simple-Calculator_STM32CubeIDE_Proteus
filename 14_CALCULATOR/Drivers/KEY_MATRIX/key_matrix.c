/*
 * key_matrix.c
 *
 *  Created on: Nov 8, 2024
 *      Author: Admin
 */
#include "key_matrix.h"

// 说明：行(x),列(Y)
/******************************************
X0_Y0 1		X0_Y1 2		X0_Y2 3		X0_Y3 A
X1_Y0 4		X1_Y1 5		X1_Y2 6		X1_Y3 B
X2_Y0 7		X2_Y1 8		X2_Y2 9		X2_Y3 C
X3_Y0 D		X3_Y1 0		X3_Y2 E		X3_Y3 F
******************************************/






int keyScan(void){
	int key;
	int dot_flag;
	int flag_fs;
	int mo_flag;
	//set X0-X4 to 0111
	X0_DOWN;
	X1_UP;
	X2_UP;
	X3_UP;
	if(Y0 == RESET){
		HAL_Delay(10);
		if(Y0 == RESET){
			key = 1;
			dot_flag = 0;
			while(Y0 == RESET);
			return key;
		}
	}else if(Y1 == RESET){
		HAL_Delay(10);
		if(Y1 == RESET){
			key = 2;
			dot_flag = 0;
			while(Y1 == RESET);
			return key;
		}
	}else if(Y2 == RESET){
		HAL_Delay(10);
		if(Y2 == RESET){
			key = 3;
			dot_flag = 0;
			while(Y2 == RESET);
			return key;
		}
	}else if(Y3 == RESET){
		HAL_Delay(10);
		if(Y3 == RESET){
			key = 10;
			dot_flag = 0;
			while(Y3 == RESET);
			return key;
		}
	}

	//set X0-X4 to 1011
	X0_UP;
	X1_DOWN;
	X2_UP;
	X3_UP;
	if(Y0 == RESET){
		HAL_Delay(10);
		if(Y0 == RESET){
			key = 4;
			dot_flag = 0;
			while(Y0 == RESET);
			return key;
		}
	}else if(Y1 == RESET){
		HAL_Delay(10);
		if(Y1 == RESET){
			key = 5;
			dot_flag = 0;
			while(Y1 == RESET);
			return key;
		}
	}else if(Y2 == RESET){
		HAL_Delay(10);
		if(Y2 == RESET){
			key = 6;
			dot_flag = 0;
			while(Y2 == RESET);
			return key;
		}
	}else if(Y3 == RESET){
		HAL_Delay(10);
		if(Y3 == RESET){
			key = 11;
			dot_flag = 0;
			while(Y3 == RESET);
			return key;
		}
	}

	//set X0-X4 to 1101
	X0_UP;
	X1_UP;
	X2_DOWN;
	X3_UP;
	if(Y0 == RESET){
		HAL_Delay(10);
		if(Y0 == RESET){
			key = 7;
			dot_flag = 0;
			while(Y0 == RESET);
			return key;
		}
	}else if(Y1 == RESET){
		HAL_Delay(10);
		if(Y1 == RESET){
			key = 8;
			dot_flag = 0;
			while(Y1 == RESET);
			return key;
		}
	}else if(Y2 == RESET){
		HAL_Delay(10);
		if(Y2 == RESET){
			key = 9;
			dot_flag = 0;
			while(Y2 == RESET);
			return key;
		}
	}else if(Y3 == RESET){
		HAL_Delay(10);
		if(Y3 == RESET){
			key = 12;
			dot_flag = 0;
			while(Y3 == RESET);
			return key;
		}
	}

	//set X0-X4 to 1110
	X0_UP;
	X1_UP;
	X2_UP;
	X3_DOWN;
	if(Y0 == RESET){
		HAL_Delay(10);
		if(Y0 == RESET){
			key = 13;
			dot_flag = 0;
			while(Y0 == RESET);
			return key;
		}
	}else if(Y1 == RESET){
		HAL_Delay(10);
		if(Y1 == RESET){
			key = 0;
			dot_flag = 0;
			while(Y1 == RESET);
			return key;
		}
	}else if(Y2 == RESET){
		HAL_Delay(10);
		if(Y2 == RESET){
			key = 14;
			dot_flag = 0;
			while(Y2 == RESET);
			return key;
		}
	}else if(Y3 == RESET){
		HAL_Delay(10);
		if(Y3 == RESET){
			key = 15;
			dot_flag = 0;
			while(Y3 == RESET);
			return key;
		}
	}


	return 99;
}

