#include "config.h"

class Encoder{
  private:
    int animCount = 0;
    int EncoderAtual;
    int EncoderUltimo;
    int ROT_CLK_Pin = 13;   
    int ROT_DT_Pin = 2;  
    int ROT_SW_Pin = 11;
    
  public:
  void begin(uint8_t);
  
};

void Encoder::begin(uint8_t port){
  pinMode(ROT_CLK_Pin, INPUT);
  pinMode(ROT_DT_Pin, INPUT);
  pinMode(ROT_SW_Pin, INPUT_PULLUP);
  EncoderUltimo = digitalRead(ROT_CLK_Pin); 
}
