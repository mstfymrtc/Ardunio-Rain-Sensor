#include <LiquidCrystal.h>
#include<Servo.h>
Servo motor; // define motor
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // define lcd

const int sensorMin = 0; // sensor maksimum
const int sensorMax = 1024; // sensor minimum

void setup() {
  Serial.begin(9600); // set connection speed 
  lcd.begin(16, 2);
  lcd.print("Hello Master");
  delay(1000);
  lcd.clear();
  motor.attach(9); // attach motor to pin 3


}
void loop() {
  int sensorReading = analogRead(A0);
  int range = map(sensorReading, sensorMin, sensorMax, 0, 2);
  switch (range) {
    case 0:
      lcd.print("Rainy");
      delay(500);
      motor.write(180); //set motor angle to 180 degree
      lcd.clear();
      break;
    case 1:
      lcd.print("No rain");
      delay(500);
      motor.write(0); // set motor angle to initial
      lcd.clear();
      break;
  }
  delay(1);
}
