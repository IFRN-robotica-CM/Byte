class Sensor{
  float valorSensorDir;
  float valorSensorEsq;
  float valorSensorMaisDir;
  float valorSensorMaisEsq;
  
  public:
  // Identifica quando todos os sensores não detectarem linha
  bool bbbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o mais direito detectar linha
  bool bbbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o direito detectar linha
  bool bbpb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o mais direito e o direito detectarem linha
  bool bbpp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o esquerdo detectar linha
  bool bpbb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o esquerdo e o mais direito detectarem linha
  bool bpbp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o esquerdo e o direito detectarem linha
  bool bppb(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando quando apenas o mais esquerdo não detectar linha
  bool bppp(){return (valorSensorMaisEsq > DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas apenas o mais esquerdo detectar linha
  bool pbbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando o mais esquerdo e o mais direito detectarem linha
  bool pbbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o mais esquerdo e o direito detectarem linha
  bool pbpb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o esquerdo não detectar linha
  bool pbpp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq > DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando o esquerdo e o mais esquerdo detectarem linha
  bool ppbb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando apenas o direito não detectar linha
  bool ppbp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir > DBP_D && valorSensorMaisDir < DBP_MD);}
  // Identifica quando apenas o mais direito não detectar linha
  bool pppb(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir > DBP_MD);}
  // Identifica quando todos detectarem linha
  bool pppp(){return (valorSensorMaisEsq < DBP_ME && valorSensorEsq < DBP_E && valorSensorDir < DBP_D && valorSensorMaisDir < DBP_MD);}


  void ler();
};