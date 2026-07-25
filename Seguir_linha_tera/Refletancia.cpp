#include "Refletancia.h"
#include <robo_hardware2.h>

void Refletancia::ler(){
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //Lê o valor do sensor mais esquerdo e coloca dentro da variável lerSensorLinhaMaisEsq
  valorSensorEsq = robo.lerSensorLinhaEsq();         //Lê o valor do sensor esquerdo e coloca dentro da variavel lerSensorLinhaEsq
  valorSensorDir = robo.lerSensorLinhaDir();         //Lê o valor do sensor direito e coloca dentro da variavel lerSensorLinhaDir
	valorSensorMaisDir = robo.lerSensorLinhaMaisDir(); //Lê o valor do sensor mais direito e coloca dentro da variável lerSensorLinhaMaisDir
}

void Refletancia::print(){
  ler();

  Serial.print("Sensores refletancia: +esq: ");
	Serial.print(valorSensorMaisEsq);   //Imprime o valor do sensor mais esquerdo pela porta serial
	Serial.print("; esq: ");
	Serial.print(valorSensorEsq);       //Imprime o valor do sensor esquerdo pela porta serial
	Serial.print("; dir: ");
	Serial.print(valorSensorDir);       //Imprime o valor do sensor direito pela porta serial
	Serial.print("; +dir: ");
	Serial.println(valorSensorMaisDir);
}