#include <iostream>
using namespace std;
char board[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
void drawBoard(){
    cout<<"     |     |     \n";
    cout<<"  "<<board[0][0]<<"  |  "<<board[0][1]<<"  |  "<<board[0][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[1][0]<<"  |  "<<board[1][1]<<"  |  "<<board[1][2]<<" \n";
    cout<<"_____|_____|_____\n";
    cout<<"     |     |     \n";
    cout<<"  "<<board[2][0]<<"  |  "<<board[2][1]<<"  |  "<<board[2][2]<<" \n";
    cout<<"     |     |     \n";
  
}
void addLetter(int num, char player){
 if(num==1&&board[0][0]=='1'){
   board[0][0]=player;
 }
 else if(num==2&&board[0][1]=='2'){
    board[0][1]=player;
  }
  else if(num==3&&board[0][2]=='3'){
    board[0][2]=player;

  }
  else if(num==4&&board[1][0]=='4'){
    board[1][0]=player;
  }
  else if(num==5&&board[1][1]=='5'){
    board[1][1]=player;
  }
  else if(num==6&&board[1][2]=='6'){
    board[1][2]=player;
  }
  else if(num==7&&board[2][0]=='7'){
    board[2][0]=player;
  }
  else if(num==8&&board[2][1]=='8'){
    board[2][1]=player;
  }
  else if(num==9&&board[2][2]=='9'){
    board[2][2]=player;
  }
  else{
    cout<<"Invalid try again\n";
  }
}
bool checkRow(){
  //first row
  if(board[0][0]=='x'&&board[0][1]=='x'&&board[0][2]=='x'||board[0][0]=='o'&&board[0][1]=='o'&&board[0][2]=='o'){
    return true;
  }
    //second row
  else if(board[1][0]=='x'&&board[1][1]=='x'&&board[1][2]=='x'||board[1][0]=='o'&&board[1][1]=='o'&&board[1][2]=='o'){
    return true;
  }
    //last row
  else if(board[2][0]=='x'&&board[2][1]=='x'&&board[2][2]=='x'||board[2][0]=='o'&&board[2][1]=='o'&&board[2][2]=='o'){
    return true;
  }
  return false;
}
bool checkCol(){
  //first col
if(board[0][0]=='x'&&board[1][0]=='x'&&board[2][0]=='x'||board[0][0]=='o'&&board[1][0]=='o'&&board[2][0]=='o'){
  return true;
  }
  //second col
  else if(board[0][1]=='x'&&board[1][1]=='x'&&board[2][1]=='x'||board[0][1]=='o'&&board[1][1]=='o'&&board[2][1]=='o'){
    return true;
}
    //third col
else if(board[0][2]=='x'&&board[1][2]=='x'&&board[2][2]=='x'||board[0][2]=='o'&&board[1][2]=='o'&&board[2][2]=='o'){
  return true;
}
  return false;
  }
bool checkDiag(){
  return ((board[0][0]=='x'&&board[1][1]=='x'&&board[2][2]=='x')||(board[0][0]=='o'&&board[1][1]=='o'&&board[2][2]=='o')||(board[0][2]=='x'&&board[1][1]=='x'&&board[2][0]=='x')||(board[0][2]=='o'&&board[1][1]=='o'&&board[2][0]=='o'));
}
bool checkTie(){
  if(checkRow()==false&&checkCol()==false&&checkDiag()==false){
    for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
          if(board[i][j]<=57){
            return false;
            }
      }
      }
    return true;
  }
}
int main() {
  char play;
  char player='x';
  int spot;
  cout<<"Are you ready to play tic tac toe(y/n)";
  cin>>play;
  while(play!='y'&&play!='n'){
    cout<<"Invalid please re-enter y or n ";
    cin>>play;
  }
  while(play=='y'){
    cout<<"Current board: \n";
    drawBoard();
   cout<<"It is "<<player<<"'s turn\n";
    cout<<"What spot do you want to put your letter in?";
    cin>>spot;
    while(spot<1||spot>9){
    cout<<"Invalid spot please re-enter the spot ";
    cin>>spot;
  }
    addLetter(spot, player);
    if(checkDiag()==true||checkRow()==true||checkCol()==true){
      cout<<"Game over "<<player<<" wins! \n";
      break;
      }  
    if(checkTie()==true){
      cout<<"It's a tie\n";
      break;
    }
    if(player=='x'){
      player='o';
    }
    else{
      player='x';
    }
      }
  cout<<"This is your final board: \n";
  drawBoard();
  
  
  }
  
