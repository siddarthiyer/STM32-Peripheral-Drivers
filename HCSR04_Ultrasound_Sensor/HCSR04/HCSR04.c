/*
 * HCSR04.c
 *
 *  Created on: Jul 16, 2022
 *      Author: sidiyer27
 */

#include "HCSR04.h"

void HCSR04_Init(){

	RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	TIM1->SR = 0;
	TIM1->PSC = 71;
	TIM1-> ARR = 0xFFFFFFFF;
	TIM1->CR1 |= TIM_CR1_URS;
	GPIO_Pin_Init(GPIOA, 8, FLOATING_INPUT); //Echo(TIM1 Channel 1)
	GPIO_Pin_Init(GPIOA, 9, GEN_PUSH_PULL_OUTPUT); //Trigger
	Delay_Config();
}

float HCSR04_Get_Distance_Meter(){
	float distance;
	int time;
	GPIO_WritePin(GPIOA, 9, GPIO_PIN_SET);
	Delay_us(10);
	GPIO_WritePin(GPIOA, 9, GPIO_PIN_RESET);
	TIM1->CR1 |= TIM_CR1_CEN;
	while(GPIO_ReadPin(GPIOA, 9) != GPIO_PIN_SET){} //Loop till Echo is High
	time = TIM1->CNT; //copy timer counter value
	TIM1->CR1 &= ~TIM_CR1_CEN; // Disable Timer
	distance = ((time * 0.000001 ) * SOUND_SPEED)/2;
	return distance;
}

float HCSR04_Get_Distance_cm(){
	return HCSRO4_Get_Distance_Meter()*100;
}

bool HCSRO4_Threshold(float threshold){
	if(HCSR04_Get_Distance_cm() >= threshold) return true;
	else return false;

}


