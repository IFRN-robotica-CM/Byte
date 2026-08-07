#include "Refletancia.h"
#include "Motor.h"
#include "Distancia.h"

class Estrategia{
  private:
  Refletancia refletancia;
  Motor motor;

  void desviarObstaculo();
  void seguirLinha();

  public:
  void executar();
};