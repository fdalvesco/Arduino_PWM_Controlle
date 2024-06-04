# Arduino_PWM_Controlle
Atividade da disciplina de Sistemas Embarcados do Curso de Sistemas de Informação

## Introdução à Modulação por Largura de Pulso (PWM)
A Modulação por Largura de Pulso (PWM) é uma técnica empregada para regular a quantidade de energia que chega a um dispositivo eletrônico. Ao modificar a largura dos pulsos em uma série de sinais de controle, a PWM permite ajustar a potência média fornecida ao dispositivo, mantendo constante a frequência do sinal.

## Componentes Necessários
### Arduino Nano
O Arduino Nano é uma placa de desenvolvimento microcontrolada, compacta e completa, baseada no ATmega328. Criada pela plataforma Arduino, ela é ideal para projetos que necessitam de um microcontrolador potente em um espaço reduzido.

### CELL
O processador CELL, oficialmente denominado Cell Broadband Engine Architecture (CBEA), é um microprocessador desenvolvido por Sony, Toshiba e IBM (STI). Lançado em 2005, o CELL foi criado para oferecer alto desempenho em tarefas de computação intensiva, incluindo gráficos, jogos e processamento multimídia.


### L293D
O L293D é um driver de ponte H muito utilizado em projetos eletrônicos para controlar motores DC e motores de passo. Esse circuito integrado possibilita que microcontroladores e outras fontes de controle de baixa potência operem motores de maior potência de forma eficiente e segura.


### Motor
Motores DC (corrente contínua) e motores de passo são amplamente empregados em projetos de eletrônica e robótica. Combinados com controladores como o Arduino Nano e drivers como o L293D, esses motores possibilitam a criação de sistemas de movimento precisos e eficientes.

## Esquemático
![esquematico](https://github.com/fdalvesco/Arduino_PWM_Controlle/assets/101358513/b667168b-6b06-4547-baa2-b87c368c0d2f)

## Código-fonte
    
#include <Arduino.h>
const int button = 4;

int buttonState = LOW;
int lastButtonState = LOW;
int qtdeClick = 0;
void setup() {
  pinMode(button, INPUT_PULLUP);
}
void loop() {
  buttonState = digitalRead(button);
  if(lastButtonState == LOW && buttonState == HIGH){
    qtdeClick++;
    if(qtdeClick == 0) {
      analogWrite(9, 255);
    } else if (qtdeClick == 1) {
      analogWrite(9, 191);
    } else if (qtdeClick == 2) {
      analogWrite(9, 127);
    } else if(qtdeClick == 3) {
      analogWrite(9, 64);
    } else if(qtdeClick == 4) {
      analogWrite(9, 0);
    } else if (qtdeClick == 5){
      analogWrite(9, 255);
      qtdeClick = 0;
    }
  }
  lastButtonState = buttonState;
}

## Funcionamento do projeto
Este projeto usa um botão para ajustar a velocidade de um motor. Cada vez que o botão é pressionado, a velocidade do motor aumenta em 25%. Quando atinge 100%, a velocidade é resetada para 0%.

O código implementa o conceito de debounce para garantir que apenas uma pressão de botão seja registrada, evitando leituras incorretas causadas por oscilações elétricas. Isso é crucial para manter um controle preciso da velocidade do motor.

Ao pressionar o botão, o Arduino lê o estado atual e o compara com o estado anterior após o período de debounce. Se houver uma mudança no estado do botão e o tempo de debounce tiver expirado, o Arduino incrementa a velocidade do motor em 25%. Quando a velocidade chega a 100%, ela é redefinida para 0%, reiniciando o ciclo.

Este projeto ilustra um exemplo simples de controle de motor utilizando PWM e um botão com Arduino.

