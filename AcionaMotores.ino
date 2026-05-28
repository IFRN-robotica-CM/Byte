#include <Adafruit_TCS34725.h>
#include <CorHardware.h>
#include <CorTcs34.h>
#include <Ultrasonic.h>
#include <cor.h>
#include <pinagem.h>
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

#define DIVISOR_BRANCO_PRETO_DIR 84
#define DIVISOR_BRANCO_PRETO_ESQ 72
#define VELOC_ESQ 70
#define VELOC_DIR 60

float valorSensorDir;
float valorSensorEsq;

void setup(){
	robo.configurar();
}

void loop(){
	valorSensorEsq = robo.lerSensorLinhaEsq(); //Le o valor do sensor esquerdo e coloca dentro da variavel valor_sensor_esq
	valorSensorDir = robo.lerSensorLinhaDir(); //Le o valor do sensor direito e coloca dentro da variavel valor_sensor_dir

	//Identifica se os dois sensores viram branco
	if(valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ){
		robo.acionarMotores(VELOC_DIR, VELOC_ESQ);	//Aciona os dois motores com a mesma velocidade
	}
	//Identifica se o sensor da esquerda viu banco e o da direita viu preto
	else if (valorSensorDir > DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq < DIVISOR_BRANCO_PRETO_ESQ){
		robo.acionarMotores(VELOC_DIR, VELOC_ESQ * -2);	//Aciona o motor esquerdo e mantem o motor direito desligado
	}
	//Identifica se o sensor da direita viu banco e o da esquerda viu preto
	else if ( valorSensorDir < DIVISOR_BRANCO_PRETO_DIR && valorSensorEsq > DIVISOR_BRANCO_PRETO_ESQ){
		robo.acionarMotores(VELOC_DIR * -2, VELOC_ESQ);	//Aciona o motor direito e mantem o motor esquerdo desligado
	}
	else{ //Identifica se os dois sensores viram preto
		robo.acionarMotores(0, 0);
	}

}

