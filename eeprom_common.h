#ifndef eeprom_common_h
#define eeprom_common_h


#define WRITE_DELAY_10MS 200

#define TIME_TO_WRITE() (s_eeDirtyMsk && (tmr10ms_t)(get_tmr10ms() - s_eeDirtyTime10ms) >= (tmr10ms_t)WRITE_DELAY_10MS)

extern uint8_t   s_eeDirtyMsk;
extern tmr10ms_t s_eeDirtyTime10ms;

void eeDirty(uint8_t msk);
void eeCheck(bool immediately);
void eeReadAll();
bool eeModelExists(uint8_t id);
void eeLoadModel(uint8_t id);
bool eeConvert();
void eeErase(bool warn);
void ConvertModel(int id, int version);
uint8_t eeFindEmptyModel(uint8_t id, bool down);
void selectModel(uint8_t sub);

#define eeLoadModelHeaders()
#endif
