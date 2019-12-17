#include <Servo.h>
#include <EEPROM.h>
Servo d1;
Servo d2;
Servo d3;
Servo d4;
Servo l1;
Servo l2;
#define semprot A5
void setup() {
  pinMode(semprot,OUTPUT);
  Serial.begin(9600);
  d1.attach(9);
  d2.attach(6);
  d3.attach(5);
  d4.attach(3);
  l1.attach(11);
  l2.attach(10);
  d1.write(90);
  d2.write(30);
  d3.write(30);
  d4.write(180);
  l1.write(0);
  l2.write(90);
  EEPROM.write(100,90);
  EEPROM.write(101,30);
  EEPROM.write(102,30);
  EEPROM.write(103,180);
  EEPROM.write(104,0);
  EEPROM.write(105,90);
  EEPROM.write(1000,0);
  EEPROM.write(1001,0);
  delay(1000);
}
unsigned long lastTime=0;
int count=0;
void loop() {
//  ambil(3);
//  delay(2000);
//  buang(5);
//  delay(2000);
  kepala(40);
}
