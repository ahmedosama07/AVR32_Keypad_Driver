/*
 * keypad.c
 *
 * Created: 12/10/2021 12:08:08 AM
 *  Author: LEGION
 */ 
#include <avr/io.h>
#include "GPIO.h"
#include "keypad.h"
#include <util/delay.h>

static unsigned char key1 = 0;
static unsigned char key2 = 0;
void Keypad_4_3_Init(unsigned char port_x, unsigned char row_1_pin, unsigned char row_2_pin, unsigned char row_3_pin, unsigned char row_4_pin,
					 unsigned char col_1_pin, unsigned char col_2_pin, unsigned char col_3_pin)
{
	GPIOConfigType row;
	row.PortDirection = 1;
	row.UsePullUp = 0;
	
	GPIOConfigType col;
	col.PortDirection = 0;
	col.UsePullUp = 0;
	
	GPIO_Init(&row, port_x, row_1_pin);
	GPIO_Init(&row, port_x, row_2_pin);
	GPIO_Init(&row, port_x, row_3_pin);
	GPIO_Init(&row, port_x, row_4_pin);
	
	GPIO_Init(&col, port_x, col_1_pin);
	GPIO_Init(&col, port_x, col_2_pin);
	GPIO_Init(&col, port_x, col_3_pin);
}



unsigned char Keypad_4_3_read(unsigned char port_x, unsigned char row_1_pin, unsigned char row_2_pin, unsigned char row_3_pin, unsigned char row_4_pin,
							  unsigned char col_1_pin, unsigned char col_2_pin, unsigned char col_3_pin)
{
	unsigned char keypad_4_3[4][3] = {{'1', '2', '3'},
									  {'4', '5', '6'},
									  {'7', '8', '9'},
									  {'*', '0', '#'}};
	
	
	
	unsigned char rows_pins[4] = {row_1_pin, row_2_pin, row_3_pin, row_4_pin};
	unsigned char cols_pins[3] = {col_1_pin, col_2_pin, col_3_pin};
	
	unsigned char data = 0;
	unsigned char rows = 0;
	unsigned char cols = 0;
	
	
	
	for(rows = 0; rows < 4; rows++)
	{
		data = GPIO_Readpin(port_x, cols_pins[key2]);
		_delay_ms(10);
		if(data == 1)
		{
			return keypad_4_3[key1][key2];
		}
		
		GPIO_Writepin(port_x, rows_pins[rows], 1);
		
		
		for(cols = 0; cols < 3; cols++)
		{
			data = GPIO_Readpin(port_x, cols_pins[cols]);
			_delay_ms(10);
			if(data == 1)
			{
				key2 = cols;
				key1 = rows;
				return keypad_4_3[rows][cols];
			}
		}
		GPIO_Writepin(port_x, rows_pins[rows], 0);
		_delay_ms(10);
	}
}