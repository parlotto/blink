/*
 * blink.cpp
 *
 *  Created on: 22 janv. 2015
 *      Author: philippe
 */

#include "blink.h"

Blink::Blink(){
	this->ledPin = 13 ;
	this->onTime = 500 ;
	this->interval = 1000 ;
	previousMillis = 0 ;
	state = 0 ;
	mode = BLINK_BLINK ;
	pinMode(ledPin,OUTPUT);
	digitalWrite(ledPin,state);
}

Blink::Blink(unsigned int ledPin){
	this->ledPin = ledPin ;
	this->onTime = 500 ;
	this->interval = 1000 ;
	previousMillis = 0 ;
	state = 0 ;
	mode = BLINK_BLINK ;
	pinMode(ledPin,OUTPUT);
	digitalWrite(ledPin,state);
}

Blink::Blink(unsigned int ledPin , unsigned int onTime , unsigned int interval) {
	this->ledPin = ledPin ;
	this->onTime = onTime ;
	this->interval = interval ;
	previousMillis = 0 ;
	state = 0 ;
	mode = BLINK_BLINK ;
	pinMode(ledPin,OUTPUT);
	digitalWrite(ledPin,state);

}

Blink::~Blink() {
	pinMode(ledPin,INPUT);
}


void Blink::doBlink(){
	mode = BLINK_BLINK ;

}

void Blink::doFlash(){
	mode = BLINK_FLASH ;
	digitalWrite(ledPin,1);
        previousMillis = millis();
}

void Blink::setBlink(unsigned int onTime , unsigned int interval){
	setOnTime(onTime);
	setInterval(interval);
}
void Blink::setOnTime(unsigned int onTime){

	 this->onTime = onTime ;

}

void Blink::setInterval(unsigned int interval){

	this->interval = interval ;

}
void Blink::setFrequency(float freq) {
    
    this->interval = 1000.0/freq ;
    this->onTime = this->interval / 2 ;
}
void Blink::on() {
	mode = BLINK_FORCED ;
	state = 1 ;
	digitalWrite(ledPin,state);
}
void Blink::off() {
	mode = BLINK_FORCED ;
	state = 0 ;
	digitalWrite(ledPin,state);
}

void Blink::makeBlink() {
	if (mode==BLINK_FORCED ) {
		 digitalWrite(ledPin,state);
		 return ;
	}
        
	unsigned long currentMillis;
        currentMillis = millis();
        if (mode==BLINK_FLASH ) {
                 if(currentMillis - previousMillis >= onTime) {
                      digitalWrite(ledPin,0);
                 }
		
            return ;
	}
    
    
    switch ( state ) {
            case 0 :
    			  if(currentMillis - previousMillis >= (interval-onTime) ) {
    				  previousMillis = currentMillis  ;
    				  state = 1 ;
    				  digitalWrite(ledPin,state);
    			  }
    	         break ;
           case 1 :
        	   if(currentMillis - previousMillis >= onTime) {
        	       	  previousMillis = currentMillis  ;
        	       	  state = 0 ;
        	       	  digitalWrite(ledPin,state);
        	       			  }
        	   break ;
           default : //Ooops !!!
        	   state = 0 ;
        	   previousMillis = currentMillis  ;
        }

}
