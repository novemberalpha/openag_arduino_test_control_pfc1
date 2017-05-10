/*
Adafruit Arduino - Lesson 05. Serial Monitor
*/

int heatPin = 6;
int h2oCirculationPin = 7;
int lightsPin = 8;
int humidityPin = 9;
int ventFanPin = 14;
int circFanPin = 15;


void setup() 
{
  pinMode(heatPin, OUTPUT);
  pinMode(h2oCirculationPin, OUTPUT);
  pinMode(lightsPin, OUTPUT);
  pinMode(humidityPin, OUTPUT);
  pinMode(ventFanPin, OUTPUT);
  pinMode(circFanPin, OUTPUT);

  Serial.begin(9600);
  while (! Serial); // Wait untilSerial is ready
  Serial.println("Enter Number 0 to 5 or 'x' to clear");
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
    if (ch == '0')
    {
      digitalWrite(heatPin, LOW);
      Serial.println("Heater ON!");
    }
    if (ch == '1')
    {
      digitalWrite(h2oCirculationPin, LOW);
      Serial.println("Circulation Pump ON!");
    }
    if (ch == '2')
    {
      digitalWrite(lightsPin, LOW);
      Serial.println("Grow Lights ON!");
    }
    if (ch == '3')
    {
      digitalWrite(humidityPin, LOW);
      Serial.println("Humidifier ON!");
    }
    if (ch == '4')
    {
      digitalWrite(ventFanPin, LOW);
      Serial.println("Vent Fan ON!");
    }
    if (ch == '5')
    {
      digitalWrite(circFanPin, LOW);
      Serial.println("Circulation Fan ON!");
    }
    
    if (ch == 'x')
    {
      digitalWrite(heatPin, HIGH);
      digitalWrite(h2oCirculationPin, HIGH);
      digitalWrite(lightsPin, HIGH);
      digitalWrite(humidityPin, HIGH);
      digitalWrite(ventFanPin, HIGH);  
      digitalWrite(circFanPin, HIGH);
      Serial.println("EVERYTHING OFF!");
    }
  }
}
