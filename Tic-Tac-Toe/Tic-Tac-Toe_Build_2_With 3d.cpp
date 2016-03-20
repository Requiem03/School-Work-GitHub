#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


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
      
             char square[10];
             
            
            };
class TicTacToe3d: public TicTacToe
{
      private:
              
      TicTacToe square3d[3];
      
      public:
             int playerscore; 
             int computerscore;
             void DisplayBoard3d();
             int Checkforscore3d();
             void reset3d();
             bool Ismovevalid3d(int move);
             int MakeRandomMove3d();
             int GetMove3d();
        TicTacToe3d(){playerscore=0; computerscore=0;}
             
      };
            
            
            
int main()
{

TicTacToe Board;
TicTacToe3d Board3d;
int board[board_size];
int turn=0;
int move=10;
srand(time(0));
int coin;
int choice;
int playerscore;
int computerscore;
int x, y;
int count=0;

while (choice!=3)    
    {
     cout<<"(1) Play Tic Tac Toe"<<endl;
     cout<<"(2) Play 3D Tic Tac Toe"<<endl;
     cout<<"(3) Exit"<<endl;
     cin>>choice;
    if (choice==0||choice>3)
    cout<<"invalid option please try again"<<endl;
    
    switch(choice)
    {
       case 1:
      
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
     coin=rand()%2;
     if(coin==0)
     {
     for(count=0;count<27;)
     {
     Board3d.DisplayBoard3d();
     Board3d.GetMove3d();
     count++;
     if(count==27)
     break;
     Board3d.MakeRandomMove3d();
     count++;
     }
     
     Board3d.Checkforscore3d();
     Board3d.reset3d();
     
     }
     else if(coin==1)
     {
     for(count=0;count<27;)
     {
     Board3d.DisplayBoard3d();
     Board3d.MakeRandomMove3d();
     count++;
     if(count==27)
     break;
     Board3d.GetMove3d();
     count++;
     }
     
     Board3d.Checkforscore3d();
     Board3d.reset3d();
     
     }
     
     break;
     
     case 3:
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
 move=(rand()%board_size)+1;
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
   
  if (square[move]=='X')
  return false;
  
  else if(square[move]=='O')
  return false;
  

  
  
  else
  return true;   
     }
     
void TicTacToe::reset()
{
  strcpy(square, "0123456789");       
                        
     }

void TicTacToe3d::DisplayBoard3d()
{
     system("cls");
     cout << "Player  (X)  -  Computer (O)" << endl << endl;
     cout<<"Board1"<<endl;
     square3d[0].DisplayBoard();
     cout<<"Board2"<<endl;
     square3d[1].DisplayBoard();
     cout<<"Board3"<<endl;
     square3d[2].DisplayBoard();
     
     }
     
     
int TicTacToe3d::Checkforscore3d()
{

playerscore=0;
computerscore=0;
     if((square3d[0].square[1]==square3d[0].square[2] && square3d[0].square[2]==square3d[0].square[3] && square3d[0].square[1]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[0].square[4]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[6] && square3d[0].square[4]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[0].square[7]==square3d[0].square[8] && square3d[0].square[8]==square3d[0].square[9] && square3d[0].square[7]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[0].square[1]==square3d[0].square[4] && square3d[0].square[4]==square3d[0].square[7] && square3d[0].square[1]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[0].square[2]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[8] && square3d[0].square[2]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[0].square[3]==square3d[0].square[6] && square3d[0].square[6]==square3d[0].square[9] && square3d[0].square[3]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[0].square[1]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[9] && square3d[0].square[1]=='X'))//diagonal check
         {playerscore=playerscore+1;}
     if((square3d[0].square[3]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[7] && square3d[0].square[3]=='X'))//diagonal check
         {playerscore=playerscore+1;}
  
     if((square3d[1].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[1].square[3] && square3d[1].square[1]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[1].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[6] && square3d[1].square[4]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[1].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[1].square[9] && square3d[1].square[7]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[1].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[1].square[7] && square3d[1].square[1]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[1].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[8] && square3d[1].square[2]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[1].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[1].square[9] && square3d[1].square[3]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[1].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[9] && square3d[1].square[1]=='X'))//diagonal check
         {playerscore=playerscore+1;}
     if((square3d[1].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[7] && square3d[1].square[3]=='X'))//diagonal check
         {playerscore=playerscore+1;}
         
     if((square3d[2].square[1]==square3d[2].square[2] && square3d[2].square[2]==square3d[2].square[3] && square3d[2].square[1]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[2].square[4]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[6] && square3d[2].square[4]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[2].square[7]==square3d[2].square[8] && square3d[2].square[8]==square3d[2].square[9] && square3d[2].square[7]=='X'))//row check
         {playerscore=playerscore+1;}
     if((square3d[2].square[1]==square3d[2].square[4] && square3d[2].square[4]==square3d[2].square[7] && square3d[2].square[1]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[2].square[2]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[8] && square3d[2].square[2]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[2].square[3]==square3d[2].square[6] && square3d[2].square[6]==square3d[2].square[9] && square3d[2].square[3]=='X'))//column check
         {playerscore=playerscore+1;}
     if((square3d[2].square[1]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[9] && square3d[2].square[1]=='X'))//diagonal check
         {playerscore=playerscore+1;}
     if((square3d[2].square[3]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[7] && square3d[2].square[3]=='X'))//diagonal check
         {playerscore=playerscore+1;}         
    
     if((square3d[0].square[1]==square3d[0].square[2] && square3d[0].square[2]==square3d[0].square[3] && square3d[0].square[1]=='O'))//row check
        {computerscore=computerscore+1;}
     if((square3d[0].square[4]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[6] && square3d[0].square[4]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[0].square[7]==square3d[0].square[8] && square3d[0].square[8]==square3d[0].square[9] && square3d[0].square[7]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[0].square[1]==square3d[0].square[4] && square3d[0].square[4]==square3d[0].square[7] && square3d[0].square[1]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[0].square[2]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[8] && square3d[0].square[2]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[0].square[3]==square3d[0].square[6] && square3d[0].square[6]==square3d[0].square[9] && square3d[0].square[3]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[0].square[1]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[9] && square3d[0].square[1]=='O'))//diagonal check
         {computerscore=computerscore+1;}
     if((square3d[0].square[3]==square3d[0].square[5] && square3d[0].square[5]==square3d[0].square[7] && square3d[0].square[3]=='O'))//diagonal check
         {computerscore=computerscore+1;}
  
     if((square3d[1].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[1].square[3] && square3d[1].square[1]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[1].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[6] && square3d[1].square[4]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[1].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[1].square[9] && square3d[1].square[7]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[1].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[1].square[7] && square3d[1].square[1]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[1].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[8] && square3d[1].square[2]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[1].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[1].square[9] && square3d[1].square[3]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[1].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[9] && square3d[1].square[1]=='O'))//diagonal check
         {computerscore=computerscore+1;}
     if((square3d[1].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[1].square[7] && square3d[1].square[3]=='O'))//diagonal check
         {computerscore=computerscore+1;}
         
     if((square3d[2].square[1]==square3d[2].square[2] && square3d[2].square[2]==square3d[2].square[3] && square3d[2].square[1]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[2].square[4]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[6] && square3d[2].square[4]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[2].square[7]==square3d[2].square[8] && square3d[2].square[8]==square3d[2].square[9] && square3d[2].square[7]=='O'))//row check
         {computerscore=computerscore+1;}
     if((square3d[2].square[1]==square3d[2].square[4] && square3d[2].square[4]==square3d[2].square[7] && square3d[2].square[1]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[2].square[2]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[8] && square3d[2].square[2]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[2].square[3]==square3d[2].square[6] && square3d[2].square[6]==square3d[2].square[9] && square3d[2].square[3]=='O'))//column check
         {computerscore=computerscore+1;}
     if((square3d[2].square[1]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[9] && square3d[2].square[1]=='O'))//diagonal check
         {computerscore=computerscore+1;}
     if((square3d[2].square[3]==square3d[2].square[5] && square3d[2].square[5]==square3d[2].square[7] && square3d[2].square[3]=='O'))//diagonal check
         {computerscore=computerscore+1;}   
    
     if((square3d[0].square[1]==square3d[1].square[1] && square3d[1].square[1]==square3d[2].square[1] && square3d[1].square[1]=='X'))//Vertical 3d check sq1
          playerscore=playerscore+1;
     if((square3d[0].square[2]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[2] && square3d[1].square[2]=='X'))//Vertical 3d check sq2
          playerscore=playerscore+1;
     if((square3d[0].square[3]==square3d[1].square[3] && square3d[1].square[3]==square3d[2].square[3] && square3d[1].square[3]=='X'))//Vertical 3d check sq3
          playerscore=playerscore+1;
     if((square3d[0].square[4]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[4] && square3d[1].square[4]=='X'))//Vertical 3d check sq4
          playerscore=playerscore+1;
     if((square3d[0].square[5]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[5] && square3d[1].square[5]=='X'))//Vertical 3d check sq5
          playerscore=playerscore+1;
     if((square3d[0].square[6]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[6] && square3d[1].square[6]=='X'))//Vertical 3d check sq6
          playerscore=playerscore+1;
     if((square3d[0].square[7]==square3d[1].square[7] && square3d[1].square[7]==square3d[2].square[7] && square3d[1].square[7]=='X'))//Vertical 3d check sq7
          playerscore=playerscore+1;
     if((square3d[0].square[8]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[8] && square3d[1].square[8]=='X'))//Vertical 3d check sq8
          playerscore=playerscore+1;
     if((square3d[0].square[9]==square3d[1].square[9] && square3d[1].square[9]==square3d[2].square[9] && square3d[1].square[9]=='X'))//Vertical 3d check sq9
          playerscore=playerscore+1;

     if((square3d[0].square[1]==square3d[1].square[1] && square3d[1].square[1]==square3d[2].square[1] && square3d[1].square[1]=='O'))//Vertical 3d check sq1
          computerscore=computerscore+1;
     if((square3d[0].square[2]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[2] && square3d[1].square[2]=='O'))//Vertical 3d check sq2
          computerscore=computerscore+1;
     if((square3d[0].square[3]==square3d[1].square[3] && square3d[1].square[3]==square3d[2].square[3] && square3d[1].square[3]=='O'))//Vertical 3d check sq3
          computerscore=computerscore+1;
     if((square3d[0].square[4]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[4] && square3d[1].square[4]=='O'))//Vertical 3d check sq4
          computerscore=computerscore+1;
     if((square3d[0].square[5]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[5] && square3d[1].square[5]=='O'))//Vertical 3d check sq5
          computerscore=computerscore+1;
     if((square3d[0].square[6]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[6] && square3d[1].square[6]=='O'))//Vertical 3d check sq6
          computerscore=computerscore+1;
     if((square3d[0].square[7]==square3d[1].square[7] && square3d[1].square[7]==square3d[2].square[7] && square3d[1].square[7]=='O'))//Vertical 3d check sq7
          computerscore=computerscore+1;
     if((square3d[0].square[8]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[8] && square3d[1].square[8]=='O'))//Vertical 3d check sq8
          computerscore=computerscore+1;
     if((square3d[0].square[9]==square3d[1].square[9] && square3d[1].square[9]==square3d[2].square[9] && square3d[1].square[9]=='O'))//Vertical 3d check sq9
          computerscore=computerscore+1;

     if((square3d[0].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[7] && square3d[1].square[1]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[8] && square3d[1].square[2]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[9] && square3d[1].square[3]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[3] && square3d[1].square[1]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[1].square[4]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[9] && square3d[1].square[7]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[9] && square3d[1].square[1]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[1].square[3]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    
     
     if((square3d[0].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[7] && square3d[1].square[1]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[8] && square3d[1].square[2]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[9] && square3d[1].square[3]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[3] && square3d[1].square[1]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[1].square[4]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[9] && square3d[1].square[7]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[9] && square3d[1].square[1]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[1].square[3]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    

     cout<<"Player Score:"<<playerscore<<endl;
     cout<<"Comptuer Score:"<<computerscore<<endl;
     
     return 0;
     }
int TicTacToe3d::GetMove3d()
{
    int move, whichboard;
do
{
 cout<<"Choose Board:"<<endl;
 cin>>whichboard;
 cout<<"Player Enter Move:"<<endl;
 cin>>move;
}while (!(square3d[whichboard-1].Ismovevalid(move)));
 square3d[whichboard-1].square[move]='X';
 DisplayBoard3d();
 }

int TicTacToe3d::MakeRandomMove3d()
{
  int move, whichboard1;
 do
{   
 whichboard1=rand()%3;
 move=(rand()%board_size)+1;
}while(!square3d[whichboard1].Ismovevalid(move));
 square3d[whichboard1].square[move]='O';
 DisplayBoard3d();   
    
    
}

     
void TicTacToe3d::reset3d()
{
  
  strcpy(square3d[0].square, "0123456789");   
  strcpy(square3d[1].square, "0123456789");   
  strcpy(square3d[2].square, "0123456789");
     }
