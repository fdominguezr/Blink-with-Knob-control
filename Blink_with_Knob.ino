/*
  Blink
  The basic Energia example.
  Turns on an LED on for one second, then off for one second, repeatedly.
  Change the LED define to blink other LEDs.
  
  Hardware Required:
  * LaunchPad with the RED LED onboard
  * Controllerd by a knob at PE_4
  
  This example code is in the public domain.
*/

// most launchpads have a red LED
#define LED RED_LED

//see pins_energia.h for more LED definitions
//#define LED GREEN_LED
  
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);     
  Serial.begin(9600);

}

// the loop routine runs over and over again forever:
void loop() {
  int potpin = PE_4;  // analog pin used to connect the potentiometer
  int val;    // variable to read the value from the analog pin 
  val = analogRead(potpin);            // reads the value of the potentiometer (value between 0 and 4095) 
  val = map(val, 0, 4095, 0, 100);     // scale it to use it with the LED (value between 0 and 100) 
  Serial.println(val);
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(val);               // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(val);               // wait for a second
}
