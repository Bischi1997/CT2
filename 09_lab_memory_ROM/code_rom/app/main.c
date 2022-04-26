/* ------------------------------------------------------------------
 * --  _____       ______  _____                                    -
 * -- |_   _|     |  ____|/ ____|                                   -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems    -
 * --   | | | '_ \|  __|  \___ \   Zurich University of             -
 * --  _| |_| | | | |____ ____) |  Applied Sciences                 -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland     -
 * ------------------------------------------------------------------
 * --
 * -- Application for testing external memory
 * --
 * -- $Id: main.c 3647 2016-09-27 12:37:36Z kesr $
 * ------------------------------------------------------------------
 */

/* standard includes */
#include <stdint.h>
#include <stdbool.h>
#include <reg_ctboard.h>
#include "hal_ct_buttons.h"

/// STUDENTS: To be programmed

#define START_ADDR ((volatile uint8_t*)0x64000400)

/// END: To be programmed

int main(void)
{
    /// STUDENTS: To be programmed
		
		uint32_t j = 0;
		while(1)
		{
			for(j=0; j<256; j++)
			{
				if (j!=START_ADDR[j])
				{
					CT_LED->BYTE.LED23_16 = START_ADDR[j];
					CT_LED->BYTE.LED15_8 = j;
					while (!hal_ct_button_is_pressed(HAL_CT_BUTTON_T0));
				}
			}
		}
		
		

    /// END: To be programmed
}
