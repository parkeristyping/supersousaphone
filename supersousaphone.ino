// Tone library for producing tones
#include <Tone.h>

// Setup 2 tones for a 2-oscillator synth sound
Tone tone1;
Tone tone2;

// Define constants for the pins that our buttons lead to
const int buttonOnePin = 2;
const int buttonTwoPin = 4;
const int buttonThreePin = 7;

// Pin for a button that will serve as a proxy for a mouthpiece-controlled noise gate
const int mouthpiecePin = 5;

// Define a constant for the LED pin, which we'll have light up
// just for some extra feedback
const int ledPin = 13;

// Some state variables for the buttons
int buttonOneState = 0;
int buttonTwoState = 0;
int buttonThreeState = 0;

int mouthpieceState = 0;

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pins as inputs
  pinMode(buttonOnePin, INPUT);
  pinMode(buttonTwoPin, INPUT);
  pinMode(buttonThreePin, INPUT);
  pinMode(mouthpiecePin, INPUT);
  // setup tones
  tone1.begin(8);
  tone2.begin(12);
}

// todo: learn some C and clean up this abomination
int buttonsToNote(int b1, int b2, int b3) {
  if (b1 == HIGH) {
    if (b2 == HIGH) {
      if (b3 == HIGH) {
        return NOTE_D2;
      } else {
        return NOTE_E2;
      }
    } else {
      if (b3 == HIGH) {
        return NOTE_FS2;
      } else {
        return NOTE_A2;
      }
    }
  } else {
    if (b2 == HIGH) {
      if (b3 == HIGH) {
        return NOTE_B2;
      } else {
        return NOTE_D3;
      }
    } else {
      if (b3 == HIGH) {
        return NOTE_E3;
      } else {
        return NOTE_FS3;
      }
    }
  }
}

void loop() {
  // read the state of the pushbutton values
  buttonOneState = digitalRead(buttonOnePin);
  buttonTwoState = digitalRead(buttonTwoPin);
  buttonThreeState = digitalRead(buttonThreePin);
  mouthpieceState = digitalRead(mouthpiecePin);

  // shut off everything if mouthpiece isn't firing
  if (mouthpieceState == LOW) {
    digitalWrite(ledPin, LOW);
    tone1.stop();
    tone2.stop();
  } else {
    // convert button configuration to integer
    digitalWrite(ledPin, HIGH);
    tone1.play(buttonsToNote(buttonOneState, buttonTwoState, buttonThreeState));
    tone2.play(buttonsToNote(buttonOneState, buttonTwoState, buttonThreeState) / 2);
  }
}
