/*Programa que realiza a leitura de entrada de dados de dois botões e armazena os dados lidos em um veotr dinâmicamente alocado
  Para cada valor inserido, é verificado se hpa necessidade de realocar o vetor inicial
  Os dados são apresentados por meio de um display LCD
*/

/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

//incluir o arquivo .h das funções de processamento
#include "functions.h"
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio



void loop(){}

void setup()
{
  //chamada da função beginLCD
  beginLCD();
  
  //attachInterrupt(pino de interrupção, função a ser executada, modo de interrupção)
  attachInterrupt(0, readButtons, CHANGE);
  attachInterrupt(1, readButtons, CHANGE);
}
