#include "LCD_4bit.h"

void LCD_Initialize()
{
	PINSEL2 = 0X00000000; //All pins are GPIO
	IODIR1 |=( (1<<RS) | (1<<RW) | (1<<EN) | (1<<D4) | (1<<D5) | (1<<D6) | (1<<D7)); // Pins are Output
	
	delay(50);
	LCD_CMD(0x02); /* Initialize lcd in 4-bit mode */
  LCD_CMD(0x28); /* 2 lines */ 
  LCD_CMD(0x0C); /* Display on cursor off */ 
  LCD_CMD(0x06); /* Auto increment cursor */ 
  LCD_CMD(0x01); /* Display clear */ 

}

void LCD_CMD(char CMD)
{
	IOPIN1 = ((IOPIN1 & 0xFF01FFFF) | ((CMD & 0XF0) << 16 ));  //Send Upper Nibble
	IOCLR1 = (1<<RS) | (1<<RW); //RS=0 Command Register and RW=0 Write Operation
		//Enable High to Low Pulse
	IOSET1 = (1<<EN);
	delay(5);
	IOCLR1 = (1<<EN);
	delay(5);
	//To send Lower Nibble
	IOPIN1 = ( (IOPIN1 & 0xFF01FFFF) | ((CMD & 0X0F) << 20)); 
	IOCLR1 |= (1<<RS) | (1<<RW); //RS=0 Command Register and RW=0 Write Operation
	//Enable High to Low Pulse
	IOSET1 = (1<<EN);
	delay(5);
	IOCLR1 = (1<<EN);
	delay(5);
}

void LCD_Data(char Data)
{
	IOPIN1 = ( (IOPIN1 & 0xFF01FFFF) | ((Data & 0XF0) << 16 ));  //Send Upper Nibble
	IOSET1 = (1<<RS); //RS =1 for Data Register
	IOCLR1 = (1<<RW); //RW = 1 for Write Operation
	//Enable High to Low Pulse
	IOSET1 = (1<<EN);
	delay(5);
	IOCLR1 = (1<<EN);
	delay(5);
	//To send Lower Nibble
	IOPIN1 = ( (IOPIN1 & 0xFF01FFFF) | ((Data & 0X0F) << 20 ));
	IOSET1 = (1<<RS); //RS =1 for Data Register
	IOCLR1 = (1<<RW); //RW = 1 for Write Operation
	//Enable High to Low Pulse
	IOSET1 = (1<<EN);
	delay(5);
	IOCLR1 = (1<<EN);
	delay(5);
}

//LCD String Function
void LCD_String(char *str)
{
	while(*str)
	LCD_Data(*str ++);
}

