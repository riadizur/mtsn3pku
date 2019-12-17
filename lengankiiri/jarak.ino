float HCSR04(const int echo, const int trigger){
  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  float distance,duration;
  digitalWrite(trigger,LOW);
  delayMicroseconds(2);
  digitalWrite(trigger,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger,LOW);
  duration=pulseIn(echo,HIGH);
  distance=duration*0.034/2;
  return distance;
}
