#define DBP_ME 70 // Divisor branco e preto do sensor Mais Esquerdo
#define DBP_E 75  // Divisor branco e preto do sensor Esquerdo
#define DBP_D 88  // Divisor branco e preto do sensor Direito
#define DBP_MD 75 // Divisor branco e preto do sensor Mais Direito

class Refletancia{
  float valorSensorDir;
  float valorSensorEsq;
  float valorSensorMaisDir;
  float valorSensorMaisEsq;

  public:
  // Identifica quando todos os sensores não detectarem linha
  inline bool bbbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o mais direito detectar linha
  inline bool bbbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o direito detectar linha
  inline bool bbpb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o mais direito e o direito detectarem linha
  inline bool bbpp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o esquerdo detectar linha
  inline bool bpbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o esquerdo e o mais direito detectarem linha
  inline bool bpbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o esquerdo e o direito detectarem linha
  inline bool bppb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando quando apenas o mais esquerdo não detectar linha
  inline bool bppp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas apenas o mais esquerdo detectar linha
  inline bool pbbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o mais esquerdo e o mais direito detectarem linha
  inline bool pbbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o mais esquerdo e o direito detectarem linha
  inline bool pbpb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o esquerdo não detectar linha
  inline bool pbpp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o esquerdo e o mais esquerdo detectarem linha
  inline bool ppbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o direito não detectar linha
  inline bool ppbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o mais direito não detectar linha
  inline bool pppb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando todos detectarem linha
  inline bool pppp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}

  void ler();
  void print();
  void print_preto_branco();
};