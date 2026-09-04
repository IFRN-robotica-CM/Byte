#include "Distancia.h"
#include <robo_hardware2.h>

int Distancia::ler(){
  ValorDistanciaLaser = robo.lerSensorLaserFrontal();
  return ValorDistanciaLaser;
}

void Distancia::print(){
  ler();

  Serial.print("Valor Distância Laser em mm: ");
  Serial.println(ValorDistanciaLaser);
  delay(500);
}