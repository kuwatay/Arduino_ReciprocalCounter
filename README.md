# Arduino_ReciprocalCounter
Arduino based reciprocal frequency counter

This library makes your arduino a simple low frequency counter. 
The library use reciprocal measurement method.
The frequency is calculated by the reciprocal of the time period.

This library is useful for lower frequency; i.e. 5Hz to 30KHz.
Up to 2 digits after the decimal point can be measured in short period of time.

Usage:

`#include <ReciprocalCounter.h>`

for the measurement...

`ReciprocalCounter::start(pin, timeout);`

The results are stored in

`ReciprocalCounter::f_freq, and` 
`ReciprocalCounter::f_mod`

Please consult programs in 'Examples folder' in details.

2016/08/21

-Yoshi
