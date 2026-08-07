#include "Distancia.h"
#include <robo_hardware2.h>

void Distancia::ler(){
  ValorDistanciaLaser = robo.lerSensorLaserFrontal();
}

void Distancia::print(){
  ler();

  Serial.print("Valor Distância Laser em mm: ");
  Serial.println(ValorDistanciaLaser);
}