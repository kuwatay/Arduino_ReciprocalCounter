
/*
  ReciprocalCounter.h - Library for a Reciprocal Frequency Counter.


  also refer to Martin Nawrath, KHM Lab3, Dec. 2008
  Released into the public domain.
*/

#ifndef ReciprocalCounter_h
#define ReciprocalCounter_h

#include <avr/interrupt.h>

#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include <WConstants.h>
#endif

namespace ReciprocalCounter {
  extern unsigned long f_freq;
  extern unsigned long f_mod;
  void start(int pin, int timeout);
}

#endif





