#include "functions.h"

#define button1 2
#define button2 3

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd = {rs, en, d4, d5, d6, d7};

bool buttonState1 = false, buttonState2 = false;
bool startup = true;
int mn = 10, mx = -1, sum = 0;
float med;
int capacity = 10, index = 0, num = 0;
int* arr = (int*) malloc(capacity*sizeof(int));

void bot1(){
  num++;
  if(num == 10) num = 0;
  lcd.setCursor(15, 0);
  lcd.print(num);
}

void bot2(){
  addInt();
  updateData();
  updateLCD();
  num = 0;
}

void readButtons(){
  if(digitalRead(button1) == 1){
     buttonState1 = true;
  } 
  if(buttonState1 && digitalRead(button1) == 0){
     bot1();
     buttonState1 = false;
  }
  
  if(digitalRead(button2) == 1){
     buttonState2 = true;
  } 
  if(buttonState2 && digitalRead(button2) == 0){
     bot2();
     buttonState2 = false;
  }
}

void expandArray(int increment){
  capacity = capacity + increment;
  arr = (int*) realloc(arr, sizeof(arr) + increment*sizeof(int));
}

void addInt(){
  if(index == capacity)
    expandArray(10);
  arr[index] = num;
  index = index + 1;
}

void updateData(){
  mn = (num < mn) ? num : mn;
  mx = (num > mx) ? num : mx;
  sum += num;
  med = (float)sum/index;
  num = 0;
}

void beginLCD(){
  lcd.begin(16, 2);
}

void updateLCD(){
  lcd.clear();
  for(int i = (index - 5 >= 0) ? index - 5 : 0, n = 0;
      n < 5 && i < index;
      i++, n++)
  {
    lcd.setCursor(n*3, 0);
    lcd.print(arr[i]);
  }
  lcd.setCursor(0, 1);
  lcd.print(mn);
  lcd.setCursor(3, 1);
  lcd.print(mx);
  lcd.setCursor(6, 1);
  lcd.print(med);
  lcd.setCursor(12, 1);
  lcd.print(index);
}
