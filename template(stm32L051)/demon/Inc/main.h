/**
  ******************************************************************************
  * File Name          : main.h
  * Description        : This file contains the common defines of the application
  ******************************************************************************
  *
  * COPYRIGHT(c) 2017 STMicroelectronics
  *
  * Redistribution and use in source and binary forms, with or without modification,
  * are permitted provided that the following conditions are met:
  *   1. Redistributions of source code must retain the above copyright notice,
  *      this list of conditions and the following disclaimer.
  *   2. Redistributions in binary form must reproduce the above copyright notice,
  *      this list of conditions and the following disclaimer in the documentation
  *      and/or other materials provided with the distribution.
  *   3. Neither the name of STMicroelectronics nor the names of its contributors
  *      may be used to endorse or promote products derived from this software
  *      without specific prior written permission.
  *
  * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H
  /* Includes ------------------------------------------------------------------*/

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private define ------------------------------------------------------------*/

#define TamperSwitch_Pin GPIO_PIN_13
#define TamperSwitch_GPIO_Port GPIOC
#define BatteryVoltageControl_Pin GPIO_PIN_0
#define BatteryVoltageControl_GPIO_Port GPIOC
#define BatteryVoltage_Pin GPIO_PIN_1
#define BatteryVoltage_GPIO_Port GPIOC
#define BEEP_Pin GPIO_PIN_2
#define BEEP_GPIO_Port GPIOC
#define RestoreFactorySettings_Pin GPIO_PIN_3
#define RestoreFactorySettings_GPIO_Port GPIOC
#define PCF8563INT_Pin GPIO_PIN_0
#define PCF8563INT_GPIO_Port GPIOA
#define RC523_IRQ_Pin GPIO_PIN_1
#define RC523_IRQ_GPIO_Port GPIOA
#define HC595ShiftClock_Magnet_Pin GPIO_PIN_2
#define HC595ShiftClock_Magnet_GPIO_Port GPIOA
#define HC595LatchClock_Pin GPIO_PIN_3
#define HC595LatchClock_GPIO_Port GPIOA
#define Si4438_nSEL_Pin GPIO_PIN_4
#define Si4438_nSEL_GPIO_Port GPIOA
#define Si4438_SCLK_Pin GPIO_PIN_5
#define Si4438_SCLK_GPIO_Port GPIOA
#define Si4438_SDO_Pin GPIO_PIN_6
#define Si4438_SDO_GPIO_Port GPIOA
#define Si4438_SDI_Pin GPIO_PIN_7
#define Si4438_SDI_GPIO_Port GPIOA
#define Si4438_nIRQ_Pin GPIO_PIN_4
#define Si4438_nIRQ_GPIO_Port GPIOC
#define Si4438_SDN_Pin GPIO_PIN_5
#define Si4438_SDN_GPIO_Port GPIOC
#define Si4438SendStateP0_Pin GPIO_PIN_0
#define Si4438SendStateP0_GPIO_Port GPIOB
#define Si4438RecvStateP1_Pin GPIO_PIN_1
#define Si4438RecvStateP1_GPIO_Port GPIOB
#define LockCodeBit2_Pin GPIO_PIN_12
#define LockCodeBit2_GPIO_Port GPIOB
#define LockCodeBit1_Pin GPIO_PIN_13
#define LockCodeBit1_GPIO_Port GPIOB
#define GateLockStateCheck2_Pin GPIO_PIN_14
#define GateLockStateCheck2_GPIO_Port GPIOB
#define GateLock2_Pin GPIO_PIN_15
#define GateLock2_GPIO_Port GPIOB
#define GateLockStateCheck1_Pin GPIO_PIN_6
#define GateLockStateCheck1_GPIO_Port GPIOC
#define GateLock1_Pin GPIO_PIN_7
#define GateLock1_GPIO_Port GPIOC
#define HC595SerialDataInput_Pin GPIO_PIN_8
#define HC595SerialDataInput_GPIO_Port GPIOC
#define OpenTheDoor_Pin GPIO_PIN_9
#define OpenTheDoor_GPIO_Port GPIOC
#define KeyValue_Pin GPIO_PIN_8
#define KeyValue_GPIO_Port GPIOA
#define HbridgeDrive__Pin GPIO_PIN_11
#define HbridgeDrive__GPIO_Port GPIOA
#define HbridgeDrive_A12_Pin GPIO_PIN_12
#define HbridgeDrive_A12_GPIO_Port GPIOA
#define GateMagnet_Pin GPIO_PIN_15
#define GateMagnet_GPIO_Port GPIOA
#define AreaCodeBit7_Pin GPIO_PIN_10
#define AreaCodeBit7_GPIO_Port GPIOC
#define AreaCodeBit6_Pin GPIO_PIN_11
#define AreaCodeBit6_GPIO_Port GPIOC
#define AreaCodeBit5_Pin GPIO_PIN_12
#define AreaCodeBit5_GPIO_Port GPIOC
#define AreaCodeBit4_Pin GPIO_PIN_2
#define AreaCodeBit4_GPIO_Port GPIOD
#define AreaCodeBit3_Pin GPIO_PIN_3
#define AreaCodeBit3_GPIO_Port GPIOB
#define AreaCodeBit2_Pin GPIO_PIN_4
#define AreaCodeBit2_GPIO_Port GPIOB
#define AreaCodeBit1_Pin GPIO_PIN_5
#define AreaCodeBit1_GPIO_Port GPIOB
#define LockCodeBit4_Pin GPIO_PIN_8
#define LockCodeBit4_GPIO_Port GPIOB
#define LockCodeBit3_Pin GPIO_PIN_9
#define LockCodeBit3_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

/**
  * @}
  */ 

/**
  * @}
*/ 

#endif /* __MAIN_H */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
