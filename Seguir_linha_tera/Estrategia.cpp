#include <robo_hardware2.h>
#include "Estrategia.h"

void Estrategia::executar(){
  if (distancia.ler() > 30){
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

void Estrategia::curvaObstaculo(){
  motor.frente();
  delay(1000);
  motor.curvaForteDir();
  delay(2000);
  motor.frente();
  delay(1000);
}

bool Estrategia::buscarLinha(int tempo){
  for (int i = 0; i < tempo; i++){
    motor.frente();
    delay(100);
    refletancia.ler();
    if (!refletancia.bbbb()) {
      return true;
    }
  }
  return false;
}

void Estrategia::desviarObstaculo(){
  motor.tras();
  delay(500);
  motor.curvaForteDir();
  delay(2000);
  motor.frente();
  delay(1000);
  
  bool linhaEncontrada = false

  for (int i = 0; i < 4; i++){
    if (!linhaEncontrada){
      curvaObstaculo();
      linhaEncontrada = buscarLinha(3000);
    } else {
      motor.frente();
      delay(500);
      motor.curvaForteEsq();
      delay(2000);
    }
  }

}