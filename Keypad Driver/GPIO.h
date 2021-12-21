/*
 * GPIO.h
 *
 * Created: 12/7/2021 4:35:16 PM
 *  Author: LEGION
 */ 


#ifndef GPIO_H_
#define GPIO_H_

typedef struct
{
	unsigned char PortDirection;
	unsigned char UsePullUp;
}	GPIOConfigType;

void GPIO_Init(GPIOConfigType* cfgparam, unsigned char port_x, unsigned char mask);
void GPIO_Writepin(unsigned char port_x, unsigned char pin_no, unsigned char data);
unsigned char GPIO_Readpin(unsigned char port_x, unsigned char pin_no);
unsigned char btn_getstate(void);



#endif /* GPIO_H_ */