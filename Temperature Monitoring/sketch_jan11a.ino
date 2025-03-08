#include <LiquidCrystal.h>
#include <Servo.h> 
 

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);
 

Servo servoMotor;
 

int potPin = A3;     
int tempPin = A2;     
int buttonPin = 2;    
int buzzerPin = 13;   
int ledRed = 4;       
int ledGreen = 5;     
int ledBlue = 6;      
int singleLedPin = A0; 
int Servo_motor = 3;
 
int potValue = 0;
float voltage = 0.0;
float temperature = 0.0;
int tempLow = 20;
int tempHigh = 30;
bool setupCompleted = false; 
bool ledState = false;
unsigned long previous_millis = 0;
const long interval = 100; 
 
void setup() {

  lcd.begin(16, 2);
 

  servoMotor.attach(Servo_motor); 
 
  pinMode(potPin, INPUT);
  pinMode(tempPin, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledBlue, OUTPUT);
  pinMode(singleLedPin, OUTPUT);
 

  Serial.begin(9600);
 
  lcd.setCursor(0, 0);
  lcd.print("Set Temp Range");
}
 
void loop() {
  unsigned long current_second = millis();
 
  if (!setupCompleted) {
  
    potValue = analogRead(potPin);
 
    if (potValue < 200) {
      tempLow = 15;
      tempHigh = 25;
    } else if (potValue < 500) {
      tempLow = 20;
      tempHigh = 30;
    } else {
      tempLow = 30;
      tempHigh = 40;
    }
 

    lcd.setCursor(0, 1);
    lcd.print("Low:");
    lcd.print(tempLow);
    lcd.print(" High:");
    lcd.print(tempHigh);
 
  
    if (digitalRead(buttonPin) == LOW) {
      delay(50);
      if (digitalRead(buttonPin) == LOW) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Setup Done");
        delay(1000);
        lcd.clear();
        setupCompleted = true;
      }
    }
 
    delay(100);
  } else {
    int adcValue = analogRead(tempPin);
    voltage = (adcValue / 1023.0) * 5.0;
    temperature = voltage * 100.0; 
 
    
    lcd.setCursor(0, 0);
    lcd.print("Temp Monitor");
    lcd.setCursor(0, 1);
    lcd.print("Temp: ");
    lcd.print(temperature, 1);
    lcd.print(" C");
 
    
    if (temperature < tempLow) {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, HIGH);
      digitalWrite(singleLedPin, LOW);
      digitalWrite(buzzerPin, LOW); 
      servoMotor.write(180); 
    } else if (temperature <= tempHigh) {
      digitalWrite(ledRed, LOW);
      digitalWrite(ledGreen, HIGH);
      digitalWrite(ledBlue, LOW);
      digitalWrite(singleLedPin, HIGH);
      digitalWrite(buzzerPin, LOW); 
      servoMotor.write(90); 
    } else {
      digitalWrite(ledRed, HIGH);
      digitalWrite(ledGreen, LOW);
      digitalWrite(ledBlue, LOW);
      digitalWrite(buzzerPin, HIGH); 
      servoMotor.write(0); 
 
      
      if (current_second - previous_millis >= interval) {
        previous_millis = current_second;
        ledState = !ledState; 
        digitalWrite(singleLedPin, ledState);
      }
    }
 
    delay(1000);
  }
}