#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Servo myServo;

// PIN DEFINITIONS
int irPin = 2;        // IR sensor output
int servoPin = 9;     // Servo signal
int ledPin = 13;      // LED output
int ldrPin = A0;      // LDR input

void setup() {
  pinMode(irPin, INPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(ldrPin, INPUT);

  myServo.attach(servoPin);

  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("System Ready");
  delay(1000);

  myServo.write(0);  // Servo default at 0 degrees
}

void loop() {
  int irValue = digitalRead(irPin);
  int ldrValue = analogRead(ldrPin);

  // Display LDR value on LCD second line
  lcd.setCursor(0, 1);
  lcd.print("LDR: ");
  lcd.print(ldrValue);
  lcd.print("    ");   // Clear remains

  // IR detection logic
  if (irValue == LOW) { 
    // Object detected
    lcd.setCursor(0, 0);
    lcd.print("Object Detected ");

    myServo.write(90); 
    delay(200);

    // LED blinking when object present
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(200);
  }
  else {
    // No object
    lcd.setCursor(0, 0);
    lcd.print("No Object       ");

    myServo.write(0);
    digitalWrite(ledPin, LOW); // LED OFF
  }

  delay(50);
}