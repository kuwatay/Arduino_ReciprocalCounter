/*
  ReciprocalCounter.h
  Using Counter1 for counting 16MHz internal clock
  Using pin X for Gatetime generation

*/

#include <ReciprocalCounter.h>

unsigned long ReciprocalCounter::f_freq;
unsigned long ReciprocalCounter::f_mod;

uint8_t carry;

void ReciprocalCounter::start(int fin_pin, int timeout) {
  uint8_t trig_state, f_carry;
  uint16_t count, time;
  unsigned long f_count, f_time;
  volatile uint8_t * fin_port = portInputRegister(digitalPinToPort(fin_pin));
  uint8_t bitmask = digitalPinToBitMask(fin_pin);

  // initialize timer 1 (16bit timer for internal clock count)
  TCCR1A = 0;   		// normal timer
  TCCR1B = 0;   		// stop timer1
  TIFR1 |= (1 << TOV1);         // clear intpt request
  TIMSK1 |= (1 << TOIE1);       // overflowr interrupt enable

  carry = 0;
  count = 0;
  trig_state = 0;

  // Sync with timer and pulse
  while (((*fin_port) & bitmask) != 0)
    ;
  while (((*fin_port) & bitmask) == 0)
    ;

  TCCR1B |= 1;  			// enable timer 1 no prescaler
  TCNT1 = 0;				// clear counter
  do {                                  // begin chasing signal
    if (((*fin_port) & bitmask) != 0) { // Freq PIN high?
      if (trig_state == 0) {            // standing pulse?
	cli();                          // inhibit intpt of timer
	time = TCNT1;                   // record elapse time
	f_carry = carry;                // save carry of Timer1
	sei();                          // release intpt of carry up
	count++;                        // increment pulse cnt
	trig_state = 1;                 // set status
      }
    } else {
      trig_state = 0; 			// clear status for next
    }
  } while (!((count > 0xffff - 1) ||
	     (carry > timeout))); 	// either count or time

  TIMSK1 &= ~(1 << TOIE1);          	// mask timer1 intpt
  f_count = count - 1;              	// move into 4byte area
  f_time = f_carry;
  f_time = time + (f_time << 16); 	// calculate total times
  ReciprocalCounter::f_freq = (f_count * 16000) / f_time;   //devide 2 blocks for over 32bits calc
  ReciprocalCounter::f_mod  = (f_count * 16000) % f_time;
  ReciprocalCounter::f_freq = ReciprocalCounter::f_freq * 1000 + ((ReciprocalCounter::f_mod * 1000) / f_time);
  ReciprocalCounter::f_mod = ((ReciprocalCounter::f_mod * 1000) % f_time) * 100 / f_time ; // fraction, 2 digits

}

ISR ( TIMER1_OVF_vect ) {
  carry++;
}

