#ifndef CONFIG_H
#define CONFIG_H

//Libraries
#include <LiquidCrystal.h>
#include "animations.h"
#include "encoder.h"

//How many of the shift registers - change this
#define number_of_74hc595s 8
//do not touch
#define numOfRegisterPins number_of_74hc595s * 8

//Referentes as entradas do arduino que controlam as layers
#define t1 2
#define t2 3
#define t3 4
#define t4 5
#define t5 6
#define t6 7
#define t7 8
#define t8 9


//Declaration
Animations animation;
Encoder encoder;

#endif
