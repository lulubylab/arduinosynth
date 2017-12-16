int WS = 2;
int BCK = 3;
int DATAI = 4;
int SF1 = 5;
int stereo_ct = 0;
int sine_index = 0;
uint8_t  sine_wave[256] = {

};
int offset=0;

void setup(){
  pinMode(WS,OUTPUT);
  pinMode(BCK,OUTPUT);
  pinMode(DATAI,OUTPUT);
  pinMode(SF1,OUTPUT);
  digitalWrite(SF1,HIGH);
  Serial.begin(115200);
  for ( int i = 0; i < 255; i ++ ){
  sine_wave[i]=i;

}
}

void loop(){
  if (stereo_ct == 1){
    digitalWrite(BCK,HIGH);
    digitalWrite(WS,HIGH);

  }
  if (stereo_ct == 2){
    digitalWrite(BCK,HIGH);
    digitalWrite(WS,LOW);
    sine_index++;
    stereo_ct=0;
  }
  if (sine_index == 255){
    
  sine_index=0;
  }
  writeByte(sine_wave[sine_index]);
  if (offset==10)
  offset=0;

  stereo_ct++;
  offset++;
  if (offset== 1000)
  offset=0;

}

void writeByte(uint8_t byte){
  int bit = 0;

  while (bit < 8){
    delayMicroseconds(offset/100);
    digitalWrite(BCK,LOW);
    switch (bit){
      case 0:
      digitalWrite(DATAI, byte & (1<<0));
      break;
      case 1:
      digitalWrite(DATAI, byte & (1<<1));
      break;
      case 2:
      digitalWrite(DATAI, byte & (1<<2));
      break;
      case 3:
      digitalWrite(DATAI, byte & (1<<3));
      break;
      case 4:
      digitalWrite(DATAI, byte & (1<<4));
      break;
      case 5:
      digitalWrite(DATAI, byte & (1<<5));
      break;
      case 6:
      digitalWrite(DATAI, byte & (1<<6));
      break;
      case 7:
      digitalWrite(DATAI, byte & (1<<7));
      break;
    }
  digitalWrite(BCK,HIGH);
  bit++;
  }
  
}
    
  



