void kepala(int kec){
  int step=EEPROM.read(1001);
  switch(step){
    case 0:gerakKepala(0,0,kec);break;
    case 1:gerakKepala(0,180,kec);break;
    case 2:gerakKepala(20,0,kec);break;
    case 3:gerakKepala(40,180,kec);break;
    case 4:gerakKepala(20,0,kec);break;
    case 5:EEPROM.write(1001,0);break;
  }
}

