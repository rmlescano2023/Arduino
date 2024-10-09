#include <ezButton.h>

const int BUTTON_PIN = 7;           // Arduino Pin for Button
const int LED_PIN = 3;              // Arduino Pin for LED
const int LONG_PRESS_TIME  = 5000;  // long press threshold duration

ezButton button(BUTTON_PIN);        // library for debounce

int ledState = LOW;                 // default LED OFF

unsigned long pressedTime  = 0;     // start
unsigned long releasedTime = 0;     // end

long pressDuration;                 // container for duration of presses
bool isPressing = false;            // allow detect of long-press while pressing
bool startBlink = false;            // switch to toggle blink
bool stopBlink = false;             // switch to toggle blink

void setup() {
  Serial.begin(9600);               // initiate terminal
  button.setDebounceTime(50);       // debounce of 50 msec
}

void loop() { 
  button.loop();                    // prerequisite call for the button library
  
  if(button.isPressed()){           // detect any press
    stopBlink = true;               // by default, any switch should toggle to STOP LED BLINK (into STATIC HIGH)
    isPressing = true;              // switch ON "pressing"; allow detect of long-press while pressing
    pressedTime = millis();         // record pressed time start
  }
  
  if(button.isReleased()) {         // clause if button is released
    isPressing = false;             // switch OFF "pressing"
    releasedTime = millis();        // record end time

    pressDuration = releasedTime - pressedTime;           // solve for duration (end-start)
    if(pressDuration < LONG_PRESS_TIME){                  // if less than long-press threshold duration (thus short-press)
      Serial.print("A SHORT press is detected: \t");
      if (startBlink == true && stopBlink == true){       // if STARTED BLINKING; needs to STOP
        ledState = HIGH;                                  // reassign LED state to HIGH
        Serial.print("<blink off> \t");
        digitalWrite(LED_PIN,ledState);                   // set LED state: STATIC HIGH
        startBlink = false;                               // switch startBlink to false; toggle to STOP LED BLINK
    } else {
      ledState = !ledState;                               // if NOT BLINKING, toggle LED state (invert)
      digitalWrite(LED_PIN, ledState);                    // set LED state: INVERT of previous state
      }
    Serial.print(ledState);                               // output LED state in serial monitor
    Serial.print("\n");
    }
  }

  if(isPressing == true) {                                        // continuously calculate duration while button is pressed
    pressDuration = millis() - pressedTime;
    if(pressDuration > LONG_PRESS_TIME) {                         // once long press threshold duration is reached
      Serial.println("A LONG press is detected: \t <blink on>");
      startBlink = true;                                          // toggle to ALLOW LED BLINK
      stopBlink = false;                                          
    }
  }
    
  if (startBlink == true && stopBlink == false){                  // START BLINKING; not need to stop
    digitalWrite(LED_PIN, HIGH);                                  // LED state: BLINKING (1 second delay)
    Serial.println("HIGH \t 1");
    delay(1000);                      
    digitalWrite(LED_PIN, LOW);  
    Serial.println("LOW \t 0"); 
    delay(1000);           
  }
}
