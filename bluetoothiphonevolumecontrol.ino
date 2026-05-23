#include <HijelHID_BLEKeyboard.h>
//use this library
// define your encoder pins
#define ENCODER_CLK 22
#define ENCODER_DT  21
#define ENCODER_SW  19  // click to mute

// set the name for the device in bluetooth discovery
HijelHID_BLEKeyboard bleKeyboard("ESP32 Volume Knob", "DIY", 100);

int lastClkState;

void setup() {
  pinMode(ENCODER_CLK, INPUT_PULLUP); // use internal pullups for stability
  pinMode(ENCODER_DT, INPUT_PULLUP);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  lastClkState = digitalRead(ENCODER_CLK);
  
  // start the bluetooth keyboard emulation
  bleKeyboard.begin();
}

void loop() {
  // heck if connected to your iPhone
  if (bleKeyboard.isConnected()) {
    
    // read the knob rotation
    int currentClkState = digitalRead(ENCODER_CLK);
    
    // detect the precise moment the knob turns
    if (currentClkState != lastClkState) {
      if (digitalRead(ENCODER_DT) != currentClkState) {
        // press and instantly release ensures iOS captures the media command
        bleKeyboard.press(MEDIA_VOLUME_UP);
        bleKeyboard.releaseAll();
      } else {
        bleKeyboard.press(MEDIA_VOLUME_DOWN);
        bleKeyboard.releaseAll();
      }
      delay(50); // small debounce delay so it doesn't skip steps
    }
    lastClkState = currentClkState;

    // read the button click for Mute
    if (digitalRead(ENCODER_SW) == LOW) {
      bleKeyboard.press(MEDIA_MUTE);
      bleKeyboard.releaseAll();
      delay(300); // debounce delay so it doesn't double-mute
    }
  }
}