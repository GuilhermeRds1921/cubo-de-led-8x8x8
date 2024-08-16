#include "config.h"
//How many of the shift registers - change this
#define number_of_74hc595s 8
//do not touch
#define numOfRegisterPins number_of_74hc595s * 8
class Animations{
  private:
    boolean registers[numOfRegisterPins];
    
  public:
    void begin(uint8_t);
    void clearRegisters();    //set all register pins to LOW
    void lightAllRegisters(); //set all register pins to HIGH
    void clearLayers();       //set all layer pins to LOW
    void lightAllLayers();    //set all layer pins to HIGH
    void setRegisterPin();    //set an individual pin HIGH or LOW

    int nextAnimation(int);
    int prevAnimation(int);
    void teste();
    
};

void Animations::begin(uint8_t port){
  
  LiquidCrystal lcd(3,4,5,6,7,8);
  
  lcd.begin(16, 2); 
  lcd.setCursor(0,1);
  lcd.print("Proximo  "); 
  lcd.setCursor(0,0);
  lcd.print("->Anterior");
}
int Animations::nextAnimation(int count){
  if(count == 3)
    return 0;
  else{
    count++;
    return count;
  }
}
int Animations::prevAnimation(int count){
  if(count == 0)
    return 3;
  else{
    count--;
    return count;
  }
}
void Animations::lightAllLayers(){
  for(int i = 2; i < 10; i++){
     digitalWrite(i, HIGH);
  }
}
void Animations::clearLayers(){
  for(int i = 2; i < 10; i++){
     digitalWrite(i, LOW);
  }
}
void Animations::lightAllRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
}
void Animations::clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
}
void setRegisterPin(int index, int value){
  registers[index] = value;
}
void Animations::teste(){
    Serial.println("ok");
}
