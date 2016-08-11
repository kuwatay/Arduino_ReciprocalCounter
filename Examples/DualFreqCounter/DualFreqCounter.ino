// ReciprocalCounter Lib example

#include <ReciprocalCounter.h>
#include <FreqCounter.h>

int cnt = 0;
unsigned long frq, mod;
int pinLed = 13;
int fin_pin = 5;  // T1  pin (D5)
int timeout = 50;
#define GATETIME 100 // for normal mode counter
#define GATEMUL  (1000/GATETIME)

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(115200);        // connect to the serial port
  Serial.println("Reciprocal / Normal Frequency Counter");
}

void loop() {
  
  //
  // normal mode
  //
  FreqCounter::f_comp= 0;                 // Set compensation to 8 for 100ms gatetime
  FreqCounter::start(GATETIME);           // Start counting with gatetime of 100ms
  while (FreqCounter::f_ready == 0)       // wait until counter ready
 
  frq=FreqCounter::f_freq;                // read result
  Serial.print(cnt++);
  Serial.print(" Normal  Freq: ");
  Serial.print(frq * GATEMUL);

  digitalWrite(pinLed,!digitalRead(pinLed));  // blink Led

  //
  // reciprocal mode
  //
  ReciprocalCounter::start(fin_pin, timeout);

  frq = ReciprocalCounter::f_freq;
  mod = ReciprocalCounter::f_mod;
  Serial.print(" Reciprocal  Freq: ");
  Serial.print(frq);
  Serial.print(".");
  Serial.println(mod);

  digitalWrite(pinLed,!digitalRead(pinLed));  // blink Led

}  

