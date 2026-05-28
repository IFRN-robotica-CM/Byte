const int PINO_ENA = 9; // pino A para controlar velocidade
const int PINO_ENB = 3; // pino B para controlar velocidade

const int PINO_IN1 = 7;
const int PINO_IN2 = 6;
const int PINO_IN3 = 5;
const int PINO_IN4 = 4;

int i = 0;
const int TEMPO_ESPERA = 1000;
const int TEMPO_DESAC = 30; // mesmo que TEMPO_RAMPA

void setup() {
  //definir todos os pinos como saída, opu seja, o arduiono irá comandar o seu funcionamento
  pinMode(PINO_ENA, OUTPUT);
  pinMode(PINO_ENB, OUTPUT);
  pinMode(PINO_IN1, OUTPUT);
  pinMode(PINO_IN2, OUTPUT);
  pinMode(PINO_IN3, OUTPUT);
  pinMode(PINO_IN4, OUTPUT);

//iniciar com os motores desligados:
digitalWrite(PINO_IN1, LOW);
digitalWrite(PINO_IN2, LOW);
digitalWrite(PINO_IN3, LOW);
digitalWrite(PINO_IN4, LOW);
digitalWrite(PINO_ENA, LOW);
digitalWrite(PINO_ENB, LOW);
}

void loop() {
  // PARTE DE ANNA -> CONFIGURANDO OS MOTORES
  digitalWrite(PINO_IN1, LOW); // IN1 E IN2 são do motor A, logo, de inicio, motor A vai no sentido anti-horário
  digitalWrite(PINO_IN2, HIGH); 
  digitalWrite(PINO_IN3, HIGH); //IN3 E IN 4 são do motor B, logo, B começa no sentido horário
  digitalWrite(PINO_IN4, LOW);

//ACELERANDO:
for (i = 0; i < 256; i = i + 10){ // i é a variavel que vai nos ajudar a mudar a velocidade
  analogWrite(PINO_ENA, i); //atribuindo o valor de i para o valor analogico do pino referente ao motor
  analogWrite(PINO_ENB, i);
  delay(TEMPO_DESAC); //intervalo para incrementar  a variavel i
  }

//DESACELERANDO:
for (i = 255; i >= 0; i = i - 10){
  analogWrite(PINO_ENA,i);
  analogWrite(PINO_ENB,i);
  delay(TEMPO_DESAC);
  }

delay(TEMPO_ESPERA);

//PARTE DE JULIA -> CONFIGURANDO OS MOTORES 
digitalWrite(PINO_IN1,HIGH);
digitalWrite(PINO_IN2,LOW);
digitalWrite(PINO_IN3,HIGH);
digitalWrite(PINO_IN4,LOW);

for(i = 0; i < 256; i=i+10){
  analogWrite(PINO_ENA,i);
  analogWrite(PINO_ENB,i);
  delay(TEMPO_DESAC);
  }

for(i = 255; i >= 0; i = i - 10){
  analogWrite(PINO_ENA,i);
  analogWrite(PINO_ENB,i);
  delay(TEMPO_DESAC);
  }
  
delay(TEMPO_ESPERA);
}