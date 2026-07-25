#include "Refletancia.h"
#include "Motor.h"

class Estrategia{
  private:
  Refletancia refletancia;
  Motor motor;

  void desviarObstaculo();
  void seguirLinha();

  public:
  void executar();

};