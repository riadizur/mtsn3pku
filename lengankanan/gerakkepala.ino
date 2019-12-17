unsigned long lastMillis1;
int gerakKepala(int A, int B, int kecepatan){
  int Lpos[2];
  int pos[2]={A,B};
  if(millis()-lastMillis1>=kecepatan){
    lastMillis1=millis();
    int same=0;
    for(int a=0;a<2;a++){
      Lpos[a]=EEPROM.read(104+a);
      if(Lpos[a]<pos[a]){
        Lpos[a]=Lpos[a]+1;
      }
      else if(Lpos[a]>pos[a]){
        Lpos[a]=Lpos[a]-1;
      }
      else{
        same++;
      }
      EEPROM.write(104+a,Lpos[a]);
      Serial.print(String(Lpos[a])+"\t");
    }
    l1.write(Lpos[0]);
    l2.write(Lpos[1]);
    if(same==2){
      EEPROM.write(1001,EEPROM.read(1001)+1);
    }
//    Serial.println();
  }
}

