#define VELOCIDADE_FRENTE 100
#define VELOCIDADE_TRAS -100

#define VELOCIDADE_CURVA_FRACA_FRENTE 75
#define VELOCIDADE_CURVA_FRACA_TRAS -25

#define VELOCIDADE_CURVA_MEDIA_FRENTE 75
#define VELOCIDADE_CURVA_MEDIA_TRAS -50

#define VELOCIDADE_CURVA_FORTE_FRENTE 100
#define VELOCIDADE_CURVA_FORTE_TRAS -75

#define VELOCIDADE_PARAR 0

class Motor{
  public:
  void frente();
  void tras();
  void curvaFracaEsq();
  void curvaFracaDir();
  void curvaMediaEsq();
  void curvaMediaDir();
  void curvaForteEsq();
  void curvaForteDir();
  void parar();
};