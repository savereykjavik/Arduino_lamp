/*

Glow in dark, with fotoresistor.

 */

// Pin 13 is used to turn on the light
// Pin 12 turn off
// Pin 0 Analog In reads fotoresistor

// Give them names (no magic numbers) kan stå som int, men const int gör de till konstata tal.
const int switchOn = 13;
const int switchOff = 12;
const int lightmeter = 0; 
const int threshold = 400;
const int tolerance = 100;

// OBS OBS OBS Global states - variabler som sätts innan setup körs. 
// Borde reflektera vilket grundstate du vill ha om den deklareras med värde.
// Declate the state of the lamp. 0 = off, 1 = on.
int state;


// the setup routine runs once when you press reset:
void setup() { 
  // initialize the digital pin as an output/inputs.
  pinMode(switchOn, OUTPUT);
  pinMode(switchOff, OUTPUT);
  turnOff();
}

// the loop routine runs over and over again forever:
void loop() {
  int light = analogRead(lightmeter);
  
  // Obs if the if/else bodies contain only one statement, no blocks { } are needed.
  if      (state == 1 && light > threshold + tolerance) turnOff();
  else if (state == 0 && light < threshold - tolerance) turnOn();
}  

void turnOn() {
  // Precondition: if the lamp is already on, do nothing. The funtion returns/ends.
  // if (state == 1) return;
  
  digitalWrite(switchOn, HIGH);
  digitalWrite(switchOff, LOW);
  delay(500);
  digitalWrite(switchOn, LOW);
  state = 1;
}

void turnOff() {
  // Precondition: if the lamp is already off, do nothing. The funtion returns/ends.
  // if (state == 0) return;
  
  digitalWrite(switchOn, LOW);
  digitalWrite(switchOff, HIGH);
  delay(500);
  digitalWrite(switchOff, LOW);
  state = 0;
}
