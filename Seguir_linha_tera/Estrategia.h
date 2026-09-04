#include "Refletancia.h"
#include "Motor.h"
#include "Distancia.h"

class Estrategia{
  private:
  Refletancia refletancia;
  Motor motor;
  Distancia distancia;

  // Método para seguir linha
  void seguirLinha();

  // Métodos para desviar de obstáculos
  void desviarObstaculo();
  void curvaObstaculo();
  bool buscarLinha(int tempo);

  public:
  void executar();
};