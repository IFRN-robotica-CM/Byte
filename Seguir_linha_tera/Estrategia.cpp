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
  refletancia.ler();
  if(refletancia.pppp()){
    motor.pare();
  }
  else if (refletancia.bbbb()){
    motor.seguirEmFrente();
  }
}

void Estrategia::desviarObstaculo(){
  
}