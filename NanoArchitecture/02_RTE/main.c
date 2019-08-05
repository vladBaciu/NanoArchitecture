/*
 * NanoArchitecture.c
 *
 * Created: 7/14/2019 12:55:11 PM
 * Author : baciu
 * AVR_Pocket command: -c usbtiny -p m328p -v -v -v -U flash:w:$(TargetDir)$(TargetName).hex:i
 */ 
#define F_CPU (16000000U)
#include <avr/io.h>
#include <util/delay.h>
#include "Port.h"
#include "Dio.h"
#include "Adc.h"

int main(void)
{
DDRD |= 0xFF;// setting the pin PD3 as output
Port_Init(&Port_gkt_Config);
for(;;)

{

	
Dio_WritePort(DIO_PORTB,0xFF);
	_delay_ms(1000);//function name will differ for //atmel studio

Dio_WritePort(DIO_PORTB,0x00);
_delay_ms(1000);//function name will differ for //atmel studio

}
}

