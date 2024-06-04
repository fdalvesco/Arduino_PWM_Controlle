
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