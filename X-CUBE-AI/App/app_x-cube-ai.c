
#ifdef __cplusplus
 extern "C" {
#endif
/**
  ******************************************************************************
  * @file           : app_x-cube-ai.c
  * @brief          : AI program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "app_x-cube-ai.h"
#include "main.h"
//#include "constants_ai.h"
#include "ai_datatypes_defines.h"

/* USER CODE BEGIN includes */
#include "stm32746g_discovery_ts.h"
#include "stm32746g_discovery_lcd.h"
#include <stdbool.h>
#include "dwt_utility.h"
#include "img_preprocess.h"

#define PATCH_SIZE 28

#define PEN_POINT_SIZE 7
#define TOUCH_TIMEOUT 700

#define PATCH_SIZE_X 58
#define PATCH_SIZE_Y 32

// static uint32_t g_patch8888_5832[PATCH_SIZE_X*PATCH_SIZE_Y];
// static uint32_t g_patch8888_2828[28*28];

 static ai_float in_data[AI_NETWORK_IN_1_SIZE];
 static ai_float out_data[AI_NETWORK_OUT_1_SIZE]= {0};
 extern UART_HandleTypeDef huart6;
 extern UART_HandleTypeDef huart1;
 extern uint8_t uRx_Data[];
 extern uint8_t screenMode;
 extern bool data_ready;
/* USER CODE END includes */
/* USER CODE BEGIN initandrun */
#include <stdlib.h>

/* Global handle to reference the instance of the NN */
static ai_handle network = AI_HANDLE_NULL;
static ai_buffer ai_input[AI_NETWORK_IN_NUM] = AI_NETWORK_IN ;
static ai_buffer ai_output[AI_NETWORK_OUT_NUM] = AI_NETWORK_OUT ;

/*
 * Init function to create and initialize a NN.
 */
int aiInit(const ai_u8* activations)
{
    ai_error err;

    /* 1 - Specific AI data structure to provide the references of the
     * activation/working memory chunk and the weights/bias parameters */
    const ai_network_params params = {
            AI_NETWORK_DATA_WEIGHTS(ai_network_data_weights_get()),
            AI_NETWORK_DATA_ACTIVATIONS(activations)
    };

    /* 2 - Create an instance of the NN */
    err = ai_network_create(&network, AI_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE) {
	    return -1;
    }

    /* 3 - Initialize the NN - Ready to be used */
    if (!ai_network_init(network, &params)) {
        err = ai_network_get_error(network);
        ai_network_destroy(network);
        network = AI_HANDLE_NULL;
	    return -2;
    }

    return 0;
}

/*
 * Run function to execute an inference.
 */
int aiRun(const void *in_data, void *out_data)
{
    ai_i32 nbatch;
    ai_error err;

    /* Parameters checking */
    if (!in_data || !out_data || !network)
        return -1;

    /* Initialize input/output buffer handlers */
    ai_input[0].n_batches = 1;
    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].n_batches = 1;
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    /* 2 - Perform the inference */
    nbatch = ai_network_run(network, &ai_input[0], &ai_output[0]);
    if (nbatch != 1) {
        err = ai_network_get_error(network);
        // ...
        return err.code;
    }

    return 0;
}
/* USER CODE END initandrun */

/*************************************************************************
  *
  */
void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 0 */
    /* Activation/working buffer is allocated as a static memory chunk
     * (bss section) */
    AI_ALIGNED(4)
    static ai_u8 activations[AI_NETWORK_DATA_ACTIVATIONS_SIZE];

    aiInit(activations);
    /* USER CODE END 0 */
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 1 */
//	static TS_StateTypeDef ts_state;
//	    static uint32_t touch_time;
	    static uint32_t t_cycle_start, t_cycle_inference_duration;
	    static struct dwtTime t_ms_inference_duration;
	    static float max_probability;
	    static uint8_t max_index;
	    static char prediction;
	    static char msg[30];

	    /* Get status and positions of the touch screen */
//		if( BSP_TS_GetState(&ts_state) == TS_OK )
//		{
//		  /* Trigger event*/
	    	char s0[100];
//			if(HAL_UART_Receive(&huart6, uRx_Data, 5*20+1, 1000) == HAL_OK)
//			{
////				printf( &uRx_Data);
//
//				data_ready = true;
////				s0 = "recieved\n";
//				HAL_UART_Transmit(&huart1, "recieved\n\r", 10, 0xFFFF);
//			}
//		  /*Draw display*/
//		  for(int i=0;i<ts_state.touchDetected;i++)
//		  {
//		    touch_time = HAL_GetTick();
//		    BSP_LCD_FillCircle(ts_state.touchX[i],ts_state.touchY[i],PEN_POINT_SIZE);
//		  }

		  /* Major block of drawing mini patch and running AI related code */
		  if( data_ready )// && (HAL_GetTick() - touch_time) > TOUCH_TIMEOUT)
		  {
			  BSP_LCD_Clear(LCD_COLOR_BLACK);
			/* retrieve downsampled image 58*32 from display memory (480*272) in SDRAM */
		    int ii = 0;

//		    for(uint16_t y=16;y<BSP_LCD_GetYSize();y+=8)
//		    {
//		      for(uint16_t x=16;x<BSP_LCD_GetXSize();x+=8)
//		      {
//		        g_patch8888_5832[ii++]= BSP_LCD_ReadPixel(x,y);
//		      }
//		    }

		    if(screenMode>0.5){
		    	BSP_LCD_SetFont(&Font24);
				sprintf(msg,"I = ");
				BSP_LCD_DisplayStringAt(38,4,(uint8_t*)msg,LEFT_MODE);
				BSP_LCD_SetFont(&Font16);
		    }
		    char buffer[16];
		    for(uint16_t x=0;x<5*20;x+=5)
		    {
		    	int s1 =  (uRx_Data[x]-48)*1000 + (uRx_Data[x+1]-48)*100 + (uRx_Data[x+2]-48)*10 + (uRx_Data[x+3]-48)*1;
		    	in_data[ii] = 0.00471698*s1;
		    	HAL_UART_Transmit(&huart1, (uint8_t*)buffer, sprintf(buffer, "%i %i\n\r", s1,ii), 500);
		    	ii++;
		    	if(screenMode>0.5){
		    		sprintf(msg," %d", s1);
					BSP_LCD_DisplayStringAt(98,8+(95-x)*3,(uint8_t*)msg,LEFT_MODE);
				}
		    }
//
//		    /* Resize from 58*32 to 28*28 */
//		    ImageResize((uint8_t*)g_patch8888_5832, 58, 32, 4, 0, 0, 58, 32, (uint8_t*)g_patch8888_2828, 28, 28);

//	        BSP_LCD_Clear(LCD_COLOR_BLACK);

	        /* Draw 28*28 and prepare input array of AI model: in_data */
	        ii=0;
//	        for(uint16_t y=0;y<PATCH_SIZE;y+=1)
//	        {
//	          for(uint16_t x=0;x<PATCH_SIZE;x+=1)
//	          {
//	        	in_data[ii] = (g_patch8888_2828[ii] > 0xFF000000)?1.0F:0.0F;
//	            BSP_LCD_DrawPixel(x,y,g_patch8888_2828[ii++]);
//	          }
//	        }

	        /* DWT reset*/
	        dwtReset();

	        /* inference duration measurement */
	        t_cycle_start = dwtGetCycles();

	        /* run NN*/
	        aiRun(in_data, out_data);

	        /* inference duration measurement */
	        t_cycle_inference_duration = dwtGetCycles() - t_cycle_start;

	        dwtCyclesToTime(t_cycle_inference_duration, &t_ms_inference_duration);

	        /* show results*/
	        max_probability = 0;
	        max_index = -1;
	        for(ii=0;ii<AI_NETWORK_OUT_1_SIZE;ii++)
	        {
	          if( out_data[ii] > max_probability ) { max_probability = out_data[ii]; max_index = ii; }
	        }
	        if(screenMode<0.5){
				BSP_LCD_SetFont(&Font24);
				if(max_index >= 0 && max_probability > 0.5F)
				{
				  prediction = (max_index <10) ? max_index+48 : max_index+55;
//				  const char status[3][15];
//				  strcpy(status[0] , "Unplug");
//				  strcpy(status[1] , "Heat Preserve");
//				  strcpy(status[2] , "Cooking");
				  if(prediction=='0') sprintf(msg,"Mode = 0 (Unplug)");
				  else if(prediction=='1') sprintf(msg,"Mode = 1 (Heat Preserve)");
				  else if(prediction=='2') sprintf(msg,"Mode = 2 (Cooking)");
				  else sprintf(msg,"Mode = %c",prediction);
				  BSP_LCD_DisplayStringAt(38,4,(uint8_t*)msg,LEFT_MODE);
				  BSP_LCD_SetFont(&Font16);
				  sprintf(msg,"(%d%% %dms)",(int)(max_probability*100),t_ms_inference_duration.ms);
				  BSP_LCD_DisplayStringAt(158,30,(uint8_t*)msg,LEFT_MODE);
				}
				else
				{
				  BSP_LCD_DisplayStringAt(38,4,(uint8_t*)"= ?",LEFT_MODE);
				}
	        }
	        HAL_UART_Transmit(&huart6, (uint8_t *)&max_index, 1, 0xFFFF);
	        data_ready = false;
	      } // end of if( data_ready && (HAL_GetTick() - touch_time) > TOUCH_TIMEOUT)
//	    } // end of if( BSP_TS_GetState(&ts_state) == TS_OK )
    /* USER CODE END 1 */
}
#ifdef __cplusplus
}
#endif
