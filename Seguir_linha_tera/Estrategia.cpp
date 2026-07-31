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

  // Frente e parar
  if (refletancia.bbbb() || refletancia.bppb()){
    motor.frente();
  }
  else if(refletancia.pppp()){
    motor.parar();
  }

  // Curvas fortes
  else if (refletancia.bbbp()){
    motor.curvaForteEsq();
  }
  else if (refletancia.pbbb()){
    motor.curvaForteDir();
  }

  // Curvas médias
  else if (refletancia.bbpp()){
    motor.curvaMediaEsq();
  }
  else if (refletancia.ppbb()){
    motor.curvaMediaDir();
  }

  // Curvas fracas
  else if (refletancia.bbpb()){
    motor.curvaFracaEsq();
  }
  else if (refletancia.bpbb()){
    motor.curvaFracaDir();
  }
}

void Estrategia::desviarObstaculo(){
  
}