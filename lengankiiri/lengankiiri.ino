#include <Servo.h>
#include <EEPROM.h>
Servo d1;
Servo d2;
Servo d3;
Servo d4;
void setup() {
  setupMotor(A0,8,10,12,A1,11,75); //parameter: moPin A, moPinB, Kecepatan
  Serial.begin(9600);
  d1.attach(9);
  d2.attach(6);
  d3.attach(5);
  d4.attach(3);
  d1.write(90);
  d2.write(30);
  d3.write(30);
  d4.write(0);
  EEPROM.write(100,90);
  EEPROM.write(101,30);
  EEPROM.write(102,30);
  EEPROM.write(103,0);
  EEPROM.write(1000,0);
  delay(1000);
}
boolean kanan=false,kiri=false;
unsigned long lastTime=0;
void loop() {
  float jarak=HCSR04(4,7);
  Serial.println(jarak);
  if(jarak<25){
    mundur();
    delay(200);
    belokKiri();
    delay(100);
    if(HCSR04(4,7)<25){
      kanan=true;
    }
    else{
      kiri=true;
    }
  }
  else{
    kanan=false;
    kiri=false;
  }
  if(kanan or kiri){
    mundur();
    delay(100);
    while(HCSR04(4,7)<40){
      if(kanan){
        belokKanan();
        delay(100);
      }
      else if(kiri){
        belokKiri();
        delay(100);
      }
    }
  }
  else{
    maju();
  }
}
