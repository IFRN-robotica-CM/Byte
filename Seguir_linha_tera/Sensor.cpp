#include "Sensor.h"

void Sensor::ler(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //Lê o valor do sensor mais esquerdo e coloca dentro da variável lerSensorLinhaMaisEsq
  valorSensorEsq = robo.lerSensorLinhaEsq();         //Lê o valor do sensor esquerdo e coloca dentro da variavel lerSensorLinhaEsq
  valorSensorDir = robo.lerSensorLinhaDir();         //Lê o valor do sensor direito e coloca dentro da variavel lerSensorLinhaDir
	valorSensorMaisDir = robo.lerSensorLinhaMaisDir(); //Lê o valor do sensor mais direito e coloca dentro da variável lerSensorLinhaMaisDir
}