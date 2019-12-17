void ambil(int kec){
  int step;
  while(step!=6){
    step=EEPROM.read(1000);
    switch(step){
      case 0:lenganKanan(0,110,30,90,kec);break;
      case 1:lenganKanan(0,120,80,90,kec);break;
      case 2:lenganKanan(60,110,80,90,kec);break;
      case 3:lenganKanan(60,30,30,90,1);break;
      case 4:lenganKanan(60,20,120,90,1);break;
      case 5:lenganKanan(60,20,120,0,kec);break;
    }
  }
}
void buang(int kec){
  int step;
  while(step!=0){
    step=EEPROM.read(1000);
    switch(step){
      case 6:lenganKanan(0,20,120,0,kec);break;
      case 7:lenganKanan(0,10,120,0,10);break;
      case 8:lenganKanan(100,30,30,90,kec);break;
      case 9:EEPROM.write(1000,0);break;
    }
  }
}

