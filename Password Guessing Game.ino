/*
  Button

 Turns on and off a light emitting diode(LED) connected to digital
 pin 13, when pressing a pushbutton attached to pin 2.


 The circuit:
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground

 * Note: on most Arduinos there is already an LED on the board
 attached to pin 13.


 created 2005
 by DojoDave <http://www.0j0.org>
 modified 30 Aug 2011
 by Tom Igoe

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Button
 */

// constants won't change. They're used here to
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin
int photocellPin = A2;
int photocellVal = 0;
int photocellValyouChoose = 0;
int photocellValyouGuess = 0;
int maxGuess = 1000;
int minGuess = 0;

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  Serial.begin(9600);
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);
  
  photocellVal = analogRead(photocellPin);
//  Serial.print("photocellVal: ");
//  Serial.print(photocellVal);
//  Serial.print(" ");
//  Serial.print("You choose: ");
//  Serial.print(photocellValyouChoose);
//  Serial.println(" ");
  
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    photocellValyouChoose = photocellVal;
  } 
  else {
  }

  delay(10);

  while (Serial.available() > 0) {
      int photocellValyouGuess = Serial.parseInt();
   
      if(photocellValyouGuess > photocellValyouChoose){
        maxGuess = photocellValyouGuess;
        Serial.print("Too Large! And the range is ");
        Serial.print(minGuess);
        Serial.print("~");
        Serial.println(maxGuess);
      }
      else if(photocellValyouGuess < photocellValyouChoose){
        minGuess = photocellValyouGuess;
        Serial.print("Too Small! And the range is ");
        Serial.print(minGuess);
        Serial.print("~");
        Serial.println(maxGuess);
      }
      else if(photocellValyouGuess == photocellValyouChoose){
        Serial.print("BINGO and the answer is ");
        Serial.println(photocellValyouChoose);
        digitalWrite(ledPin, HIGH);
      }
      
  }
}
