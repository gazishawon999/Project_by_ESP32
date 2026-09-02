#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad_I2C.h>
#include <ESP32Servo.h>

// I2C Addresses (সাধারণত 0x27 বা 0x3F হয় LCD-র জন্য)
LiquidCrystal_I2C lcd(0x27, 16, 2);
#define KEYPAD_ADDR 0x20 // Keypad I2C Module Address

// Keypad Configuration
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {0, 1, 2, 3}; 
byte colPins[COLS] = {4, 5, 6, 7};
Keypad_I2C keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS, KEYPAD_ADDR);

// Pin Definitions
#define IR_START 32
#define IR_END 33
#define LASER 34
#define TRIG 25
#define ECHO 26
#define BUZZER 27
#define ROOM_LED 2
#define GATE_SERVO_PIN 13
#define DOOR_SERVO_PIN 12

Servo gateServo, doorServo;

// Variables & Settings
float distanceBetweenIR = 15.0; // দুই IR সেন্সরের দূরত্ব (cm)
float speedLimit = 40.0;        // আপনার সেট করা স্পিড লিমিট
String correctPin = "1234";     // ডিফল্ট ডোর পিন
String inputPin = "";
int wrongCount = 0;
unsigned long startTime, endTime;

void setup() {
  Wire.begin();
  keypad.begin();
  lcd.init();
  lcd.backlight();
  
  pinMode(IR_START, INPUT);
  pinMode(IR_END, INPUT);
  pinMode(LASER, INPUT);
  pinMode(BUZZER, OUTPUT);
  pinMode(ROOM_LED, OUTPUT);
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  gateServo.attach(GATE_SERVO_PIN);
  doorServo.attach(DOOR_SERVO_PIN);
  
  // Initial position
  gateServo.write(0);
  doorServo.write(0);
  
  lcd.print("System Active");
  delay(2000);
  lcd.clear();
}

// Function to trigger alarms with messages
void runAlarm(String msg, int timeMs) {
  lcd.clear();
  lcd.print("!! WARNING !!");
  lcd.setCursor(0, 1);
  lcd.print(msg);
  digitalWrite(BUZZER, HIGH);
  delay(timeMs);
  digitalWrite(BUZZER, LOW);
  lcd.clear();
}

void loop() {
  // --- PRIORITY 1: LASER SECURITY (Rear Wall) ---
  if (digitalRead(LASER) == LOW) { // যদি লেজার বিম ব্রেক হয়
    runAlarm("INTRUDER DETECT!", 2000);
    return; // লেজারের অ্যালার্ম বাজলে নিচের বাকি লজিকগুলো স্কিপ হবে
  }

  // --- PRIORITY 2: CAR SPEED CHECK ---
  if (digitalRead(IR_START) == LOW) {
    startTime = millis();
    while (digitalRead(IR_END) == HIGH) {
       if (digitalRead(LASER) == LOW) return; // লেজার চেক ইনসাইড লুপ
    }
    endTime = millis();
    
    float timeSec = (endTime - startTime) / 1000.0;
    float speed = (distanceBetweenIR / 100.0) / timeSec; // m/s
    float speedKmH = speed * 3.6; // Speed in km/h

    lcd.setCursor(0,0);
    lcd.print("Speed: "); lcd.print(speedKmH);
    
    if (speedKmH > speedLimit) {
      runAlarm("OVER SPEED!", 3000);
    } else {
      lcd.setCursor(0,1);
      lcd.print("Welcome! Gate Open");
      gateServo.write(90);
      delay(5000);
      gateServo.write(0);
      lcd.clear();
    }
  }

  // --- PRIORITY 3: KEYPAD DOOR LOCK ---
  char key = keypad.getKey();
  if (key) {
    if (key == '#') { // '#' চাপলে পিন ভেরিফাই হবে
      if (inputPin == correctPin) {
        lcd.clear(); lcd.print("Pin Correct!");
        doorServo.write(90);
        delay(4000);
        doorServo.write(0);
        wrongCount = 0;
      } else {
        wrongCount++;
        lcd.clear(); lcd.print("Incorrect Pin!");
        if (wrongCount >= 3) {
          runAlarm("UNAUTHORIZED!", 5000);
          wrongCount = 0;
        }
      }
      inputPin = "";
    } else if (key == '*') { // '*' দিয়ে ক্লিয়ার করা যাবে
      inputPin = "";
    } else {
      inputPin += key;
      lcd.setCursor(0,1);
      lcd.print("Pin: ****"); 
    }
  }

  // --- PRIORITY 4: ROOM LIGHTING ---
  digitalWrite(TRIG, LOW); delayMicroseconds(2);
  digitalWrite(TRIG, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  long duration = pulseIn(ECHO, HIGH);
  int distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 40) { // ৪০ সেমি এর ভেতর কাউকে পেলে
    digitalWrite(ROOM_LED, HIGH);
  } else {
    digitalWrite(ROOM_LED, LOW);
  }
}
