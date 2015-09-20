#include "TimerOne.h"

int seg,minute,hour;
void setup(){
  pinMode(13, OUTPUT);
  Timer1.initialize();         // Inicializa o  Timer1 e configura para um período de 0,5 segundos
  Timer1.attachInterrupt(callback);  // Configura a função callback() como a função para ser chamada a cada interrupção do Timer1
  Serial.begin(9600);
}

void timerInit(){
  seg=0;
  minute=0;
  hour=0;
}

void callback(){
//  digitalWrite(13, digitalRead(13) ^ 1);
  seg++;
}

void loop(){
  // Seu código vai aqui...
  if(seg>=60) {
  seg = 0;
  minute++;
  }
  if(minute>=60) {
  minute = 0;
  hour++;
  }
  if(hour>=24) {
  hour=0;
  minute=0;
  }
  Serial.print(hour);
  Serial.print(":");
  Serial.print(minute);
  Serial.print(":");
  Serial.println(seg);
  delay(1000);
}
