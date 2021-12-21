/*
 * keypad.h
 *
 * Created: 12/10/2021 12:07:52 AM
 *  Author: LEGION
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

void Keypad_4_3_Init(unsigned char port_x, unsigned char row_1_pin, unsigned char row_2_pin, unsigned char row_3_pin, unsigned char row_4_pin, 
					 unsigned char col_1_pin, unsigned char col_2_pin, unsigned char col_3_pin);
					
unsigned char Keypad_4_3_read(unsigned char port_x, unsigned char row_1_pin, unsigned char row_2_pin, unsigned char row_3_pin, unsigned char row_4_pin,
							  unsigned char col_1_pin, unsigned char col_2_pin, unsigned char col_3_pin);

#endif /* KEYPAD_H_ */