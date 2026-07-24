#include "Estrategia.h"


void Estrategia::executar(){
  if (distancia.ler()> 30){
    seguirLinha();
  }
  else{
    desviarObstaculo();
  }
}

void Estrategia::seguirLinha(){

  
  sensor.ler();
  if(sensor.pppp()){
    motor.pare();
  }
  else if (sensor.bbbb()){
    motor.emFrente();
  }
  

}

void Estrategia::desviarObstaculo(){
  
}