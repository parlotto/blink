/*
 * blink.h
 *
 *  Created on: 22 janv. 2015
 *      Author: philippe
 */

#ifndef BLINK_H_
#define BLINK_H_

#include "Arduino.h"

#define BLINK_BLINK 0
#define BLINK_FORCED 1
#define BLINK_FLASH 2

class Blink {
public:
	Blink();
	Blink(unsigned int ledPin);
	Blink(unsigned int ledPin , unsigned int onTime , unsigned int interval);
	~Blink();
	void on();
	void off();
	void doBlink();
        void doFlash();
	void setBlink(unsigned int onTime , unsigned int interval);
	void setInterval(unsigned int interval);
	void setOnTime(unsigned int onTime );
        void setFrequency( float freq );
	void makeBlink();  // must be called continuously in loop()

private :
	unsigned int ledPin ;
	unsigned long onTime ;
	unsigned long interval ;
	unsigned long previousMillis ;
	int state  ;
	int mode ;
};

#endif /* BLINK_H_ */
