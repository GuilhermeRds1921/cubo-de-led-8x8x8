int SER_Pin = 5;   //pin 14 on the 75HC595 data
int RCLK_Pin = 4;  //pin 12 on the 75HC595 latch
int SRCLK_Pin = 3; //pin 11 on the 75HC595 clock

//How many of the shift registers - change this
#define number_of_74hc595s 8

#define t1 13
#define t2 12
#define t3 11
#define t4 10
#define t5 9
#define t6 8
#define t7 7
#define t8 6

//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

boolean registers[numOfRegisterPins];

void setup(){
  pinMode(SER_Pin, OUTPUT);
  pinMode(RCLK_Pin, OUTPUT);
  pinMode(SRCLK_Pin, OUTPUT);
  pinMode(t1, OUTPUT);
  pinMode(t2, OUTPUT);
  pinMode(t3, OUTPUT);
  pinMode(t4, OUTPUT);
  pinMode(t5, OUTPUT);
  pinMode(t6, OUTPUT);
  pinMode(t7, OUTPUT);
  pinMode(t8, OUTPUT);

  //reset all register pins
  clearRegisters();
  writeRegisters();
}               


//set all register pins to LOW
void clearRegisters(){
  for(int i = numOfRegisterPins - 1; i >=  0; i--){
     registers[i] = LOW;
  }
} 


//Set and display registers
//Only call AFTER all values are set how you would like (slow otherwise)
void writeRegisters(){

  digitalWrite(RCLK_Pin, LOW);

  for(int i = numOfRegisterPins - 1; i >=  0; i--){
    digitalWrite(SRCLK_Pin, LOW);

    int val = registers[i];

    digitalWrite(SER_Pin, val);
    digitalWrite(SRCLK_Pin, HIGH);

  }
  digitalWrite(RCLK_Pin, HIGH);

}

//set an individual pin HIGH or LOW
void setRegisterPin(int index, int value){
  registers[index] = value;
}


void loop(){
  digitalWrite(t1,HIGH);
  //digitalWrite(t2,HIGH);
  //digitalWrite(t3,HIGH);
  //digitalWrite(t4,HIGH);
  /*digitalWrite(t3,HIGH);
  digitalWrite(t4,HIGH);*/
  //digitalWrite(t5,HIGH);
  //digitalWrite(t6,HIGH);
  //digitalWrite(t7,HIGH);
  digitalWrite(t8,HIGH);  
  
  
  /*for(int i = numOfRegisterPins - 1; i >=  0; i--){
    setRegisterPin(i, HIGH);
    writeRegisters();
    delay(100);
    setRegisterPin(i, LOW);
    writeRegisters();        
  }*/

setRegisters(1, HIGH)
  //MUST BE CALLED TO DISPLAY CHANGES
  //Only call once after the values are set how you need.
}