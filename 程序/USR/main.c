#include "pbdata.h"

void RCC_Configuration(void);
void GPIO_Configuration(void);
void TIM3_Configuration(void);
void NVIC_Configuration(void);

int main(void)
{
			RCC_Configuration(); 
			GPIO_Configuration();
			TIM3_Configuration();
			NVIC_Configuration();
			while(1)
				{
				
			
				
				}
   
	
}

void RCC_Configuration(void)
{
    SystemInit();
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);

}

void GPIO_Configuration(void)
{
    GPIO_InitTypeDef GPIO_InitStructure;	
	//LED
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
	
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_6;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_AF_PP;
	GPIO_Init(GPIOD,&GPIO_InitStructure);
		
	//KEY
GPIO_InitStructure.GPIO_Pin=GPIO_Pin_5;
GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IPU;//???????
GPIO_Init(GPIOC,&GPIO_InitStructure);
}
void TIM3_Configuration(void) //TIM3 ?????????
{
TIM_TimeBaseInitTypeDef TIM_TimeBaseStruct;
TIM_ClearITPendingBit(TIM3,TIM_IT_Update);//?????????
TIM_TimeBaseStruct.TIM_Period=2000;//??
TIM_TimeBaseStruct.TIM_Prescaler=35999;//???
TIM_TimeBaseStruct.TIM_ClockDivision=0;
TIM_TimeBaseStruct.TIM_CounterMode=TIM_CounterMode_Up;//??
TIM_TimeBaseInit(TIM3,&TIM_TimeBaseStruct);
TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
TIM_Cmd(TIM3,ENABLE); //???????
}
void NVIC_Configuration(void)//设置外部中断优先级
{
NVIC_InitTypeDef NVIC_InitStructure;
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);// ???????
NVIC_InitStructure.NVIC_IRQChannel =  TIM3_IRQn;//????? 9-5 ??
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1; //??????
NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
NVIC_Init(&NVIC_InitStructure);
}
