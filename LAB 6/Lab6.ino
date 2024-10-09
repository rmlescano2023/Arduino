#include <ezButton.h>
ezButton button(2);

unsigned long press_down = 0, press_up = 0;  
const int threshold = 5000, pin_count = 8;
int state, counter = 0, device_state = LOW;

bool pressed = false;

byte pins[] = {5, 6, 7, 8, 9, 10, 11, 12};
String binary_form;

void setup() {
  Serial.begin(9600);                                         // activate serial
  button.setDebounceTime(50);                                 // debounce for button
  attachInterrupt(digitalPinToInterrupt(2), down, FALLING);   // on press-down, call Interrupt Service Routine

  for(int i = 0; i < pin_count; i++) {                        // record all pins as output pins
    pinMode(pins[i], OUTPUT);
  }
}

void loop() {
  if (pressed == true){                                       // if button is pressed (from ISR "up")
    long duration = press_up-press_down;                      // calculate duration of press
    Serial.print("PRESS DURATION: ");                         // print the duration in milliseconds
    Serial.print(duration);
    Serial.println();
   
    if (duration > threshold)                                 // if duration > 5 sec
      action_long();                                          // call action for long press
    else                                                      // if duration <= 5 sec
      action_short();                                         // call action for short press
      
    pressed = false;                                          // reset press
  }

  if (device_state == HIGH){                                  // if device is set to ON
    if (counter <= 255) {                                     // if counter can still be represented in 8 bits
      binary_form = String(counter, BIN);                     // convert counter to bits
      int activeLED = binary_form.length();                   // number of bits = number of LEDs to use
      
      for(int i = 0; i < activeLED; i++) {                    // iterate through the bits
        if(binary_form[i] == '1') state = HIGH;               // if bit = 1, set the LED to ON
        else state = LOW;                                     // if bit = 0, set the LED to OFF
        digitalWrite(i + 4 + activeLED - 2*i, state);         // find the LED pin using offset formula and set the state
      }
      Serial.print("COUNTER VALUE: ");                        // print the counter value
      Serial.print(counter);
      Serial.println();
      counter++;                                              // increment counter
      delay(1000);                                            // delay by 1 sec
      
      } else {                                                // if counter exceed 255
        control_LED(LOW);                                     // reset to 0
        counter = 0;                                          
      }
  }

 

}
void down() {                                                 // ISR for press down
  press_down = millis();                                      // record time
  attachInterrupt(digitalPinToInterrupt(2), up, RISING);  
}

void up() {                                                   // ISR for press release
  press_up = millis();                                        // record time
  pressed = true;                                             // set pressed to true
  attachInterrupt(digitalPinToInterrupt(2), down, FALLING);
}

void action_long(){                                           // if press > 5 sec
  if (device_state == HIGH) {                                 // if device is ON
    device_state = LOW;                                       // set device to OFF
    control_LED(LOW);                                         // turn OFF all LED
    Serial.println("LONG PRESS ON DEVICE ACTIVE");
  } else {                                                    // if device is OFF
    device_state = HIGH;                                      // set device to ON                               
    Serial.println("LONG PRESS ON DEVICE INACTIVE");
  }
  counter = 0;                                                // reset counter
}

void action_short(){                                          // if press <= 5 sec
  if (device_state == HIGH){                                  // if device is ON
    control_LED(LOW);                                         // turn OFF all LED
    counter = 0;                                              // reset counter
    Serial.println("SHORT PRESS ON DEVICE ACTIVE");
  } else {                                                    // if device is OFF
    control_LED(HIGH);                                        // turn ON all LED
    delay(2000);                                              // wait for 2 sec
    control_LED(LOW);                                         // turn OFF all LED
    Serial.println("SHORT PRESS ON DEVICE INACTIVE");
  }
}

void control_LED(int state) {                                 // to control LED state
  int pin = 0;
  while (pin < pin_count){                                    // iterate through all pins
    digitalWrite(pin + 5, state);                             // and set to passed state, note the offset
    pin++;
  }
}
