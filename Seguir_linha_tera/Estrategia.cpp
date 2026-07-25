#include "Estrategia.h"

void Estrategia::executar(){
  // if (distancia.ler()> 30){
    seguirLinha();
  // }
  // else{
  //   desviarObstaculo();
  // }
}

void Estrategia::seguirLinha(){
  refletancia.ler();
  if(refletancia.pppp()){
    motor.parar();
  }
  else if (refletancia.bbbb()){
    motor.frente();
  }
}

void Estrategia::desviarObstaculo(){
  
}