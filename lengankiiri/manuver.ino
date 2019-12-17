int moKiriA1=0,moKiriA2=0,moKiriB=0,moKananA1=0,moKananA2=0,moKananB=0,kec=0;
void setupMotor(int moKiA1,int moKiA2, int moKiB, int moKaA1,int moKaA2,int moKaB,int kece){
  moKiriA1=moKiA1;
  moKiriA2=moKiA2;
  moKiriB=moKiB;
  moKananA1=moKaA1;
  moKananA2=moKaA2;
  moKananB=moKaB;
  kec=kece;
  pinMode(moKiriA1,OUTPUT);
  pinMode(moKiriA2,OUTPUT);
  pinMode(moKiriB,OUTPUT);
  pinMode(moKananA1,OUTPUT);
  pinMode(moKananA2,OUTPUT);
  pinMode(moKananB,OUTPUT);
}
boolean start=true;
int count=0;
void motor(bool state1,int speed1, bool state2, int speed2){
  if(state1==0){
    digitalWrite(moKiriA1, HIGH);
    digitalWrite(moKiriA2, LOW);
  }
  else{
    digitalWrite(moKiriA1, LOW);
    digitalWrite(moKiriA2, HIGH);
  }
  analogWrite(moKiriB,speed1);
  if(state2==0){
    digitalWrite(moKananA1, HIGH);
    digitalWrite(moKananA2, LOW);
  }
  else{
    digitalWrite(moKananA1, LOW);
    digitalWrite(moKananA2, HIGH);
  }
  analogWrite(moKananB,speed2);
}
void maju(){
  if(start){
    int kece=255-count;
    motor(1,kece,1,kece);
    delayMicroseconds(500);
    if(kece<=kec){
      start=false;
      count=0;
    }
    count++;
  }else{
    motor(1,kec,1,kec);
  }
}
void mundur(){
  if(start){
    int kece=255-count;
    motor(0,kece,0,kece);
    delayMicroseconds(500);
    if(kece<=kec){
      start=false;
      count=0;
    }
    count++;
  }else{
    motor(0,kec,0,kec);
  }
}
void belokKiri(){
  motor(1,kec*2,0,kec*2);
}
void belokKanan(){  
  motor(0,kec*2,1,kec*2);
}
void berhenti(){  
  motor(0,0,0,0);
  start=true;
}
