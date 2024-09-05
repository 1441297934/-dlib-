#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "stm32f103xe.h"
/************************************************
 ALIENTEK ??STM32F103?????0-1
 Template????-????????-HAL???
 ????:www.openedv.com
 ????: http://eboard.taobao.com 
 ???????????:"????",????STM32???
 ?????????????  
 ??:???? @ALIENTEK
************************************************/


/***??:????????????3.3????***/

int main(void)
{
	GPIO_InitTypeDef GPIO_Initure;
     
    HAL_Init();                    	 			//???HAL?    
    Stm32_Clock_Init(RCC_PLL_MUL9);   			//????,72M

    __HAL_RCC_GPIOB_CLK_ENABLE();           	//??GPIOB??
	__HAL_RCC_GPIOE_CLK_ENABLE();           	//??GPIOE??
	
    GPIO_Initure.Pin=GPIO_PIN_5; 				//PB5
    GPIO_Initure.Mode=GPIO_MODE_OUTPUT_PP;  	//????
    GPIO_Initure.Pull=GPIO_PULLUP;          	//??
    GPIO_Initure.Speed=GPIO_SPEED_FREQ_HIGH;    //??
    HAL_GPIO_Init(GPIOB,&GPIO_Initure);

	GPIO_Initure.Pin=GPIO_PIN_5; 				//PE5
	HAL_GPIO_Init(GPIOE,&GPIO_Initure);
	uart_init(115200);					//³õÊ¼»¯´®¿Ú
	delay_init(72);
	while(1)
	{
		printf("hello\r\n");
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_SET);		//PB5?1 
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_SET);		//PE5?1  			
		delay_ms(1000);
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_5,GPIO_PIN_RESET);		//PB5?0
		HAL_GPIO_WritePin(GPIOE,GPIO_PIN_5,GPIO_PIN_RESET);
		delay_ms(1000);
	}
}