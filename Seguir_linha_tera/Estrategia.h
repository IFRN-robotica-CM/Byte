#include "Sensor.h"
#include "Motor.h"

class Estrategia{

  private:
  Sensor sensor;
  Motor motor;

  void desviarObstaculo();
  void seguirLinha();

  public:
  void executar();

};