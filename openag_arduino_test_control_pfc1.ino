/*
PFC1 Hardware Test Sketch for Arduino Mega2560 with both daugherboards
Written by Joseph Juhnke
License: GPL 3.0
Written without cleverness so it's easy to mod!
*/

// Declare Pins
int heatPin = 6;
int h2oCirculationPin = 7;
int lightsPin = 8;
int humidityPin = 9;
int ventFanPin = 14;
int circFanPin = 15;


void setup() 
{
//   Initialize Pins
  pinMode(heatPin, OUTPUT);
  pinMode(h2oCirculationPin, OUTPUT);
  pinMode(lightsPin, OUTPUT);
  pinMode(humidityPin, OUTPUT);
  pinMode(ventFanPin, OUTPUT);
  pinMode(circFanPin, OUTPUT);

//   Initialize Serial
  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready
  Serial.println("Enter Number 0 to 5 or 'x' to clear");
  
//   Set all pins hot
  digitalWrite(heatPin, HIGH);
  digitalWrite(h2oCirculationPin, HIGH);
  digitalWrite(lightsPin, HIGH);
  digitalWrite(humidityPin, HIGH);
  digitalWrite(ventFanPin, HIGH);  
  digitalWrite(circFanPin, HIGH);
  
}

void loop() 
{
  if (Serial.available())
  {
    char ch = Serial.read();
    Serial.println(ch);

    switch(ch) {
    case 0:
      digitalWrite(heatPin, LOW);
      Serial.println("Heater ON!");
      break;
    case 1:
      _serial_port = &Serial2;
      digitalWrite(h2oCirculationPin, LOW);
      Serial.println("Circulation Pump ON!");
      break;
    case 2:
      _serial_port = &Serial3;
      digitalWrite(lightsPin, LOW);
      Serial.println("Grow Lights ON!");
      break;
    case 3:
      _serial_port = &Serial3;
      digitalWrite(humidityPin, LOW);
      Serial.println("Humidifier ON!");
      break;
    case 4:
      _serial_port = &Serial3;
      digitalWrite(ventFanPin, LOW);
      Serial.println("Vent Fan ON!");
      break;
    case 5:
      _serial_port = &Serial3;
      digitalWrite(circFanPin, LOW);
      Serial.println("Circulation Fan ON!");
      break;
    case x:
      _serial_port = &Serial3;
      digitalWrite(heatPin, HIGH);
      digitalWrite(h2oCirculationPin, HIGH);
      digitalWrite(lightsPin, HIGH);
      digitalWrite(humidityPin, HIGH);
      digitalWrite(ventFanPin, HIGH);  
      digitalWrite(circFanPin, HIGH);
      Serial.println("EVERYTHING OFF!");
      break;
    }
  }
}
