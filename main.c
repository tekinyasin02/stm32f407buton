#include "stm32f4xx.h"                  // Device header


uint8_t buton_okunan ;
int sayac = 0;
void GPIO_Ayar (void)
{
GPIO_InitTypeDef led;
GPIO_InitTypeDef buton;
	
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); 
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE); 
	
	
	led.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	led.GPIO_Mode = GPIO_Mode_OUT;
  led.GPIO_Speed = GPIO_Speed_100MHz;
  led.GPIO_OType = GPIO_OType_PP;
  led.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &led);
	
	buton.GPIO_Pin  = GPIO_Pin_0;
  buton.GPIO_Mode = GPIO_Mode_IN;
  buton.GPIO_Speed = GPIO_Speed_100MHz;
  buton.GPIO_OType = GPIO_OType_PP;
  buton.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &buton);
	
}

int main ()
{
GPIO_Ayar();
	
	while(1)
	{
	
		buton_okunan = 	GPIO_ReadInputDataBit(GPIOA,GPIO_Pin_0);
	  if(buton_okunan == 1)
		 {
		 sayac++;
			int i = 0;
			while(i< 2000000)
			{
			i++;
			}
		 }
		if(sayac == 0)
		{
		GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		}
		else if (sayac == 1)
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_12);
		}
			else if (sayac == 2)
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_13);
		}
			else if (sayac == 3)
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_14);
		}
			else if (sayac == 4)
		{
		GPIO_SetBits(GPIOD,GPIO_Pin_15);
		}
		else if (sayac >= 5)
		{
		sayac =0 ;
				GPIO_ResetBits(GPIOD,GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15);
		}
	}

 }