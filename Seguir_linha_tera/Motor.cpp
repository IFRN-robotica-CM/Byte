#include "Motor.h"
#include <robo_hardware2.h>

// Funções para segruir em frente e para trás
void Motor::frente(){
  robo.acionarMotores(VELOCIDADE_FRENTE, VELOCIDADE_FRENTE);
}
void Motor::tras(){
  robo.acionarMotores(VELOCIDADE_TRAS, VELOCIDADE_TRAS);
}

// Funções para fazer curvas fracas
void Motor::curvaFracaEsq(){
  robo.acionarMotores(VELOCIDADE_CURVA_FRACA_TRAS, VELOCIDADE_CURVA_FRACA_FRENTE);
}
void Motor::curvaFracaDir(){
  robo.acionarMotores(VELOCIDADE_CURVA_FRACA_FRENTE, VELOCIDADE_CURVA_FRACA_TRAS);
}

// Funções para fazer curvas médias
void Motor::curvaMediaEsq(){
  robo.acionarMotores(VELOCIDADE_CURVA_MEDIA_TRAS, VELOCIDADE_CURVA_MEDIA_FRENTE);
}
void Motor::curvaMediaDir(){
  robo.acionarMotores(VELOCIDADE_CURVA_MEDIA_FRENTE, VELOCIDADE_CURVA_MEDIA_TRAS);
}

// Funções para fazer curvas fortes
void Motor::curvaForteEsq(){
  robo.acionarMotores(VELOCIDADE_CURVA_FORTE_TRAS, VELOCIDADE_CURVA_FORTE_FRENTE);
}
void Motor::curvaForteDir(){
  robo.acionarMotores(VELOCIDADE_CURVA_FORTE_FRENTE, VELOCIDADE_CURVA_FORTE_TRAS);
}

// Funções para parar
void Motor::parar(){
  robo.acionarMotores(VELOCIDADE_PARAR, VELOCIDADE_PARAR);
}