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
#include "Uart.h"


int main(void)
{
	FILE Uart_t_Output = FDEV_SETUP_STREAM(Uart_gv_TransmitString_CH_0, NULL, _FDEV_SETUP_WRITE);
	stdout = &Uart_t_Output;

	Port_Init(&Port_gkt_Config);
	Uart_gv_Init(&Uart_gkt_Cfg);
    Dio_WritePort(DIO_PORTB,0xFF);
	Dio_WritePort(DIO_PORTD,0xFF);
 uint8 uc_RxCommand;
	for(;;)

	{

		Uart_gv_Receive(UART_RX_D_0,&uc_RxCommand);
		printf("%d",uc_RxCommand);
		switch(uc_RxCommand)
		{ 
			//releu 1
			case 0x31:
				Dio_WriteChannel(DIO_PINB_0, STD_LOW);
				_delay_ms(1000);
			break;
			//releu1
			case 0x32:
				Dio_WriteChannel(DIO_PINB_0, STD_HIGH);
				_delay_ms(1000);
			break;
			//releu2
			case 0x33:
				Dio_WriteChannel(DIO_PINB_1, STD_LOW);
				_delay_ms(1000);
			break;
			//releu2
			case 0x34:
				Dio_WriteChannel(DIO_PINB_1, STD_HIGH);
				_delay_ms(1000);
			break;
			//releu3
			case 0x35:
				Dio_WriteChannel(DIO_PIND_6, STD_LOW);
				_delay_ms(1000);
			break;
			case 0x36:
				Dio_WriteChannel(DIO_PIND_6, STD_HIGH);
				_delay_ms(1000);
			break;
			//releu4
			case 0x37:
				Dio_WriteChannel(DIO_PIND_7, STD_LOW);
				_delay_ms(1000);
			break;
			case 0x38: 
				Dio_WriteChannel(DIO_PIND_7, STD_HIGH);
				_delay_ms(1000);
			break;
			default:
				Dio_WritePort(DIO_PORTD,~0x00);
				Dio_WritePort(DIO_PORTB,~0x00);
			break;
			
		}
		
		
	
	}
}

