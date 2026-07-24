#include <robo_hardware2.h> 
#include <Servo.h>

//-----PINOS PARA LIGAR MOTORES-----//
//Motor1:
//pino1 PWM_RODA_DIREITA 	6
//pino2 SENTIDO_RODA_DIREITA 	7
//
//Motor2:
//pino1 PWM_RODA_ESQUERDA 	5
//pino2 SENTIDO_RODA_ESQUERDA	4
//-----PINOS PARA LIGAR MOTORES-----//

//-----PINOS PARA SENSORES REFLETANCIA-----//
//SENSOR_LINHA_MAIS_ESQUERDO	    A3
//SENSOR_LINHA_ESQUERDO			    A2
//SENSOR_LINHA_DIREITO			    A1	
//SENSOR_LINHA_MAIS_DIREITO			A0	
//-----PINOS PARA SENSORES REFLETANCIA-----//

#define DBP_ME 50
#define DBP_E 35
#define DBP_D 45
#define DBP_MD 50

float valorSensorDir;
float valorSensorEsq;
float valorSensorMaisDir;
float valorSensorMaisEsq;

// Identifica quando todos os sensores não detectarem linha
bool bbbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando apenas o mais direito detectar linha
bool bbbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando apenas o direito detectar linha
bool bbpb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando o mais direito e o direito detectarem linha
bool bbpp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando apenas o esquerdo detectar linha
bool bpbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando o esquerdo e o mais direito detectarem linha
bool bpbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando o esquerdo e o direito detectarem linha
bool bppb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando quando apenas o mais esquerdo não detectar linha
bool bppp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando apenas apenas o mais esquerdo detectar linha
bool pbbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando o mais esquerdo e o mais direito detectarem linha
bool pbbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando o mais esquerdo e o direito detectarem linha
bool pbpb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando apenas o esquerdo não detectar linha
bool pbpp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando o esquerdo e o mais esquerdo detectarem linha
bool ppbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando apenas o direito não detectar linha
bool ppbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
// Identifica quando apenas o mais direito não detectar linha
bool pppb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
// Identifica quando todos detectarem linha
bool pppp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}

void lerSensores() {
  valorSensorMaisEsq = robo.lerSensorLinhaMaisEsq(); //Lê o valor do sensor mais esquerdo e coloca dentro da variável lerSensorLinhaMaisEsq
  valorSensorEsq = robo.lerSensorLinhaEsq();         //Lê o valor do sensor esquerdo e coloca dentro da variavel lerSensorLinhaEsq
  valorSensorDir = robo.lerSensorLinhaDir();         //Lê o valor do sensor direito e coloca dentro da variavel lerSensorLinhaDir
	valorSensorMaisDir = robo.lerSensorLinhaMaisDir(); //Lê o valor do sensor mais direito e coloca dentro da variável lerSensorLinhaMaisDir
}

void printRefletancia() {
  lerSensores();

  Serial.print("Sensores refletancia: +esq: ");
	Serial.print(valorSensorMaisEsq);   //Imprime o valor do sensor mais esquerdo pela porta serial
	Serial.print("; esq: ");
	Serial.print(valorSensorEsq);       //Imprime o valor do sensor esquerdo pela porta serial
	Serial.print("; dir: ");
	Serial.print(valorSensorDir);       //Imprime o valor do sensor direito pela porta serial
	Serial.print("; +dir: ");
	Serial.println(valorSensorMaisDir); //Imprime o valor do sensor mais direito pela porta serial

  delay(1000);
}

void setup(){
  Serial.begin(9600);
	robo.configurar();
}

void loop(){
	lerSensores();

  // printRefletancia();
  // delay(1000);
  
  
  // Seguir em frente
  if(bbbb()){
    robo.acionarMotores(75,-75);
  }
  else if(pppp()){
    robo.acionarMotores(0,0);
  }

  // Curvas fortes
  else if(bbbp()){
    robo.acionarMotores(-75,-100);
  }
  else if(pbbb()){
    robo.acionarMotores(100,75);
  }
  
  // Curvas medias
  else if(bbpp()){
    robo.acionarMotores(-50,-75);
  }
  else if(ppbb()){
    robo.acionarMotores(75,50);
  }

  // Curvas fracas
  else if(bbpb()){
    robo.acionarMotores(-10,-75);
  }
  else if(bpbb()){
    robo.acionarMotores(75,10);
  }
  
}
