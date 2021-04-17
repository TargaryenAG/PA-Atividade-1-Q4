#include <iostream>
#include <math.h>

using namespace std;

int BinR[8],DecR=0,N1B[8],N2B[8],N1D=0,N2D=0;
int SPT=0,V=0,i=0,j=0;
char OP;

int main() {
//Recebe e verifica se o segundo binário da operação é valido
do{
  cout<<"\nInforme o primeiro número em binário:\n";
  cin>>SPT;

  for(i=7;i>=0;i--){ //Trasporta o número para o Vetor
    N1B[i]=SPT%10;
    SPT=SPT/10;
    if(N1B[i]>1){
      V=V+1; //Verifica se o Binário é válido
    }
  }
  if(V!=0){
    cout<<"\nO número informado não é valido !!";
  }
}while(V!=0);

  //Recebe e verifica se o segundo binário da operação é valido
do{
  cout<<"\nInforme o segundo número em binário:\n";
  cin>>SPT;
  for(i=7;i>=0;i--){ //Trasporta o número para o Vetor
    N2B[i]=SPT%10;
    SPT=SPT/10;
    if(N2B[i]>1){
      V=V+1; //Verifica se o Binário é válido
    }
  }
  if(V!=0){
    cout<<"\nO número informado não é valido !!";
  }
}while(V!=0);

//Recebe e verifica se a operação matematica é valida
do{
    cout<<"\nInforme a operação matemática desejada:\nSoma = '+' || Subtração = '-' || Divisão = '/' \nMultiplicação = '*' || Módulo = '%'\n\n";
    cin>>OP;
    V=1;
    if((OP =='+') or (OP =='-') or (OP =='*') or (OP =='/') or (OP =='%')){
    V=0; //Verifica se o Operador é válido
  }else{
    cout<<"\nA operação matemática'"<<OP<<"' informada é invalida !!";
  }
}while(V!=0);
//Converte Bínário para Decimal
j=7;
for(i=0;i<8;i++){
  N1D=N1D+(N1B[i]*pow(2,j));
  N2D=N2D+(N2B[i]*pow(2,j));
  j=j-1;
}
//Realiza as operações matemáticas
switch(OP){
  case '+':
    DecR=N1D+N2D;
  break;

  case '-':
    DecR=N1D-N2D;
  break;

  case '*': 
    DecR=N1D*N2D;
  break;

  case '/':
    DecR=N1D/N2D;
  break;

  case '%':
    DecR=(N1D/N2D);
    DecR=N1D-DecR*N2D;
  break;
}
//Exibe a operação em decimal
cout<<"\nDECIMAL\nO resultado da operação: "<<N1D<<OP<<N2D<<" é "<<DecR<<"\n";

//Converte Decimal para Bínário
for(i=7;i>=0;i--){
  if((DecR % 2) > 0){
    BinR[i]=1;
  }else{
    BinR[i]=0;
  }
  DecR=DecR/2;
}

//Exibe a operação em Binário
cout<<"\nBINÁRIO\nO resultado da operação: \n";

for(i=0;i<8;i++){
  cout<<N1B[i];
}

cout<<OP;
for(i=0;i<8;i++){
  cout<<N2B[i];
}
cout<<" é ";
for(i=0;i<8;i++){
  cout<<BinR[i];
}
cout<<"\n\n";

return 0;
}