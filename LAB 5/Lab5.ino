const int LED_PIN = 3;                              // pin of LED
const int POT_PIN = A0;                             // pin of potentiometer
const int b = 6;                                    // y-intercept
const int m = -1;                                   // slope
float d = 0;                                        // placeholder for delay value

void setup() {
  Serial.begin(9600);                               // initialize serial at 9600 bits per second:
}

void loop() {
  int sensorValue = analogRead(A0);                 // read analog input from potentiometer

  // analog reading goes from 0 - 1023
  // convert to voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);

  // print voltage value in volts
  Serial.print("Input:\t");
  Serial.print(voltage);
  Serial.print(" volt/s");
  Serial.println();

  // if voltage meets threshold of 2 volts
  if (voltage >= 2){
    d = (m*voltage + b) * 1000;                     // solve for (y = mx + b)1000; d = delay, x = voltage input)
    Serial.print("Delay:\t");                       // print delay value in seconds
    Serial.print(d/1000);
    Serial.print(" second/s");
    Serial.println("\n");

    // blink LED given delay d
    digitalWrite(LED_PIN, HIGH); 
    delay(d);
    digitalWrite(LED_PIN, LOW); 
    delay(d);

  // if voltage does not meet threshold
  } else {
    digitalWrite(LED_PIN, LOW);                      // turn off pin
  }


}
