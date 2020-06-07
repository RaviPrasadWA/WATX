#include "menus.h"

MenuHandlerFunc menuHandlers[5];
uint8_t menuEvent = 0;
uint8_t menuVerticalPositions[4];
uint8_t menuLevel = 0;

void popMenu()
{
  assert(menuLevel>0);
  menuLevel = menuLevel-1;
  menuEvent = EVT_ENTRY_UP;
}

void chainMenu(MenuHandlerFunc newMenu)
{
  menuHandlers[menuLevel] = newMenu;
  menuEvent = EVT_ENTRY;
}

void pushMenu(MenuHandlerFunc newMenu)
{
  killEvents(KEY_ENTER);

  if (menuLevel == 0) {
    if (newMenu == menuGeneralSetup)
      menuVerticalPositions[0] = 1;
    if (newMenu == menuModelSelect)
      menuVerticalPositions[0] = 0;
  }
  else {
    menuVerticalPositions[menuLevel] = menuVerticalPosition;
  }

  menuLevel++;

  assert(menuLevel < DIM(menuHandlers));

  menuHandlers[menuLevel] = newMenu;
  menuEvent = EVT_ENTRY;
}

