//define os pinos em que os botões estão conectados
#define button1 2
#define button2 3

//define os pinos em que o LCD está conectado
const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd = {rs, en, d4, d5, d6, d7};

//inicializa o estado dos botões como falso
bool buttonState1 = false, buttonState2 = false;

//inicializa o valor mínimo como 10, máximo como -1 e a soma dos valores como 0
int mn = 10, mx = -1, sum = 0;

//delcara a variável que armazena o valor da média
float med;

//inicializa as variáveis capacity como 10, index e num como 0
int capacity = 10, index = 0, num = 0;

//alocação dinâmica do vetor denominado arr
int* arr = (int*) malloc(capacity*sizeof(int));

/*Função referente a entrada de dados do botão 1
  incrementa o valor de num, podendo ser de 1 a 9
*/
void bot1(){
  num++;
  if(num == 10) num = 0;
  lcd.setCursor(15, 0);
  lcd.print(num);
}

/*Função referente ao botão 2
  Chama a função addInt, seguido da função updateData e depois o updateLCD
  Após isso, redefine o valor de num como 0
*/
void bot2(){
  addInt();
  updateData();
  updateLCD();
  num = 0;
}

/*Função utilizada para certificar a leitura correta, sem repetições dos botões
*/
void readButtons(){
	
  //se o botão 1 for pressionado, buttonState1 torna-se veradeiro
  if(digitalRead(button1) == 1){
     buttonState1 = true;
  } 
  //se buttonState1 for verdadeiro e o botão for pressinado, executa a função bot1
  if(buttonState1 && digitalRead(button1) == 0){
     bot1();
	 //redefine o estado do botão 1 como falso
     buttonState1 = false;
  }
  
  //se o botão 2 for pressionado, buttonState2 torna-se veradeiro
  if(digitalRead(button2) == 1){
     buttonState2 = true;
  } 
  //se buttonState2 for verdadeiro e o botão for pressinado, executa a função bot2
  if(buttonState2 && digitalRead(button2) == 0){
	 bot2();
	 //redefine o estado do botão 2 como falso
     buttonState2 = false;
  }
}

/*Função que expande o tamanho do vetor
  Se houver necessidade, o tamanho é expandido pela função realloc
  A variável de entrada increment é o tamanho que deseja aumentar
*/
void expandArray(int increment){
  capacity = capacity + increment;
  arr = (int*) realloc(arr, sizeof(arr) + increment*sizeof(int));
}

/*Função que verifica se há necessidade de expandir o tamanho do vetor
  se houver necessidade, é executada a função expandArray, com variável de entrada sendo 10
  se não houver necessiade, acrescenta o valo lido na respectiva posição do vetor original e incrementa o index em 1
*/
void addInt(){
  if(index == capacity)
    expandArray(10);
  arr[index] = num;
  index = index + 1;
}

/*Função que realiza a verificação do valor mínimo e máximo
  realiza a soma de todas as variáveis e calcula a média
*/
void updateData(){
  mn = (num < mn) ? num : mn;
  mx = (num > mx) ? num : mx;
  sum += num;
  med = (float)sum/index;
  num = 0;
}

/*Função que inicializa o display LCD
*/
void beginLCD(){
  lcd.begin(16, 2);
}

/*Função que imprime os dados necessários do display LCD
*/
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
