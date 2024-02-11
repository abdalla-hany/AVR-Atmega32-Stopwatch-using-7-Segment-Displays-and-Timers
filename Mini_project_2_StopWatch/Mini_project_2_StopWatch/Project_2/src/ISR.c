/*
 * ISR.c
 * Interrupt Service Routine file
 *  Created on: Jan 30, 2024
 *      Author: abdalla
 */

#include "Initialization.h"

/** Timer Compare A Interrupt Service Routine **/
ISR(TIMER1_COMPA_vect)
{
	Increase_One_Second();
}

/** External INT0 Interrupt Service Routine **/
ISR(INT0_vect)
{
	Reset_StopWatch();
}

/** External INT1 Interrupt Service Routine **/
ISR(INT1_vect)
{
	Pause_StopWatch();
}

/** External INT2 Interrupt Service Routine **/
ISR(INT2_vect)
{
	Resume_StopWatch();
}
