/*
	Waltdog project is an open source intercom.


	4 December 2016
	by mvento
*/

const unsigned int OPEN_DOOR_PIN = 8;
const unsigned int CALL_PIN = 3;
const unsigned int LED_PIN = 13;


const unsigned long TIME_OPENING_DOOR = 3000;


bool isOpening = false;
unsigned long finishDoorOpening = 0;


void checkDoor() 
{
	if ( millis() > finishDoorOpening ) {
		digitalWrite(OPEN_DOOR_PIN, LOW);
  		isOpening = false;
  		digitalWrite(LED_PIN, LOW);
  		return;
	}

	if ( isOpening == false ) {
	  	digitalWrite(OPEN_DOOR_PIN, HIGH);   
  		digitalWrite(LED_PIN, HIGH);
	  	isOpening = true;
	  	return;
	} 
  	
}

void callingInterruption()
{
	finishDoorOpening = millis() + TIME_OPENING_DOOR;
}

void setup() 
{
	pinMode(OPEN_DOOR_PIN, OUTPUT);
	pinMode(LED_PIN, OUTPUT);
	pinMode(CALL_PIN, INPUT_PULLUP);
	
	attachInterrupt(digitalPinToInterrupt(CALL_PIN), callingInterruption, RISING);
}


void loop() 
{
 	checkDoor();
}