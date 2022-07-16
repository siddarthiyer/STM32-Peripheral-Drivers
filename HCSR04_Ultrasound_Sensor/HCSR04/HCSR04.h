/*
 * HCSR04.h
 *
 *  Created on: Jul 16, 2022
 *      Author: sidiyer27
 */

#ifndef HCSR04_H_
#define HCSR04_H_

#include "main.h"
#include "GPIO.h"

void HCSR04_Init();
float HCSR04_Get_Distance_Meter();
float HCSR04_Get_Distance_cm();
bool HCSRO4_Threshold(float threshold);

__STATIC_INLINE void Delay_Config(void)
{

	SysTick->CTRL = 0;
	SysTick->LOAD = 0x00FFFFFF;
	SysTick->VAL = 0;
	SysTick->CTRL |= 5;
}
__STATIC_INLINE void Delay_us(float us)
{

	SysTick->LOAD = (SystemCoreClock / 1000000) * us;
	SysTick->VAL = 0;
	while((SysTick->CTRL & 0x00010000) == 0);
}


#endif /* HCSR04_H_ */





