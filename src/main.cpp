#include <Arduino.h>

int clickTimes=0; //Definição de variável de controle de estado
const int button = 2; // Inserção do pino do botão
int estado[5] = {0,64,127,191,255}; // Definição dos valores de estado

void setup() {
  pinMode(button,INPUT); // Setando o pin mode como INPUT
}
void loop() {
  if(digitalRead(button) == HIGH){
    analogWrite(9, estado[clickTimes]); //Define o estado para o motor
    clickTimes++; //Define o próximo estado
  }
  if(clickTimes == 5){
    clickTimes = 0; // Reseta os estados
  }
}
