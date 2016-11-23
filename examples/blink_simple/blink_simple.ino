/*
* Two LED are blinked at independant rates. A third LED will flash twice.
* Connect three LED to three pins
* LED1 will blink at 1Hz : 0.5s on ,O.5s off
* LED2 will blink at 0.5Hz : 0.1s on , interval 1s (0.9s off) 
* LED3 will flash at 4s and at 6s after reset
*/

// Change to match your hardware
#define PIN_LED1  4 
#define PIN_LED2  3
#define PIN_LED3  5



#include <blink.h>


Blink led1(PIN_LED1); // default 0.5s on ,O.5s off
Blink led2(PIN_LED2,100,2000); // 0.1s on , interval 2000s (1.8s off) 
Blink led3(PIN_LED3);
void setup() {
  led3.off(); // always off
  led3.setOnTime(100); 
}

void loop() {
 
 if ( millis() == 4000 ) {
   led3.doFlash(); // flash only once for 100ms
 } else if ( millis() == 6000 ) {
   led3.setOnTime(300);
   led3.doFlash(); // flash only once for 300ms
 }
 
 led1.makeBlink();
 led2.makeBlink();
 led3.makeBlink();

}
