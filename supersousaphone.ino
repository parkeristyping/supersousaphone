// Tone library for producing tones
#include <Tone.h>

// Setup 2 tones for a 2-oscillator synth sound
Tone tone1;
Tone tone2;

// Define constants for the pins that our buttons lead to
const int buttonOnePin = 2;
const int buttonTwoPin = 4;
const int buttonThreePin = 7;

// Define a constant for the LED pin, which we'll have light up
// just for some extra feedback
const int ledPin = 13;

// Some state variables for the buttons
int buttonOneState = 0;
int buttonTwoState = 0;
int buttonThreeState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as inputs
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  // setup tones
  tone1.begin(8);
  tone2.begin(12);
}

void loop() {
  // read the state of the pushbutton values
  buttonOneState = digitalRead(buttonOnePin);
  buttonTwoState = digitalRead(buttonTwoPin);
  buttonThreeState = digitalRead(buttonThreePin);

  // check which pushbutton is pressed and trigger corresponding note
  // TODO: make this smarter so button 1 doesn't always trump button 2, etc
  if (buttonOneState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone1.play(NOTE_A4 + 1);
    tone2.play(NOTE_A3);
  } else if (buttonTwoState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone1.play(NOTE_C4 + 1);
    tone2.play(NOTE_C3);
  } else if (buttonThreeState == HIGH) {
    digitalWrite(ledPin, HIGH);
    tone1.play(NOTE_D4 + 1);
    tone2.play(NOTE_D3);
  } else {
    digitalWrite(ledPin, LOW);
    tone1.stop();
    tone2.stop();
  }
}
