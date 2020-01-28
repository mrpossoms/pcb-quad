/*
 * GccApplication1.c
 *
 * Created: 1/23/2020 10:04:20 PM
 * Author : Kirk
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <math.h>
#include "avr/iom256rfr2.h"


void init_timers()
{
	//TCCR1A = 0b00000101;
	TCCR1A |= (1 << COM1A1);
	TCCR1A |= (1 << COM1B1);
	TCCR1A |= (1 << COM1C1);
	TCCR1A |= (1 << WGM10);
	TCCR1B |= (1 << WGM12);
	TCCR1B |= (1 << CS11);
	
	TCCR2A |= (1 << COM2A1);
	TCCR2A |= (1 << WGM20);
	TCCR2A |= (1 << WGM21);
	TCCR2B |= (1 << CS21);
	
	OCR1C = 0xff;
}

int main(void)
{
	int delay = 0;
	float t = 0;
	DDRB = 0xff;
	
	init_timers();
	
    /* Replace with your application code */
    while (1) 
    {
		
		OCR1A = (sin(t + M_PI_4) + 1.0) * 128;		
		OCR1B = (sin(t + M_PI_2) + 1.0) * 128;
		OCR1C = (sin(t + M_PI_2 + M_PI_4) + 1.0) * 128;
		OCR2A = (sin(t + M_PI) + 1.0) * 128;
		t += 0.1;
		_delay_ms(10);
	}
}
