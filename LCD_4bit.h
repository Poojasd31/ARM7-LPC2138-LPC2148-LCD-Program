
#include<LPC21XX.h>

//Control Pins
#define RS 17
#define RW 18
#define EN 19

//Data Pins
#define D4 20
#define D5 21
#define D6 22
#define D7 23

//Forward Declarations
void LCD_Initialize();
void LCD_CMD(char);
void LCD_Data(char);
void LCD_String(char *);

