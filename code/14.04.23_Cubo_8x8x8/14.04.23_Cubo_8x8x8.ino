//int SER_Pin = 11;   //pin 14 on the 75HC595 data
//int RCLK_Pin = 10;  //pin 12 on the 75HC595 latch
//int SRCLK_Pin = 13; //pin 11 on the 75HC595 clock
int ROT_CLK_Pin = 13;   
int ROT_DT_Pin = 2;  
int ROT_SW_Pin = 11; 

#include <LiquidCrystal.h>

LiquidCrystal lcd(3,4,5,6,7,8);

//How many of the shift registers - change this
#define number_of_74hc595s 8

//Referentes as entradas do arduino que controlam as layers
#define t1 2
#define t2 3
#define t3 4
#define t4 5
#define t5 6
#define t6 7
#define t7 8
#define t8 9

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

int animCount = 0;
int EncoderAtual;
int EncoderUltimo;
bool aux = true;

void setup(){

  pinMode(ROT_CLK_Pin, INPUT);
  pinMode(ROT_DT_Pin, INPUT);
  pinMode(ROT_SW_Pin, INPUT_PULLUP);  
  EncoderUltimo= digitalRead(ROT_CLK_Pin);

  Serial.begin(9600);  

  lcd.begin(16, 2); 

  lcd.setCursor(0,1);
  lcd.print("Proximo  "); 
  lcd.setCursor(0,0);
  lcd.print("->Anterior");

      
  //reset all register and layer pins
}               

//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 

//set all register pins to HIGH
void lightAllRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = HIGH;
  }
}

//set all layer pins to LOW
void clearLayers(){
  for(int i = 2; i < 10; i++){
     digitalWrite(i, LOW);
  }
}

//set all layer pins to HIGH
void lightAllLayers(){
  for(int i = 2; i < 10; i++){
     digitalWrite(i, HIGH);
  }
}


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)


//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}

int nextAnimation(int count){
  if(count == 3)
    return 0;
  else{
    count++;
    return count;
  }
}

int prevAnimation(int count){
  if(count == 0)
    return 3;
  else{
    count--;
    return count;
  }
}

void loop(){
  lcd.setCursor(0,0);
  // Read the current state of CLK
	EncoderAtual = digitalRead(ROT_CLK_Pin);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	if (EncoderAtual != EncoderUltimo  && EncoderAtual == 1){

		// If the DT state is different than the CLK state then
		// the encoder is rotating CCW so decrement
		if (digitalRead(ROT_DT_Pin) == EncoderAtual) {
      lcd.setCursor(0,1);
      lcd.print("Proximo  "); 
      lcd.setCursor(0,0);
      lcd.print("->Anterior");
      aux = true; 
      Serial.print("True");       			
		} else {
			// Encoder is rotating CW so increment
			lcd.setCursor(0,0);
      lcd.print("Anterior  "); 
      lcd.setCursor(0,1);
      lcd.print("->Proximo");
      aux = false;  
      Serial.println("False");
		}
  }    
  EncoderUltimo = EncoderAtual;    
  
  if (digitalRead(ROT_SW_Pin) == LOW && aux)
  {
    animCount = prevAnimation(animCount);
    Serial.println(animCount);   
    while (digitalRead(ROT_SW_Pin) == LOW);
    delay(100);
  } else if (digitalRead(ROT_SW_Pin) == LOW && !aux){
    animCount = nextAnimation(animCount);
    Serial.println(animCount);   
    while (digitalRead(ROT_SW_Pin) == LOW);
    delay(100);
  }
  
  if(animCount == 0){
  //turnOffAnimations();
  lcd.setCursor(11,0);  
  lcd.print("Exib:");
  lcd.setCursor(11,1);  
  lcd.print("NULL");
  } else if(animCount == 1){
  lcd.setCursor(11,0);  
  lcd.print("Exib:");
  lcd.setCursor(11,1);
  lcd.print("Rain");
  //RainAnimation();
  } else if(animCount == 2){
  lcd.setCursor(11,0);  
  lcd.print("Exib:");
  lcd.setCursor(11,1);
  lcd.print("Scan");
  //ScanAnimation();  
  } else if(animCount = 3){
  lcd.setCursor(11,0);  
  lcd.print("Exib:");
  lcd.setCursor(11,1);
  lcd.print("Expd");
  //ExpandAnimation(150);
  } 

}

