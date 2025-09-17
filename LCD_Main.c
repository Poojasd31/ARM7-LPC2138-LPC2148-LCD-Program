#include<LPC21XX.h>
#include "LCD_4bit.h"

// Delay Function
void delay(int t)
{
	int i,j; 
	for(i=0;i<t;i++)
	{
		for(j=0;j<60000;j++)
		{
		}
	}
}


void main()
{

	LCD_Initialize();//Initialization Of LCD
	LCD_CMD(0X80); //First Row of LCD
	LCD_String("Pune");
	LCD_CMD(0XC0);
	LCD_String("Welcome");
	
	while(1)
	{
		
		
	}
	
}





