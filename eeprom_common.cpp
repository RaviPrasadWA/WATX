#include "eeprom_common.h"

uint8_t   s_eeDirtyMsk;
tmr10ms_t s_eeDirtyTime10ms;

void eeDirty(uint8_t msk)
{
  s_eeDirtyMsk |= msk;
  s_eeDirtyTime10ms = get_tmr10ms() ;
}

uint8_t eeFindEmptyModel(uint8_t id, bool down)
{
  uint8_t i = id;
  for (;;) {
    i = (MAX_MODELS + (down ? i+1 : i-1)) % MAX_MODELS;
    if (!eeModelExists(i)) break;
    if (i == id) return 0xff; // no free space in directory left
  }
  return i;
}

void selectModel(uint8_t sub)
{
  #if !defined(COLORLCD)
    displayPopup(STR_LOADINGMODEL);
  #endif
  saveTimers();
  eeCheck(true); // force writing of current model data before this is changed
  g_eeGeneral.currModel = sub;
  eeDirty(EE_GENERAL);
  eeLoadModel(sub);
}


void eeReadAll()
{
  if (!eepromOpen() || !eeLoadGeneral()) {
    eeErase(true);
  }
  else {
    eeLoadModelHeaders();
  }

  stickMode = g_eeGeneral.stickMode;
  eeLoadModel(g_eeGeneral.currModel);
}
