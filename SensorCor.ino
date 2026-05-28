#include <Wire.h> // importando a biblioteca de comunicação
#include "Adafruit_TCS34725.h" // importando a biblioteca do sensor 
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X); //criando o objeto da classe, ou seja, criando o sensor.
// dando um nome ao sensor, criando uma classe

void setup() {
  Serial.begin(9600);
  tcs.begin();

}

void loop() {
  uint16_t r, g, b, c;
  if (tcs.begin()){
    tcs.getRawData(&r, &g, &b, &c); //PERCENTUAIS DAS CORES E CLARIDADE
  }
  if (r > b && r > g){
    Serial.println("VERMELHO"); Serial.print("\t"); Serial.print(r); Serial.print("\t"); Serial.print(g); Serial.print("\t"); Serial.print(b);
  }
  else if (g > r && g > b){
  Serial.println("VERDE"); Serial.print("\t"); Serial.print(r); Serial.print("\t"); Serial.print(g); Serial.print("\t"); Serial.print(b);
  }
  else if (b > r && b > g){
  Serial.println("AZUL"); Serial.print("\t"); Serial.print(r); Serial.print("\t"); Serial.print(g); Serial.print("\t"); Serial.print(b);
  }
  delay(1000);
}
