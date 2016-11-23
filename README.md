# blink
a class to blink led for arduino
Blink is based on millis() counter.
1/ Create led blink objects :
    Blink myLed(4,100,1000); // a led on arduino pin 4. OnTime 100ms , period 1s
    Blink led13(13); // a led on arduino pin 13. OnTime 0.5s , period 1s
2/ in loop() always call makeBlink() for each led to update leds state
   loop() {
    // your code
    
   myLed.makeBlink();
   led13.makeBlink();
   }

Blink parameter can be change at any time with blink class method :
  void on() ; // always on
  void off() ; // always off
  void doFlash(); // on only once during onTime
  void doBlink(); // make blink again after on() or off() or doFlash()
  void setBlink(unsigned int onTime , unsigned int interval); // modify onTime and interval
  void setInterval(unsigned int interval);
  void setOnTime(unsigned int onTime );
  void setFrequency( float freq ); // set blink frequency, 50% on , 50% off

for more information, see example or source.