/*
 * main.c
 *
 * Created: 12/10/2021 12:02:07 AM
 *  Author: LEGION
 */ 

#include <xc.h>
#include "GPIO.h"
#include "keypad.h"
#include <util/delay.h>

int main(void)
{
	unsigned char data;
	Keypad_4_3_Init('B', 0, 1, 2, 3, 4, 5, 6);
	
	GPIOConfigType led;
	led.PortDirection = 1;
	led.UsePullUp = 0;
	GPIO_Init(&led, 'D', 7);
    while(1)
    {
        //TODO:: Please write your application code 
		data = Keypad_4_3_read('B', 0, 1, 2, 3, 4, 5, 6);
		
		if (data == '2')
		{
			GPIO_Writepin('D', 7, 1);
		}
		else
		{
			GPIO_Writepin('D', 7, 0);
		}
    }
}