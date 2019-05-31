/*
 * IR_NEC.h
 *
 * Created: 12. 4. 2019 10:02:55
 *  Author: Vojta
 *
 * This project uses Timer/Counter and External interrupt to decode IR NEC protocol.
 *
 * Hardware support:
 * ATtiny85: 8-bit Timer/Counter0, INT0
 * ATtiny88: 8-bit Timer/Counter0, INT0
 * CPU clock is 8 MHz.
 *
 * Connect output pin of IR receiver to PB2/PD2 (pin 7/4).
 * Execute IR_init(uint16_t clearBufferTime) function to set registers, interrupts and clearBufferTime (after this time, durationBuffer will be cleared).
 * It is useful, when some parts of running program cause delay. The clearBufferTime should be set the same as the duration of the delay.
 * Then just check IR_available() function in loop.
 * If IR_available() returns true, IR signal has been checked succesfully and then IR data (address and command) are available.
 * Access to IR data is through IR_data structure named IR (IR.address for address, IR.command for command).
 * Make sure to execute sei() function to enable global interrupts.
 */ 


#ifndef IR_NEC_H_
#define IR_NEC_H_

#ifndef F_CPU
#define F_CPU 8000000UL
#endif

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sfr_defs.h>
#include <stdbool.h>

// Structure for address and command
typedef struct
{
	uint8_t address;
	uint8_t command;
} IR_data;

extern IR_data IR;

void IR_init(uint16_t clearBufferTime);
bool IR_available();

#endif /* IR_NEC_H_ */