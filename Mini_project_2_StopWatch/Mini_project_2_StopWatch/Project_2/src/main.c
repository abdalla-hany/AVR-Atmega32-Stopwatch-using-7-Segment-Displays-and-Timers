/*
 * main.c
 * Main Function File
 *  Created on: Jan 30, 2024
 *      Author: abdalla
 */

#include "Initialization.h"

int main (void)
{
	Timer1_CTC_Count_Second_Init(); /* Timer1 enable and configuration function */
    PINS_Init();                    /* PINS configuration function */
	INT0_Init(); 					/* External INT0 enable and configuration function */
	INT1_Init(); 					/* External INT1 enable and configuration function */
	INT2_Init(); 					/* External INT2 enable and configuration function */

	/** Keep looping at all 7-segment and display time on each one synchronously **/
	while (1)
	{
		ACTIVATE(PA0);				  /* Activate the first 7-segment */
		DISPLAY(SECONDS_FIRST_DIGIT); /* Display Seconds first digit on the first 7-segment */
		DELAY;						  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA0);			  /* Deactivate this 7-segment */

		ACTIVATE(PA1); 				  /* Activate the second 7-segment */
		DISPLAY(SECONDS_SECOND_DIGIT);/* Display Seconds second digit on the first 7-segment */
		DELAY;  					  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA1); 			  /* Deactivate this 7-segment */

		ACTIVATE(PA2); 				  /* Activate the third 7-segment */
		DISPLAY(MINUTES_FIRST_DIGIT); /* Display Minutes first digit on the first 7-segment */
		DELAY; 						  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA2); 			  /* Deactivate this 7-segment */

		ACTIVATE(PA3); 				  /* Activate the fourth 7-segment */
		DISPLAY(MINUTES_SECOND_DIGIT);/* Display Minutes Sconde digit on the first 7-segment */
		DELAY; 						  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA3); 			  /* Deactivate this 7-segment */

		ACTIVATE(PA4); 				  /* Activate the fifth 7-segment */
		DISPLAY(HOURS_FIRST_DIGIT);   /* Display Hours first digit on the first 7-segment */
		DELAY; 						  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA4); 			  /* Deactivate this 7-segment */

		ACTIVATE(PA5); 				  /* Activate the sixth 7-segment */
		DISPLAY(HOURS_SECOND_DIGIT);  /* Display Hours second digit on the first 7-segment */
		DELAY; 						  /* Delay 2 micro seconds (2 clocks) to be able to send the number to the 7-segment */
		DEACTIVATE(PA5); 			  /* Deactivate this 7-segment */
	}
}

