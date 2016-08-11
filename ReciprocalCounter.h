
/*
  ReciprocalCounter.h - Library for a Reciprocal Frequency Counter.

  based on gataro AVR at http://gataro-avr-ken.cocolog-nifty.com/blog/2008/11/lcdfg-6a43.html
  also based on FreqCounter lib by  Martin Nawrath, KHM Lab3, Dec. 2008

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





