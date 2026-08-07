#include <robo_hardware2.h>
#include "Estrategia.h"

void Estrategia::executar(){
  if (distancia.ler() < 25 || distancia.ler() > 30){
    seguirLinha();
  }
  else{
    desviarObstaculo();
  }
}

void Estrategia::seguirLinha(){
  refletancia.ler();

  // Frente e parar
  if (refletancia.bbbb() || refletancia.bppb() || refletancia.pppp()){
    motor.frente();
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
  motor.tras();
  delay(500);
  motor.curvaForteDir();
  delay(2000);
  motor.frente();
  delay(1000);
  motor.curvaForteEsq();
  delay(2000);
  motor.frente();
  delay(3000);
  motor.curvaForteEsq();
  delay(2000);
  motor.frente();
  delay(1000);
  motor.curvaForteDir();
  delay(2000);
}