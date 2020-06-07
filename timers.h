#ifndef _TIMERS_H_
#define _TIMERS_H_

#include "eeprom_common.h"

#define TMR_OFF      0
#define TMR_RUNNING  1
#define TMR_NEGATIVE 2
#define TMR_STOPPED  3


typedef int16_t tmrval_t;
typedef uint16_t tmrstart_t;
#define TIMER_MAX     (0xffff/2)
#define TIMER_MIN     (-TIMER_MAX-1)

struct TimerState {
  uint16_t cnt;
  uint16_t sum;
  uint8_t  state;
  tmrval_t  val;
  uint8_t  val_10ms;
};

void timerReset(uint8_t idx);
void saveTimers();
void restoreTimers();
void evalTimers(int16_t throttle, uint8_t tick10ms);

extern TimerState timersStates[TIMERS];

#endif
