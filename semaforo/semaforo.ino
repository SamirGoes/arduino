#include "LED.h"

LED ledVermelho(11);
LED ledAmarelo(12);
LED ledVerde(13);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  abrirSinal();
  delay(5000);
  fecharSinal();
  delay(5000);

}

void abrirSinal()
{
  ledVerde.turnON();
  ledAmarelo.turnOFF();
  ledVermelho.turnOFF();
}

void fecharSinal()
{
  ledVerde.turnOFF();
  
  for (int i = 0; i <= 10; i++) {
    ledAmarelo.turnON();
    delay(500);
    ledAmarelo.turnOFF();
    delay(500);
  }
  
  ledVermelho.turnON();
}
