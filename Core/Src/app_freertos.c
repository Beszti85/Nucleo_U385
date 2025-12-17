/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : app_freertos.c
  * Description        : FreeRTOS applicative file
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2025 STMicroelectronics.
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
#include "app_freertos.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
typedef StaticTask_t osStaticThreadDef_t;
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for Task1ms */
osThreadId_t Task1msHandle;
uint32_t Task1msBuffer[ 128 ];
osStaticThreadDef_t Task1msControlBlock;
const osThreadAttr_t Task1ms_attributes = {
  .name = "Task1ms",
  .stack_mem = &Task1msBuffer[0],
  .stack_size = sizeof(Task1msBuffer),
  .cb_mem = &Task1msControlBlock,
  .cb_size = sizeof(Task1msControlBlock),
  .priority = (osPriority_t) osPriorityNormal,
};
/* Definitions for TaskComm */
osThreadId_t TaskCommHandle;
uint32_t TaskCommBuffer[ 128 ];
osStaticThreadDef_t TaskCommControlBlock;
const osThreadAttr_t TaskComm_attributes = {
  .name = "TaskComm",
  .stack_mem = &TaskCommBuffer[0],
  .stack_size = sizeof(TaskCommBuffer),
  .cb_mem = &TaskCommControlBlock,
  .cb_size = sizeof(TaskCommControlBlock),
  .priority = (osPriority_t) osPriorityBelowNormal,
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN RTOS_MUTEX */
  /* add mutexes, ... */
  /* USER CODE END RTOS_MUTEX */

  /* USER CODE BEGIN RTOS_SEMAPHORES */
  /* add semaphores, ... */
  /* USER CODE END RTOS_SEMAPHORES */

  /* USER CODE BEGIN RTOS_TIMERS */
  /* start timers, add new ones, ... */
  /* USER CODE END RTOS_TIMERS */

  /* USER CODE BEGIN RTOS_QUEUES */
  /* add queues, ... */
  /* USER CODE END RTOS_QUEUES */
  /* creation of Task1ms */
  Task1msHandle = osThreadNew(StartTask1ms, NULL, &Task1ms_attributes);

  /* creation of TaskComm */
  TaskCommHandle = osThreadNew(StartTask02, NULL, &TaskComm_attributes);

  /* USER CODE BEGIN RTOS_THREADS */
  /* add threads, ... */
  /* USER CODE END RTOS_THREADS */

  /* USER CODE BEGIN RTOS_EVENTS */
  /* add events, ... */
  /* USER CODE END RTOS_EVENTS */

}
/* USER CODE BEGIN Header_StartTask1ms */
/**
* @brief Function implementing the Task1ms thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask1ms */
void StartTask1ms(void *argument)
{
  /* USER CODE BEGIN Task1ms */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END Task1ms */
}

/* USER CODE BEGIN Header_StartTask02 */
/**
* @brief Function implementing the TaskComm thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_StartTask02 */
void StartTask02(void *argument)
{
  /* USER CODE BEGIN TaskComm */
  /* Infinite loop */
  for(;;)
  {
    osDelay(1);
  }
  /* USER CODE END TaskComm */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

/* USER CODE END Application */

