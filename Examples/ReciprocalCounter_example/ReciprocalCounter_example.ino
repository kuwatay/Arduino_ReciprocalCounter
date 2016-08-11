// ReciprocalCounter Lib example

#include <ReciprocalCounter.h>

int cnt = 0;
unsigned long frq, mod;
int pinLed = 13;
int fin_pin = 2;
int timeout = 50;

void setup() {
  pinMode(pinLed, OUTPUT);
  Serial.begin(115200);        // connect to the serial port
  Serial.println("Reciprocal Counter");
}

void loop() {

  ReciprocalCounter::start(fin_pin, timeout);

  frq = ReciprocalCounter::f_freq;
  mod = ReciprocalCounter::f_mod;
  Serial.print(cnt++);
  Serial.print("  Freq: ");
  Serial.print(frq);
  Serial.print(".");
  Serial.println(mod);

  digitalWrite(pinLed,!digitalRead(pinLed));  // blink Led

}  

