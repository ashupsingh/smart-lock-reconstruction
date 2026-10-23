// Reconstructed 2026-10-23. New pin map; not the lost original firmware.
#include <Arduino.h>
#if defined(ESP32)
const int SENSOR=34, INPUT_A=27, INPUT_B=14, OUT=26, AUX=25;
const int ADC_MAXIMUM=4095;
#else
const int SENSOR=A0, INPUT_A=2, INPUT_B=3, OUT=8, AUX=9;
const int ADC_MAXIMUM=1023;
#endif
// OUT/AUX drive a transistor/module input, never an inductive load directly.
// Default OFF = LOW. Use a compatible active-HIGH driver for this reconstruction.

#include <Adafruit_Fingerprint.h>
#if defined(ESP32)
HardwareSerial sensorSerial(2);
#else
#include <SoftwareSerial.h>
SoftwareSerial sensorSerial(10,11);
#endif
Adafruit_Fingerprint finger(&sensorSerial);bool sensorReady=false;unsigned long lastScan=0;
void startSensor(){
#if defined(ESP32)
sensorSerial.begin(57600,SERIAL_8N1,16,17);
#endif
finger.begin(57600);sensorReady=finger.verifyPassword();
}
int matchFinger(){if(finger.getImage()!=FINGERPRINT_OK)return -1;if(finger.image2Tz()!=FINGERPRINT_OK)return -1;if(finger.fingerFastSearch()!=FINGERPRINT_OK)return -1;return finger.fingerID;}

bool unlocked=false,held=false;unsigned long unlockedAt=0;
void setup(){Serial.begin(115200);pinMode(OUT,OUTPUT);digitalWrite(OUT,LOW);startSensor();}
void loop(){unsigned long now=millis();if(unlocked&&now-unlockedAt>=3000){unlocked=false;digitalWrite(OUT,LOW);}
 if(!sensorReady||now-lastScan<200)return;lastScan=now;
 uint8_t capture=finger.getImage();if(capture==FINGERPRINT_NOFINGER){held=false;return;}if(capture!=FINGERPRINT_OK)return;
 if(held)return;held=true;
 if(finger.image2Tz()!=FINGERPRINT_OK||finger.fingerFastSearch()!=FINGERPRINT_OK)return;
 if(finger.fingerID==1&&!unlocked){unlocked=true;unlockedAt=now;digitalWrite(OUT,HIGH);}
}
