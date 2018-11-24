#include<Servo.h>
Servo motor; // define motor
const int sensorMin = 0; // set sensor min value
const int sensorMax = 1024; // set sensor max value
void setup() {
  Serial.begin(9600); 

  motor.attach(3); // attach motor to pin 3
}
void loop() {
  int sensorReading = analogRead(A0); //read value from sensor
  int range = map(sensorReading, sensorMin, sensorMax, 0, 2); //map value to range
  switch (range) {
    case 0:

      motor.write(180); //set motor angle to 180 degree
      delay(300);
      break;

    case 1:

      motor.write(0); // set motor angle to initial
      delay(300);


      break;

  }
}
