#define F_CPU 16000000UL  // 16 MHz

#ifndef opentx_h
#define opentx_h

#include <inttypes.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/eeprom.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/wdt.h>


#define PLAY_REPEAT(x)            (x)                 /* Range 0 to 15 */
#define PLAY_NOW                  0x10
#define PLAY_BACKGROUND           0x20
#define PLAY_INCREMENT(x)         ((uint8_t)(((uint8_t)x) << 6))   /* -1, 0, 1, 2 */
#define CASE_CPUARM(x)
#define SIMU_SLEEP(x)
#define IF_CPUARM(x)
#define memclear(p, s) memset(p, 0, s)
#define assert(x)
#define FORCEINLINE inline __attribute__ ((always_inline))
#define NOINLINE __attribute__ ((noinline))
#define CONVERT_PTR_UINT(x) ((uint32_t)(x))
#define CONVERT_UINT_PTR(x) ((uint32_t *)(x))
#define DIM(arr) (sizeof((arr))/sizeof((arr)[0]))
#define pgm_read_adr(address_short) pgm_read_word(address_short)
#define MASK_CFN_TYPE  uint32_t  // current max = 32 function switches
#define MASK_FUNC_TYPE uint8_t   // current max = 8 functions
#define BITMASK(bit) (1<<(bit))


enum BaseCurves {
  CURVE_NONE,
  CURVE_X_GT0,
  CURVE_X_LT0,
  CURVE_ABS_X,
  CURVE_F_GT0,
  CURVE_F_LT0,
  CURVE_ABS_F,
  CURVE_BASE
};

/* make sure the defines below always go in numeric order */
enum AUDIO_SOUNDS {
    AU_TADA,
#if defined(VOICE)
    AU_THROTTLE_ALERT,
    AU_SWITCH_ALERT,
    AU_BAD_EEPROM,
    AU_EEPROM_FORMATTING,
#endif
    AU_TX_BATTERY_LOW,
    AU_INACTIVITY,
    AU_ERROR,
    AU_KEYPAD_UP,
    AU_KEYPAD_DOWN,
    AU_MENUS,
    AU_TRIM_MOVE,
    AU_WARNING1,
    AU_WARNING2,
    AU_WARNING3,
    AU_TRIM_MIDDLE,
    AU_POT_MIDDLE,
    AU_MIX_WARNING_1,
    AU_MIX_WARNING_2,
    AU_MIX_WARNING_3,
    AU_TIMER_00,
    AU_TIMER_LT10,
    AU_TIMER_20,
    AU_TIMER_30,
    AU_FRSKY_FIRST,
    AU_FRSKY_BEEP1 = AU_FRSKY_FIRST,
    AU_FRSKY_BEEP2,
    AU_FRSKY_BEEP3,
    AU_FRSKY_WARN1,
    AU_FRSKY_WARN2,
    AU_FRSKY_CHEEP,
    AU_FRSKY_RATATA,
    AU_FRSKY_TICK,
    AU_FRSKY_SIREN,
    AU_FRSKY_RING,
    AU_FRSKY_SCIFI,
    AU_FRSKY_ROBOT,
    AU_FRSKY_CHIRP,
    AU_FRSKY_TADA,
    AU_FRSKY_CRICKET,
    AU_FRSKY_ALARMC,
    AU_FRSKY_LAST,
    AU_NONE=0xff
};


template<class t> FORCEINLINE t min(t a, t b) { return a<b?a:b; }
template<class t> FORCEINLINE t max(t a, t b) { return a>b?a:b; }
template<class t> FORCEINLINE t sgn(t a) { return a>0 ? 1 : (a < 0 ? -1 : 0); }
template<class t> FORCEINLINE t limit(t mi, t x, t ma) { return min(max(mi,x),ma); }
template<class t> void SWAP(t & a, t & b) { t tmp = b; b = a; a = tmp; }

#include "myeeprom.h"

trim_t getRawTrimValue(uint8_t phase, uint8_t idx);
#define tmr10ms_t uint16_t
extern volatile tmr10ms_t g_tmr10ms;
extern uint8_t  g_vbat100mV;
#define IS_TXBATT_WARNING() (g_vbat100mV <= g_eeGeneral.vBatWarn)

typedef int8_t rotenc_t;
typedef int16_t getvalue_t;
typedef uint8_t mixsrc_t;
typedef int8_t swsrc_t;

FlightModeData *flightModeAddress(uint8_t idx);
ExpoData *expoAddress(uint8_t idx);
MixData *mixAddress(uint8_t idx);
LimitData *limitAddress(uint8_t idx);
bool getSwitch(swsrc_t swtch);

#if defined(ROTARY_ENCODERS)
  // Global rotary encoder registers
  extern volatile rotenc_t g_rotenc[ROTARY_ENCODERS];
#elif defined(ROTARY_ENCODER_NAVIGATION)
  extern volatile rotenc_t g_rotenc[1];
#endif

#if defined(ROTARY_ENCODERS)
	uint8_t getRotaryEncoderFlightPhase(uint8_t idx);
	int16_t getRotaryEncoder(uint8_t idx);
	void incRotaryEncoder(uint8_t idx, int8_t inc);
#endif

extern inline uint16_t get_tmr10ms()
{
	uint16_t time  ;
	cli();
	time = g_tmr10ms ;
	sei();
	return time ;
}

#define MAX_ALERT_TIME   60

struct t_inactivity
{
  uint16_t counter;
  uint8_t  sum;
};
extern struct t_inactivity inactivity;
extern uint8_t stickMode;

char idx2char(int8_t idx);

#include "keys.cpp"
#include "boards/mega2560/mega2560.cpp"
#include "translations.cpp"
#include "strhelpers.cpp"

#define KEY_ENTER        KEY_MENU
#define KEY_PLUS         KEY_RIGHT
#define KEY_MINUS        KEY_LEFT

typedef struct {
  MASK_FUNC_TYPE activeFunctions;
  MASK_CFN_TYPE  activeSwitches;
  tmr10ms_t lastFunctionTime[NUM_CFN];

  inline bool isFunctionActive(uint8_t func)
  {
    return activeFunctions & ((MASK_FUNC_TYPE)1 << func);
  }

  void reset()
  {
    memclear(this, sizeof(*this));
  }
} CustomFunctionsContext;
#define g_blinkTmr10ms    (*(uint8_t*)&g_tmr10ms)
#define FLASH_DURATION 20 /*200ms*/

extern uint8_t flashCounter;


#if !defined(GUI)
  #define MESSAGE_SOUND_ARG
  #define MESSAGE(...)
  #define ALERT(...)
#elif defined(VOICE)
  #define MESSAGE_SOUND_ARG , uint8_t sound
  #define MESSAGE(title, msg, info, sound) message(title, msg, info, sound)
  #define ALERT(title, msg, sound) alert(title, msg, sound)
#else
  #define MESSAGE_SOUND_ARG
  #define MESSAGE(title, msg, info, sound) message(title, msg, info)
  #define ALERT(title, msg, sound) alert(title, msg)
#endif

extern void message(const pm_char *title, const pm_char *s, const char *last MESSAGE_SOUND_ARG);
extern void alert(const pm_char * t, const pm_char * s MESSAGE_SOUND_ARG);

#if defined(AUDIO)
#include "audio/audio_avr.cpp"
#endif

#if defined(BUZZER)
#include "audio/buzzer.cpp"
#endif

#include "debug/rtc.cpp"
#include "debug/debug.cpp"
#include "debug/dump.cpp"

#include "gui/menus.cpp"
#include "timers.cpp"
#include "eeprom_rlc.cpp"
#include "eeprom_common.cpp"
#include "gui/fonts.cpp"
#include "gui/lcd.cpp"

#endif