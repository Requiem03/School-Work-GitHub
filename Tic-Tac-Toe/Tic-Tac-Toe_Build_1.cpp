#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int choice;
const int board_size=9;


class TicTacToe
{
      public:
             void DisplayBoard();
             int GetMove();
             void Checkforwin();
             int MakeRandomMove();
             bool Ismovevalid(int move);
             bool gameover();
             void reset();
             TicTacToe()
             {
              strcpy(square, "0123456789");          
                        
                        }
      private:
             char square[10];
             
            
            };
            
int main()
{
TicTacToe Board;
int board[board_size];
int turn=0;
int move=10;
srand(time(0));


while (choice!=2)    
    {
     cout<<"(1) Play Tic Tac Toe"<<endl;
     cout<<"(2) Exit"<<endl;
     cin>>choice;
    if (choice==0||choice>2)
    cout<<"invalid option please try again"<<endl;
    
    switch(choice)
    {
       case 1:
      int coin;
      coin=rand()%2;
      
      if(coin==0)
      {
      while(Board.gameover())
      {
      Board.DisplayBoard();
      Board.GetMove();
      Board.Checkforwin();
      Board.MakeRandomMove();
      Board.Checkforwin();
      }
      Board.reset();
      }
      else if(coin==1)
      {
      while(Board.gameover())
      {
      Board.DisplayBoard();
      Board.MakeRandomMove();
      Board.Checkforwin();
      Board.GetMove();
      Board.Checkforwin();
      } 
      Board.reset();
      }
      
       break;
     
       case 2:
      //Exits the Program
       break;
       
       
      
    
    
    }
    }
getch();
return 0;    
}

bool TicTacToe::gameover()
{
    if    ((square[1]==square[2] && square[2]==square[3]))
        return 0;
    else if((square[4]==square[5] && square[5]==square[6]))
        return 0;
    else if((square[7]==square[8] && square[8]==square[9]))
         return 0;
    else if((square[1]==square[4] && square[4]==square[7]))
         return 0;
    else if((square[2]==square[5] && square[5]==square[8]))
         return 0;
    else if((square[3]==square[6] && square[6]==square[9]))
         return 0;
    else if((square[1]==square[5] && square[5]==square[9]))
         return 0;
    else if((square[3]==square[5] && square[5]==square[7]))
       return 0;
   else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4'
               && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
        
        else 
        return 1;    
          
     
     }
void TicTacToe::Checkforwin()
{
     if    ((square[1]==square[2] && square[2]==square[3] && square[1]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[4]==square[5] && square[5]==square[6] && square[4]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[7]==square[8] && square[8]==square[9] && square[7]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[1]==square[4] && square[4]==square[7] && square[1]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[2]==square[5] && square[5]==square[8] && square[2]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[3]==square[6] && square[6]==square[9] && square[3]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[1]==square[5] && square[5]==square[9] && square[1]=='X'))
         cout<<"You Win!!"<<endl;
    else if((square[3]==square[5] && square[5]==square[7] && square[3]=='X'))
         cout<<"You Win!!"<<endl;
       
    else if((square[1]==square[2] && square[2]==square[3] && square[1]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[4]==square[5] && square[5]==square[6] && square[4]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[7]==square[8] && square[8]==square[9] && square[7]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[1]==square[4] && square[4]==square[7] && square[1]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[2]==square[5] && square[5]==square[8] && square[2]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[3]==square[6] && square[6]==square[9] && square[3]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[1]==square[5] && square[5]==square[9] && square[1]=='O'))
         cout<<"Computer Wins!!"<<endl;
    else if((square[3]==square[5] && square[5]==square[7] && square[3]=='O'))
         cout<<"Computer Wins!!"<<endl; 
       
       
       
       
       
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' && square[4] != '4'
             && square[5] != '5' && square[6] != '6' && square[7] != '7' && square[8] != '8' && square[9] != '9')
		       cout<<"It is a Tie"<<endl;
		
		
     
     
     }


void TicTacToe::DisplayBoard()
{
	system("cls");
	cout << "\n\n\tTic Tac Toe\n\n";

	cout << "Player  (X)  -  Computer (O)" << endl << endl;
	cout << endl;

	cout << "     |     |     " << endl;
	cout << "  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << endl;

	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;

	cout << "  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << endl;

	cout << "     |     |     " << endl << endl;
}



int TicTacToe::MakeRandomMove()
{
 int move;
 do
{
 cout<<"Computer Moving."<<endl;   
 move=rand()%board_size;
}while(!Ismovevalid(move));
 square[move]='O';
 DisplayBoard();
 

  
    }
int TicTacToe::GetMove()
{
 int move;
do
{
 cout<<"Player Enter Move:"<<endl;
 cin>>move;
}while (!Ismovevalid(move));
 square[move]='X';
 DisplayBoard();


   
    
     }
bool TicTacToe::Ismovevalid(int move)
{
  if (square[move]=='X'||square[move]=='O')
  return false;
  else
  return true;   
     }
     
void TicTacToe::reset()
{
  strcpy(square, "0123456789");       
                        
     }
