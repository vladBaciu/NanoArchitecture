/*
 * NanoArchitecture.c
 *
 * Created: 7/14/2019 12:55:11 PM
 * Author : baciu
 */ 
#define F_CPU (16000000U)
#include <avr/io.h>
#include <util/delay.h>
#include "Port.h"

int main(void)
{
DDRD |= 0xFF;// setting the pin PD3 as output
Port_Init(&Port_gkt_Config);
for(;;)

{

	PORTB |= 0xFF;//setting pin high

	_delay_ms(1000);//function name will differ for //atmel studio

	PORTB ^= 0xFF;//setting pin high

	
_delay_ms(1000);//function name will differ for //atmel studio

}
}

