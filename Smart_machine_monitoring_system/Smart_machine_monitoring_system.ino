#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <MFRC522.h>

// -------- RFID --------
#define SS_PIN 10
#define RST_PIN 9
MFRC522 rfid(SS_PIN, RST_PIN);

// -------- RTC --------
RTC_DS3231 rtc;

// -------- Vibration --------
int vibrationPin = 2;
bool machineState = false; // OFF initially

void setup() {
  Serial.begin(9600);

  // RFID
  SPI.begin();
  rfid.PCD_Init();

  // RTC
  if (!rtc.begin()) {
    Serial.println("RTC not found!");
    while (1);
  }

  // Vibration
  pinMode(vibrationPin, INPUT);

  Serial.println("System Ready...");
}

void loop() {
  DateTime now = rtc.now();

  // -------- VIBRATION CHECK --------
  int vibration = digitalRead(vibrationPin);

  if (vibration == HIGH && machineState == false) {
    machineState = true;
    Serial.print("Machine STARTED at: ");
    printTime(now);
    delay(1000);
  }

  if (vibration == LOW && machineState == true) {
    machineState = false;
    Serial.print("Machine STOPPED at: ");
    printTime(now);
    delay(1000);
  }

  // -------- RFID CHECK --------
  if (rfid.PICC_IsNewCardPresent() && rfid.PICC_ReadCardSerial()) {
    Serial.print("Worker ID: ");
    for (byte i = 0; i < rfid.uid.size; i++) {
      Serial.print(rfid.uid.uidByte[i], HEX);
      Serial.print(" ");
    }
    Serial.print(" at time: ");
    printTime(now);

    rfid.PICC_HaltA();
  }

  delay(200);
}

// -------- FUNCTION TO PRINT TIME --------
void printTime(DateTime t) {
  Serial.print(t.hour());
  Serial.print(":");
  Serial.print(t.minute());
  Serial.print(":");
  Serial.println(t.second());
}