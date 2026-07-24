#include "Estrategia.h"


void Estrategia::executar(){
  seguirLinha();
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