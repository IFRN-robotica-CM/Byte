#include "Motor.h"
#include <robo_hardware2.h>


void Motor::seguirEmFrente(){
  robo.acionarMotores(VELOCIDADE_FRENTE,-VELOCIDADE_FRENTE);
}

void Motor::parar(){
  robo.acionarMotores(0,0);
}