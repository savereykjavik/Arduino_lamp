/*

Control a switch (connected to a lamp) with a light sensor and an arduino.

 */

// Pin 13 is used to turn on the switch
// Pin 12 is used to turn off the switch
// Pin 0 (Analog In) reads light sensor

// Give the pins names
const int switchOn = 13;
const int switchOff = 12;
const int lightmeter = 0;

// set the light parameters
// hysteresis model: http://en.wikipedia.org/wiki/Hysteresis
// threshold is the "center point" of when the light will switch from on/off and off/on
// tolerance is the span that separates the on and off trigger levels (to avoid flickering of the lamp)
const int threshold = 400;
const int tolerance = 100;

// Declate the variable "state" that will serve as an indicator for when the switch is on or off 
// (0 = off, 1 = on).
int state;

// the setup routine runs once when you press reset:
void setup() { 
  // initialize the digital pin as an output/inputs.
  pinMode(switchOn, OUTPUT);
  pinMode(switchOff, OUTPUT);
  // call turnOff to start with the switch being off
  turnOff();
}

// this loop routine runs over and over again forever to read the value of the light sensor:
void loop() {
  int light = analogRead(lightmeter);
  if      (state == 1 && light > threshold + tolerance) turnOff();
  else if (state == 0 && light < threshold - tolerance) turnOn();
}  

// this function turns the switch on, and then changes the state variable to "1"
void turnOn() {
  digitalWrite(switchOn, HIGH);
  digitalWrite(switchOff, LOW);
  delay(500);
  digitalWrite(switchOn, LOW);
  state = 1;
}

//this function turns the switch off, and then changes the state variable to "0"
void turnOff() {
  digitalWrite(switchOn, LOW);
  digitalWrite(switchOff, HIGH);
  delay(500);
  digitalWrite(switchOff, LOW);
  state = 0;
}
