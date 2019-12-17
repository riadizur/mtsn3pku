unsigned long lastMillis;
int lenganKanan(int A, int B, int C, int D, int kecepatan){
  int Lpos[4];
  int pos[4]={A,B,C,D};
  if(millis()-lastMillis>=kecepatan){
    int same=0;
    for(int a=0;a<4;a++){
      Lpos[a]=EEPROM.read(100+a);
      if(Lpos[a]<pos[a]){
        if(a==0){
          Lpos[a]=Lpos[a]+5;
        }
        else{
          Lpos[a]=Lpos[a]+1;
        }
      }
      else if(Lpos[a]>pos[a]){
        if(a==0){
          Lpos[a]=Lpos[a]-5;
        }
        else{
          Lpos[a]=Lpos[a]-1;
        }
      }
      else{
        same++;
      }
      EEPROM.write(100+a,Lpos[a]);
//      Serial.print(String(Lpos[a])+"\t");
    }
    d1.write(Lpos[0]);
    d2.write(Lpos[1]);
    d3.write(Lpos[2]);
    d4.write(Lpos[3]);
    lastMillis=millis();
    if(same==4){
      EEPROM.write(1000,EEPROM.read(1000)+1);
    }
//    Serial.println();
  }
}
