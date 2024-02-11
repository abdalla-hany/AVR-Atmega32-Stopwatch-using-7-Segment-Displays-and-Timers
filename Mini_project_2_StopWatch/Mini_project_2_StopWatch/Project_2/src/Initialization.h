/*
 * Initialization.h
 * Header File have Functions Prototypes, Libraries and Macros
 *  Created on: Jan 30, 2024
 *      Author: abdalla
 */

#ifndef SRC_INITIALIZATION_H_
#define SRC_INITIALIZATION_H_

/*************** Used Libraries ***************/
#include <avr/io.h>        /* For Registers and Ports */
#include <avr/interrupt.h> /* For ISR Interrupts */
#include <util/delay.h>    /* For Delay Function */

/****************** COMMAN MACROS ******************/
#define SET_BIT(REG,BIT_NUM)(REG |= (1 << BIT_NUM))        /* Macro to make a specific Bit = 1 */
#define CLEAR_BIT(REG,BIT_NUM)(REG &= ~(1 << BIT_NUM))     /* Macro to make a specific Bit = 0 */
#define BIT_IS_SET(REG,BIT_NUM)(REG & (1 << BIT_NUM))      /* Macro to check if a specific Bit = 1 */
#define BIT_IS_CLEAR(REG,BIT_NUM)(!(REG & (1 << BIT_NUM))) /* Macro to check if a specific Bit = 0 */

#define TIMER_START_VALUE 0      /* Set timer1 initial count to zero */
#define TIMER_COMPARE_VALUE 977  /* Set the Compare value to 977 (T-tick = 1024 micro sec) */

/** PORTS CONFIGURATION **/
#define MAKE_FIRST_6PINS_OUTPUT 0x3F
#define CLEAR_FIRST_6PINS 0xC0
#define MAKE_FIRST_4PINS_OUTPUT 0x0F
#define CLEAR_FIRST_4PINS 0xF0

/** Numbers For 7-Segment **/
#define ZERO 0
#define DELAY _delay_us(2)										  /* Macro to Delay 2 micro sec */
#define ACTIVATE(PIN)(SET_BIT(PORTA,PIN))						  /* Macro to Activate certain 7-segment */
#define DEACTIVATE(PIN)(CLEAR_BIT(PORTA,PIN))                     /* Macro to Deactivate certain 7-segment */
#define DISPLAY(NUMBER)(PORTC = (PORTC & 0xF0) | (NUMBER & 0x0F)) /* Macro to Display Number on certain 7-segment */
extern unsigned char MAX_FIRST_DIGIT ;

/** SECONDS NUMBERS**/
extern unsigned char SECONDS_FIRST_DIGIT;
extern unsigned char SECONDS_SECOND_DIGIT;
extern unsigned char MAX_SECONDS_SECOND_DIGIT;

/** MINUTES NUMBERS**/
extern unsigned char MINUTES_FIRST_DIGIT;
extern unsigned char MINUTES_SECOND_DIGIT;
extern unsigned char MAX_MINUTES_SECOND_DIGIT;

/** HOURS NUMBERS**/
extern unsigned char HOURS_FIRST_DIGIT;
extern unsigned char HOURS_SECOND_DIGIT;
extern unsigned char LAST_HOUR_IN_DAY;
extern unsigned char MAX_HOURS_SECOND_DIGIT;

/** Initialization Functions Prototypes **/
void Timer1_CTC_Count_Second_Init(void); /* Timer1 enable and configuration function */
void PINS_Init(void);                    /* PINS configuration function */
void INT0_Init(void); 					 /* External INT0 enable and configuration function */
void INT1_Init(void); 					 /* External INT1 enable and configuration function */
void INT2_Init(void); 					 /* External INT2 enable and configuration function */
void Increase_One_Second (void);		 /* Function to handel Increasing one second on the stop watch */
void Reset_StopWatch (void);		     /* Function to handel Reseting stopwatch */
void Pause_StopWatch (void);			 /* Function to handel Pausing stopwatch */
void Resume_StopWatch (void);			 /* Function to handel Resuming stopwatch */

#endif /* SRC_INITIALIZATION_H_ */
