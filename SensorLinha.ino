int pinoD = 2; //porta 
int pinoA = A0; //onde o fio m x f vai conectado no módulo do sensor de linha
int pinoAE = A1;
int pinoDE = 6;
int leituraA = 0; // variavel da leitura analogica
int leituraD = 0; // variavel da leitura digital
int limiar = 512; // limiar: definição do valor entre as cores preto e branco. se for menor que 512 considera-se branco,
// caso for maior que 512, considera-se preto.

void setup() {
  Serial.begin(9600); // iniciando a comunicação entre o comp. e arduino.
  pinMode(pinoD, INPUT); // input significa que o pino do sensor ou seja o sensor que comanda o arduino
  pinMode(pinoA, INPUT);
  pinMode(pinoAE, INPUT);
  pinMode(pinoDE, INPUT);
}

void loop() {
  leituraA = analogRead(pinoA); // utilizando função pronta pra fazer a leitura de cada variavel 
  leituraD = digitalRead (pinoD);
  if (leituraD == 1){ //o 1 significa que há linha preta a sua frente
    Serial.print(leituraD); // escreve e o cursor fica na mesma linha
    Serial.println(", Linha detectada!"); // escreve e o cursor pula a linha
  }
  else{ // caso a leitura ainda seja 0
    Serial.print(leituraD);
    Serial.println(", Linha não detectada!");
  }
  if (leituraA > limiar){ //leitura do analogico precisa ser maior que o limiar 
    Serial.print(leituraA);
    Serial.println(", Linha detectada!");
  }
  else{
    Serial.print(leituraA);
    Serial.println(", Linha não detectada!");
  }
  delay(2000); // pausa

  leituraA = analogRead(pinoAE); // utilizando função pronta pra fazer a leitura de cada variavel 
  leituraD = digitalRead (pinoDE);
  if (leituraD == 1){ //o 1 significa que há linha preta a sua frente
    Serial.print(leituraD); // escreve e o cursor fica na mesma linha
    Serial.println(", Linha detectada!"); // escreve e o cursor pula a linha
  }
  else{ // caso a leitura ainda seja 0
    Serial.print(leituraD);
    Serial.println(", Linha não detectada!");
  }
  if (leituraA > limiar){ //leitura do analogico precisa ser maior que o limiar 
    Serial.print(leituraA);
    Serial.println(", Linha detectada!");
  }
  else{
    Serial.print(leituraA);
    Serial.println(", Linha não detectada!");
  }
  delay(2000); // pausa
}
