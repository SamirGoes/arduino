#include "LED.h"

LED ledVermelho(11);
LED ledAmarelo(12);
LED ledVerde(13);

LED ledVerdePedestre(10);
LED ledVermelhoPedestre(9);

void setup() {
  Serial.begin(9600);
}

void loop() {
  
  abrirSinal();
  delay(5000);
  fecharSinal();
  delay(5000);

}

void piscarAmarelo(int intervalo, int quantidade)
{
  for (int i = 0; i <= quantidade; i++) {
    ledAmarelo.turnON();
    delay(intervalo);
    ledAmarelo.turnOFF();
    delay(intervalo);
  }
  
}

void abrirSinalPedestre()
{
  ledVermelhoPedestre.turnOFF();
  ledVerdePedestre.turnON();
}

void fecharSinalPedestre()
{
  ledVermelhoPedestre.turnON();
  ledVerdePedestre.turnOFF();
}

void abrirSinal()
{
  fecharSinalPedestre();
  
  ledVerde.turnON();
  ledAmarelo.turnOFF();
  ledVermelho.turnOFF();
}

void fecharSinal()
{
  ledVerde.turnOFF();
  
  piscarAmarelo(500, 5);

  ledVermelho.turnON();

  abrirSinalPedestre();
}
