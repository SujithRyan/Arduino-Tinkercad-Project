// C++ code
//
int sensorValue = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(11, OUTPUT);
}

void loop()
{
  // read the value from the sensor
  sensorValue = map(analogRead(A0), 0, 1023, 0, 360);
  Serial.println(sensorValue);
  analogWrite(11, sensorValue);
  delay(10); // Delay a little bit to improve simulation performance
}