// C++ code
//
/*
  Ping))) Sensor

  This sketch reads a PING))) ultrasonic
  rangefinder and returns the distance to the
  closest object in range. To do this, it sends a
  pulse to the sensor to initiate a reading, then
  listens for a pulse to return.  The length of
  the returning pulse is proportional to the
  distance of the object from the sensor.

  The circuit:
   * +V connection of the PING))) attached to +5V
   * GND connection attached to ground
   * SIG connection attached to digital pin 7

  http://www.arduino.cc/en/Tutorial/Ping

  This example code is in the public domain.
*/

#include <Servo.h>

int inches = 0;

int cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

Servo servo_3;

void setup()
{
  Serial.begin(9600);
  servo_3.attach(3, 500, 2500);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
  // measure the ping time in cm
  cm = 0.01723 * readUltrasonicDistance(7, 7);
  // convert to inches by dividing by 2.54
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.println("cm");
  if (cm >= 172) {
    servo_3.write(180);
    digitalWrite(13, HIGH);
    digitalWrite(12, LOW);
    analogWrite(11, 40);
  } else {
    servo_3.write(0);
    digitalWrite(13, LOW);
    digitalWrite(12, HIGH);
    analogWrite(11, 0);
  }
  delay(100); // Wait for 100 millisecond(s)
}