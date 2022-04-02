/* ----------------------------------------------------------------------------
 * --  _____       ______  _____                                              -
 * -- |_   _|     |  ____|/ ____|                                             -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems              -
 * --   | | | '_ \|  __|  \___ \   Zuercher Hochschule Winterthur             -
 * --  _| |_| | | | |____ ____) |  (University of Applied Sciences)           -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland               -
 * ----------------------------------------------------------------------------
 * --
 * -- Project     : CT2 lab - Timer PWM
 * -- Description : Main program and interrupt service routine
 * --
 * --               Task 1: - Setup timer TIM4 to 1s.
 * --                       - Setup interrupt to toggle LED
 * --               Task 2: - Setup timer TIM3 to PWM mode
 * --                       - Read DIP switches to set duty cycles of channels
 * --               Task 3: - Use interrupt of TIM4 to create a transition
 * --                         from one colour to another
 * --
 * -- $Id: main.c 4750 2019-03-18 15:29:55Z akdi $
 * ------------------------------------------------------------------------- */

/* standard includes */
#include <stdint.h>
#include <reg_stm32f4xx.h>
#include <reg_ctboard.h>

/* user includes */
#include "timer.h"


/* -- Macros used as by student code
 * ------------------------------------------------------------------------- */

/// STUDENTS: To be programmed




/// END: To be programmed

/* -- global variables visible only within this module
 * ------------------------------------------------------------------------- */

/* cyclic counter value between 0 and 0xF */
static uint16_t cycle_counter_4bit = 0;

/* -- M A I N
 * ------------------------------------------------------------------------- */

int main(void)
{
    /// STUDENTS: To be programmed
		uint16_t dip7_0, dip15_8, dip23_16;

		CT_LED->BYTE.LED31_24 = 0x0;
		tim3_init();
		tim4_init();
		
		while(1){
			dip7_0 = CT_DIPSW->BYTE.S7_0 & 0xF;
			dip15_8 = CT_DIPSW->BYTE.S15_8 & 0xF;
			dip23_16 = CT_DIPSW->BYTE.S23_16 & 0xF;
			
			tim3_set_compare_register(PWM_CH1,(dip7_0 * 4000));
			tim3_set_compare_register(PWM_CH2,(dip15_8 * 4000));
			tim3_set_compare_register(PWM_CH3,(dip23_16 * 4000));
		}



    /// END: To be programmed
}


/* -- Interrupt service routine
 * ------------------------------------------------------------------------- */

void TIM4_IRQHandler(void)
{
    /// STUDENTS: To be programmed
		tim4_reset_uif();
		CT_LED->BYTE.LED31_24 = ~CT_LED->BYTE.LED31_24;


    /// END: To be programmed
}
