/*
 * Initialization.c
 * File have Functions definitions and Variabels Initialization
 *  Created on: Jan 30, 2024
 *      Author: abdalla
 */

#include "Initialization.h"

/** Numbers For 7-Segment **/
unsigned char MAX_FIRST_DIGIT = 10;

/** SECONDS NUMBERS**/
unsigned char SECONDS_FIRST_DIGIT      = ZERO;
unsigned char SECONDS_SECOND_DIGIT     = ZERO;
unsigned char MAX_SECONDS_SECOND_DIGIT = 6;

/** MINUTES NUMBERS**/
unsigned char MINUTES_FIRST_DIGIT      = ZERO;
unsigned char MINUTES_SECOND_DIGIT     = ZERO;
unsigned char MAX_MINUTES_SECOND_DIGIT = 6;

/** HOURS NUMBERS**/
unsigned char HOURS_FIRST_DIGIT        = ZERO;
unsigned char HOURS_SECOND_DIGIT       = ZERO;
unsigned char LAST_HOUR_IN_DAY         = 4;
unsigned char MAX_HOURS_SECOND_DIGIT   = 2;

/** PINS configuration function **/
void PINS_Init(void)
{
	DDRA |= MAKE_FIRST_6PINS_OUTPUT;
	PORTA &= CLEAR_FIRST_6PINS;

	DDRC |= MAKE_FIRST_4PINS_OUTPUT;
	PORTC &= CLEAR_FIRST_4PINS;
}

/** Timer1 enable and configuration function **/
void Timer1_CTC_Count_Second_Init(void)
{
	TCNT1 = TIMER_START_VALUE;		/* Set timer1 initial count to zero */

	OCR1A = TIMER_COMPARE_VALUE;    /* Set the Compare value to 977 (T-tick = 1024 micro sec) */

	SET_BIT(TIMSK,OCIE1A);          /* Enable Timer1 Compare A Interrupt */

	/* Configure timer control register TCCR1A
	 * 1. Disconnect OC1A and OC1B  COM1A1=0 COM1A0=0 COM1B0=0 COM1B1=0
	 * 2. FOC1A=1 FOC1B=0
	 * 3. CTC Mode WGM10=0 WGM11=0 (Mode Number 4)
	 */
	TCCR1A = (1<<FOC1A);

	/* Configure timer control register TCCR1B
	 * 1. CTC Mode WGM12=1 WGM13=0 (Mode Number 4)
	 * 2. Prescaler = F_CPU/1024 CS10=1 CS11=0 CS12=1
	 */
	TCCR1B = (1<<WGM12) | (1<<CS10) | (1<<CS12);
}

/** External INT0 enable and configuration function **/
void INT0_Init(void)
{
	CLEAR_BIT(DDRD,PD2);   /* Configure INT0/PD2 as input pin */
	SET_BIT(PORTD,PD2);    /* Activate Internal pull-up resistor */
	SET_BIT(MCUCR,ISC00);  /* Trigger INT0 with the Falling edge */
	CLEAR_BIT(MCUCR,ISC01);
	SET_BIT(GICR,INT0);    /* Enable external interrupt pin INT0 */
	SET_BIT(SREG,7);       /* Enable interrupts by setting I-bit */
}

/** External INT1 enable and configuration function **/
void INT1_Init(void)
{
	CLEAR_BIT(DDRD,PD3);  /* Configure INT1/PD3 as input pin */
	SET_BIT(MCUCR,ISC10); /* Trigger INT1 with the Rising edge */
	SET_BIT(MCUCR,ISC11);
	SET_BIT(GICR,INT1);   /* Enable external interrupt pin INT1 */
	SET_BIT(SREG,7);      /* Enable interrupts by setting I-bit */
}

/** External INT2 enable and configuration function **/
void INT2_Init(void)
{
	CLEAR_BIT(DDRB,PB2);    /* Configure INT2/PB2 as input pin */
	SET_BIT(PORTB,PB2);     /* Activate Internal pull-up resistor */
	CLEAR_BIT(MCUCSR,ISC2); /* Trigger INT2 with the Falling edge */
	SET_BIT(GICR,INT2);     /* Enable external interrupt pin INT2 */
	SET_BIT(SREG,7);        /* Enable interrupts by setting I-bit */
}


/** Function to handel Increasing one second on the stop watch **/
void Increase_One_Second (void)
{
	SECONDS_FIRST_DIGIT++;
	if (SECONDS_FIRST_DIGIT == MAX_FIRST_DIGIT)
	{
		SECONDS_FIRST_DIGIT = ZERO;
		SECONDS_SECOND_DIGIT++;
	}
	if (SECONDS_SECOND_DIGIT == MAX_SECONDS_SECOND_DIGIT)
	{
		SECONDS_SECOND_DIGIT = ZERO;
		MINUTES_FIRST_DIGIT++;
	}
	if (MINUTES_FIRST_DIGIT == MAX_FIRST_DIGIT)
	{
		MINUTES_FIRST_DIGIT = ZERO;
		MINUTES_SECOND_DIGIT++;
	}
	if (MINUTES_SECOND_DIGIT == MAX_MINUTES_SECOND_DIGIT)
	{
		MINUTES_SECOND_DIGIT = ZERO;
		HOURS_FIRST_DIGIT++;
	}
	if (HOURS_FIRST_DIGIT == MAX_FIRST_DIGIT)
	{
		HOURS_FIRST_DIGIT = ZERO;
		HOURS_SECOND_DIGIT++;
	}
	if ((HOURS_FIRST_DIGIT == LAST_HOUR_IN_DAY) && (HOURS_SECOND_DIGIT == MAX_HOURS_SECOND_DIGIT))
	{
		HOURS_SECOND_DIGIT = ZERO;
		HOURS_FIRST_DIGIT = ZERO;
	}
}

/** Function to handel Reseting stopwatch **/
void Reset_StopWatch (void)
{
	SECONDS_FIRST_DIGIT  = ZERO;
	SECONDS_SECOND_DIGIT = ZERO;
	MINUTES_FIRST_DIGIT  = ZERO;
	MINUTES_SECOND_DIGIT = ZERO;
	HOURS_FIRST_DIGIT    = ZERO;
	HOURS_SECOND_DIGIT   = ZERO;
}

/** Function to handel Pausing stopwatch **/
void Pause_StopWatch (void)
{
	/* Stop Timer1 Clock */
	CLEAR_BIT(TCCR1B,CS10);
	CLEAR_BIT(TCCR1B,CS11);
	CLEAR_BIT(TCCR1B,CS12);

}

/** Function to handel Resuming stopwatch **/
void Resume_StopWatch (void)
{
	/* Activate Timer1 Clock */
	SET_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS12);
}
