/*
 * GPIO.c
 *
 * Created: 12/7/2021 4:36:14 PM
 *  Author: LEGION
 */ 
#include <avr/io.h>
#include "GPIO.h"

void GPIO_Init(GPIOConfigType* cfgparam, unsigned char port_x, unsigned char mask)
{
	if(cfgparam->UsePullUp == 1)
	{
		SFIOR |= (1<<PUD);
	}
	else
	{
		SFIOR &= (0<<PUD);
	}
	
	switch(port_x)
	{
		case 'A':
		if(cfgparam->PortDirection == 1)
		{
			DDRA |= (1<<mask);
		}
		else
		{
			DDRA &= (0<<mask);
		}
		
		break;
		
		case 'B':
		if(cfgparam->PortDirection == 1)
		{
			DDRB |= (1<<mask);
		}
		else
		{
			DDRB &= (0<<mask);
		}
		break;
		
		case 'C':
		if(cfgparam->PortDirection == 1)
		{
			DDRC |= (1<<mask);
		}
		else
		{
			DDRC &= (0<<mask);
		}
		break;
		
		case 'D':
		if(cfgparam->PortDirection == 1)
		{
			DDRD |= (1<<mask);
		}
		else
		{
			DDRD &= (0<<mask);
		}
		break;
	}
}
void GPIO_Writepin(unsigned char port_x, unsigned char pin_no, unsigned char data)
{
	switch(port_x)
	{
		case 'A':
		if(data == 1)
		{
			PORTA |= (1 << pin_no);
		}
		else
		{
			PORTA &= (0 << pin_no);
		}
		break;
		
		case 'B':
		if(data == 1)
		{
			PORTB |= (1 << pin_no);
		}
		else
		{
			PORTB &= (0 << pin_no);
		}
		break;
		
		case 'C':
		if(data == 1)
		{
			PORTC |= (1 << pin_no);
		}
		else
		{
			PORTC &= (0 << pin_no);
		}
		break;
		
		case 'D':
		if(data == 1)
		{
			PORTD |= (1 << pin_no);
		}
		else
		{
			PORTD &= (0 << pin_no);
		}
		break;
	}
	
}
unsigned char GPIO_Readpin(unsigned char port_x, unsigned char pin_no)
{
	switch(port_x)
	{
		case 'A':
		if(PINA & (1<<pin_no))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
		
		case 'B':
		if(PINB & (1<<pin_no))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
		
		case 'C':
		if(PINC & (1<<pin_no))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
		
		case 'D':
		if(PIND & (1<<pin_no))
		{
			return 1;
		}
		else
		{
			return 0;
		}
		break;
	}
}