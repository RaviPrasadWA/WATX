#include "lcd.h"

#define NUM_BODY_LINES      (LCD_LINES-1)
#define MENU_HEADER_HEIGHT  FH

void displaySplash();
void displayScreenIndex(uint8_t index, uint8_t count, uint8_t attr);

#define DEFAULT_SCROLLBAR_X (LCD_W-1)
void displayScrollbar(coord_t x, coord_t y, coord_t h, uint16_t offset, uint16_t count, uint8_t visible);


#define SET_SCROLLBAR_X(x)
