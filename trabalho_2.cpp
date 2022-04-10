/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include "functions.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



void loop(){}

void setup()
{
  beginLCD();
  attachInterrupt(0, readButtons, CHANGE);
  attachInterrupt(1, readButtons, CHANGE);
}
