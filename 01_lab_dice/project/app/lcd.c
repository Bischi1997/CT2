/* ------------------------------------------------------------------
 * --  _____       ______  _____                                    -
 * -- |_   _|     |  ____|/ ____|                                   -
 * --   | |  _ __ | |__  | (___    Institute of Embedded Systems    -
 * --   | | | '_ \|  __|  \___ \   Zurich University of             -
 * --  _| |_| | | | |____ ____) |  Applied Sciences                 -
 * -- |_____|_| |_|______|_____/   8401 Winterthur, Switzerland     -
 * ------------------------------------------------------------------
 * --
 * -- Description:  Implementation of module lcd
 * --               Performs all the interactions with the lcd
 * --
 * -- $Id: lcd.c 5144 2020-09-01 06:17:21Z ruan $
 * ------------------------------------------------------------------
 */

/* standard includes */
#include <stdio.h>

/* user includes */
#include "lcd.h"
#include "reg_ctboard.h"

/* macros */
#define LCD_ADDR_LINE1      0u
#define LCD_ADDR_LINE2      20u

#define NR_OF_CHAR_PER_LINE 20u

#define LCD_CLEAR           "                    "
#define SLOT_SIZE						3

/// STUDENTS: To be programmed

void lcd_write_value(uint8_t slot_nr, uint8_t value)
{
	//define local variables
	uint8_t slot_value = (slot_nr-1)*SLOT_SIZE;
	char string_to_print[3];
	
	//format int-value to string
	uint8_t string_size = snprintf(string_to_print, 3, "%02d ",value);
	
	//print string to LCD on given position
	CT_LCD->ASCII[slot_value++] = string_to_print[0];
	CT_LCD->ASCII[slot_value++] = string_to_print[1];
	CT_LCD->ASCII[slot_value++] = string_to_print[2];
}

void lcd_write_total(uint8_t total_value)
{
	//define local variables
	char string_to_print[20];
	uint8_t i;
	uint8_t j = 0;

	//format int-value to string
	uint8_t string_size = snprintf(string_to_print, 20, "total throws  %03d",total_value);
	
	//print string to LCD
	for(i=20; i<40; i++){
		CT_LCD->ASCII[i] = string_to_print[j];
		j++;
	}
}

void hal_ct_lcd_clear(void)
{
	//print string to LCD
	uint8_t i;
	for(i=0; i<20; i++){
		CT_LCD->ASCII[i] = LCD_CLEAR[i];
		CT_LCD->ASCII[20+i] = LCD_CLEAR[i];
	}
	
	//set LCD to green
	CT_LCD->BG.GREEN = 65535;
	CT_LCD->BG.RED = 0;
	CT_LCD->BG.BLUE = 0;
	
}

/// END: To be programmed
