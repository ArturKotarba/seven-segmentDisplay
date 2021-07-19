int tablicaZegarowa[10] = {0b11111100, 0b01100000, 0b11011010, 0b11110010, 0b01100110, 0b10110110, 0b10111110, 0b11100000, 0b11111110, 0b11110110}; // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

int mieszanina;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 12; i++){
    pinMode(i, OUTPUT);
  } 
}

void loop() { 
  analogWrite(13, 100); 
 // digitalWrite(13, HIGH);
  delay(1000);
 for (int k = 0; k < 10; k++){
    for (int j = 0; j < 8; j++){
     if (tablicaZegarowa[k]& 1<<j){
      digitalWrite(9 - j, HIGH);
     }else{
      digitalWrite(9 - j, LOW);
     }     
     switch(tablicaZegarowa[k]){
     case 0b11111100: //0
     setColor(255, 0, 0); // red , blue, green
     break;
     case 0b01100000: //1
     setColor(0, 255, 0); // red , blue, green
     break;
     case 0b11011010: //2
     setColor(0, 0, 255); // red , blue, green
     break;
     case 0b11110010: //3
     setColor(55, 100, 100); // red , blue, green
     break;
     case 0b01100110: //4
     setColor(30, 200, 20); // red , blue, green
     break;
     case 0b10110110: //5
     setColor(140, 60, 55); // red , blue, green
     break;
     case 0b10111110: //6
     setColor(105, 0, 150); // red , blue, green
     break;
     case 0b11100000: //7
     setColor(10, 40, 150); // red , blue, green
     break;
     case 0b11111110: //8
     setColor(1, 70, 150); // red , blue, green
     break;
     case 0b11110110: //9
     setColor(15, 80, 150); // red , blue, green
     break;
     }
   }
   delay(1500);
  }
}

void setColor(int red, int blue, int green){
  mieszanina = red + blue + green;

  digitalWrite(9, red);
  digitalWrite(10, blue);
  digitalWrite(11, green);
}
