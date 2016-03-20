//Christopher Bass and Trevor Brown
//CECS 130
//4/11/13
//Lab 11


#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#define Max 3
#include<time.h>

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
class TicTacToe3d
{
      public:
              
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
             int whichboardmove;
             int whichmovemade;
             void resetscore3d();
        TicTacToe3d(){playerscore=0; computerscore=0;}
             
      };
            
    // Creates a class to hold all of the functions and variable for the board
class Board_2D
{
    public:
    char XO[Max][Max]; // Private Matrix, holds the tic-tac-toe board information       
		
		
	public:
		Board_2D()
		{
			// Loops until all spaces on the matrix XO are blank
			for (int g= 0; g < Max; g++)
			{
				for (int h= 0; h < Max; h++)
				{
					XO[g][h] = ' ';
				}
			}
		}
		
		~Board_2D()
		{
			
		}
		
		
        int FirstRand();
		// Creates a random number 1 or 2 and returns that number
		// No requirements
		void display();
		// Displays the board
		// Requires that all spaces of the matrix are filled
		int Turn(int current);
		// Changes the turn player number (1 or 2), declares whose turn it is and, returns the number
		// Requires the turn player's number in integer form
		void place_X();
		// Places an X in a row and column chosen by the user on matrix XO 
		// No prior requirments
		void place_O();
		// Places an O in a row and column chosen by the user on matrix XO 
		// No prior requirments
		int ComputerTurn(int TurnNum);
		// Uses for loops and if statements to determine what move the computer should make. Then, places an X or O depending
		//    on the number of turns that have passed. Then, returns a check (0 for fail, 1 for success)
		// Requires the number of turn that have passed stored in a variable
		int victory();
		// Checks the matrix XO to see if the conditions to win are met
		// No prior requirements
		void winner(int turn);
		// Declares the winner of the game
		// Requires the turn player's number in integer form
		
		// New Functions for 3D
		int BoardFull();
		// Checks if a board had no more empty spaces
		// No Prior Requirements
		char getvalue(int Row,int Column);
		// Returns the character stored in a row and column of a tic-tac-toe board
		// Requires two integer values between 0 and 2, and a character to be stored in that array space
		void CompPlaceX(int XRow, int XColumn, int XBoard);
		// Places an X on the Board during the computer's turn
		// Requires two integer values between 0 and 2, and for the space in the array to be filled with a blank (' ')
		void CompPlaceO(int ORow, int OColumn, int OBoard);
		// Places an O on the Board during the computer's turn
		// Requires two integer values between 0 and 2, and for the space in the array to be filled with a blank (' ')
		int FailsafeCompTurn(int fTurn);
		// Makes a random move
		// Requires an integer indicating how many turns have passed. (Helps to determine whether to place a X or an O
        
};

class Board_3D
{
	public:
		Board_2D XO3D[3]; // And array of 2D boards
	
	public:
		
		Board_3D()
		{
			
		}
		
		~Board_3D()
		{
			
		}
		
		void display3D();
		// Displays all 3 tic-tac-toe boards
		// No Requirements
		void place_X3D();
		// Allows user to place a X on the 3D board
		// No Requirements
		void place_O3D();
		// Allows user to place an O on the 3D board
		// No Requirements
		int ComputerTurn3D(int TurnNum3D);
		// Makes a move for the computer player in 3D
		// Requires the number of turns that have passed
		char WinCount3D();
		// Counts the number of wins for X and O
		// Requires every space in the 3D array to be filled with either X's or O's
		//int whichboardIsIt;
        void resetboard3d();
        int whichrow;
        int whichcolumn;
        int whichboardIsIt;
};        
 
class competition: public TicTacToe3d, public Board_3D
{
      public:
             int ComputerCmove();
             int ComputerTmove(int turn);
             void convertTboard();
             void convertCboard();
             void displayboard4d();
             void reset4d();
             void checkforscore4d();
             void resetscore4d();
      competition()
      {
      TicTacToe3d();
      Board_3D();
      }
      };
            
int main()
{
competition Board4;
TicTacToe Board;
TicTacToe3d Board3d;
int board[board_size];
int turn=0;
int move=10;
srand(time(0));
int coin;
int choice;
int playerscore=0;
int computerscore=0;
int x, y;
int count=0;


while (choice!=4)    
    {
     cout<<"(1) Play Tic Tac Toe"<<endl;
     cout<<"(2) Play 3D Tic Tac Toe"<<endl;
     cout<<"(3) Computers Play Tic Tac Toe"<<endl;
     cout<<"(4) Exit"<<endl;
     cin>>choice;
    if (choice==0||choice>4)
    cout<<"invalid option please try again"<<endl;
    
    switch(choice)
    {
       case 1://Regular Tic Tac Toe
      
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
     
     case 2://3D Tic Tac Toe
          
     coin=rand()%2;
     if(coin==0)
     {
     for(count=0;count<27;)
     {
     Board3d.DisplayBoard3d();
     Board4.GetMove3d();
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
     
     case 3://Computers Play Each Other
     
     for(int n=0; n<10; n++)
     {
     coin=rand()%2;
     if(coin==0)
     {
     for(count=0;count<27;)
     {
     Board4.displayboard4d();
     Board4.ComputerTmove(1); 
     Board4.convertTboard(); 
     Board4.displayboard4d();
     count++;
     if(count==27)
     break;
     Board4.ComputerCmove();
     Board4.convertCboard();
     Board4.displayboard4d();
     count++;
     }
     
     Board4.checkforscore4d();
     cout<<"This is Game #"<<n+1<<endl;system("pause");
     Board4.reset4d();
     
     }
     else if(coin==1)
     {
     for(count=0;count<27;)
     {
     Board4.displayboard4d();
     Board4.ComputerCmove();
     Board4.convertCboard();
     Board4.displayboard4d();
     count++;
     if(count==27)
     break;
     Board4.ComputerTmove(1);
     Board4.convertTboard();
     Board4.displayboard4d();
     count++;
     }
     
     Board4.checkforscore4d();
     cout<<"This is Game #"<<n+1<<endl;system("pause");
     Board4.reset4d();
     }
     }
     Board4.resetscore4d();
     
     
     break;
     
     case 4:
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
     cout << "Trevors' Computer  (X)  - Chris' Computer (O)" << endl << endl;
     cout<<"Board1"<<endl;
     square3d[0].DisplayBoard();
     cout<<"Board2"<<endl;
     square3d[1].DisplayBoard();
     cout<<"Board3"<<endl;
     square3d[2].DisplayBoard();
     
     }
     
     
int TicTacToe3d::Checkforscore3d()
{
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

     if((square3d[0].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[7] && square3d[0].square[1]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[8] && square3d[0].square[2]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[9] && square3d[0].square[3]=='X'))//Vertical column 3d check
          playerscore=playerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[3] && square3d[0].square[1]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[6] && square3d[0].square[4]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[9] && square3d[0].square[7]=='X'))//Vertical row 3d check
          playerscore=playerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[9] && square3d[0].square[1]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
     if((square3d[0].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[0].square[3]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    
    if((square3d[2].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[0].square[7] && square3d[2].square[1]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[8] && square3d[2].square[2]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[0].square[9] && square3d[2].square[3]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[0].square[3] && square3d[2].square[1]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[6] && square3d[2].square[4]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[0].square[9] && square3d[2].square[7]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[9] && square3d[2].square[1]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;
    if((square3d[2].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[7] && square3d[2].square[3]=='X'))//Diagonal 3d check
          playerscore=playerscore+1;

     
     if((square3d[0].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[2].square[7] && square3d[0].square[1]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[8] && square3d[0].square[2]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[2].square[9] && square3d[0].square[3]=='O'))//Vertical column 3d check
          computerscore=computerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[2].square[3] && square3d[0].square[1]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[6] && square3d[0].square[4]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[2].square[9] && square3d[0].square[7]=='O'))//Vertical row 3d check
          computerscore=computerscore+1;
     
     if((square3d[0].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[9] && square3d[0].square[1]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
     if((square3d[0].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[2].square[7] && square3d[0].square[3]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    
    if((square3d[2].square[1]==square3d[1].square[4] && square3d[1].square[4]==square3d[0].square[7] && square3d[2].square[1]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[2]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[8] && square3d[2].square[2]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[3]==square3d[1].square[6] && square3d[1].square[6]==square3d[0].square[9] && square3d[2].square[3]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[1]==square3d[1].square[2] && square3d[1].square[2]==square3d[0].square[3] && square3d[2].square[1]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[4]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[6] && square3d[2].square[4]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[7]==square3d[1].square[8] && square3d[1].square[8]==square3d[0].square[9] && square3d[2].square[7]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[1]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[9] && square3d[2].square[1]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;
    if((square3d[2].square[3]==square3d[1].square[5] && square3d[1].square[5]==square3d[0].square[7] && square3d[2].square[3]=='O'))//Diagonal 3d check
          computerscore=computerscore+1;

     cout<<"Trevors' Copmuter Score: "<<playerscore<<endl;
     cout<<"Chris' Computer Score: "<<computerscore<<endl;
     
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
 whichboardmove=whichboard1;
 whichmovemade=move;
 DisplayBoard3d();   
    
    
}

void TicTacToe3d::resetscore3d()
{
     playerscore=0;
     computerscore=0;
     
     }
     
void TicTacToe3d::reset3d()
{
  
  strcpy(square3d[0].square, "0123456789");   
  strcpy(square3d[1].square, "0123456789");   
  strcpy(square3d[2].square, "0123456789");
     }
// Chooses who goes first
int Board_2D::FirstRand()
{
	srand(time(0)); // Makes the rand() commnad based off of the computers clock
	int choice; // Holder for the random number
	
	choice = rand()%2 +1; // Picks a random number 0 or 1 and increments it
	
	// Declares who goes first
	if(choice == 1)
	{
		cout << "Player one goes first!\n";
	}
	else
	{
		cout << "Computer goes first!\n";
	}
	
	return choice; // Returns the random number
}

// Displays the board XO
void Board_2D::display()
{
	int i;
	int j;

	
	for(int i = 0; i < 3; i++)
	{
		cout << " "; // Puts a space when starting a new line
		for(j = 0; j < 3; j++)
		{
			
			cout << XO[i][j]; // Outputs a space in the matrix from left to right
			
			if (j < 2)
			{
				cout << " | "; // Separates each column in the matrix
			}
			
		}
		
		if (i < 2)
		{
			cout << "\n------------\n"; // Separates each row in the matrix, but does not cover the bottom
		} 
	}
	
	cout << endl; // Moves the line down for the next command
  
}

// Changes whose turn it is, declares whose turn it is, and returns whose turn it is
int Board_2D::Turn(int current)
{
	current++; // Increments the turn player number
	
	cout << endl; // moves the line down
	
	// If the player number is odd then it's player one's turn
	if (current%2 == 1)
	{
		cout << "Player one's turn\n";
	}
	
	// If it is even it is the computer's turn
	else
	{
		cout << "Computer's turn\n";
	}
	
	return current; // Returns the current player number
}

void Board_2D::place_X()
{
	int row; // Row on the matrix
	int column; // Column on the matrix
	int checkX = 0; // Check variable to make sure the space chosen is niether occupied nor invailid
	
	while (checkX == 0)
	{
		// Prompts user to choose a row and column of the matrix to place the X
		cout << "Choose a row, then a column to place a X\n"
		     << "Row: ";
		cin >> row; // Gets an integer for row
		cout << "Column: ";
		cin >> column; // Gets an ineger for column
		
		if ((row < 1) || (row > 3) || (column < 1) || (column > 3)) // Checks to make sure the choices are inside the board range
		{
			checkX = 0; // if they are not the check is false
			
			cout << "\nThe point you have chosen does not exist on the board.\n"
				 << "Please enter a row and column from numbers 1 to 3.\n\n"; // Informs the user of the mistake
			display(); // Displays the board
		}
		
		// Checks if the space chosen is blank
		else if (XO[row-1][column-1] == ' ')
		{
			checkX = 1; // Check returns true
		}
		
		// Else the space chosen already has an 'X' or 'O'
		else
		{
			checkX = 0; // Returns false
			cout << "\nThis space is already occupied. Try again.\n"; // Informs user of their mistake
			display();
		}
		
	}
	XO[row-1][column-1] = 'X'; // Places an X in the space chosen by the user
	
}

void Board_2D::place_O()
{
	int row; // Row on the matrix
	int column; // Column on the matrix
	int checkO = 0; // Check variable to make sure the space chosen is niether occupied nor invailid
	
	while (checkO == 0)
	{
		// Prompts user to choose a row and column of the matrix to place the O
		cout << "Choose a row, then a column to place a O\n"
		     << "Row: ";
		cin >> row; // Gets an integer for row
		cout << "Column: ";
		cin >> column; // Gets an ineger for column
		
		if ((row < 1) || (row > 3) || (column < 1) || (column > 3)) // Checks to make sure the choices are inside the board range
		{
			checkO = 0; // if they are not the check is false
			
			cout << "\nThe point you have chosen does not exist on the board.\n"
				 << "Please enter a row and column from numbers 1 to 3.\n\n"; // Informs the user of the mistake
			display(); // Displays the board
		}
		
		// Checks if the space chosen is blank
		else if (XO[row-1][column-1] == ' ')
		{
			checkO = 1; // Check returns true
		}
		
		// Else the space chosen already has an 'X' or 'O'
		else
		{
			checkO = 0; // Returns false
			cout << "\nThis space is already occupied. Try again.\n"; // Informs user of their mistake
			display();
		}
		
	}
	XO[row-1][column-1] = 'O'; // Places an O in the space chosen by the user
	
}

int Board_2D::ComputerTurn(int TurnNumber)
{
	int cRow; // Row for the computer to store a integer
	int cColumn; // Row for the computer to store a integer
	int VictorX; // Check to see if a how many X's are in a row, column or diagonal
	int VictorO; // Check to see if a how many X's are in a row, column or diagonal
	int StoreRow; // Temporary value that stores a row number
	int StoreColumn; // Temporary value that stores a column number
	
	// ** Check For Moves **
	
	// ** Check For Winning Moves **
		
	// ** Winning Moves: Diagonal Spaces Row1 Column1, R2C2, R3C3**
	
	// In this loop cRow represents row and column 
	
	VictorX = 0; // Sets the number of X's found in the diagonal to 0
	VictorO = 0; // Sets the number of O's found in the diagonal to 0
	StoreRow = -1; // initializes StoreRow
		
	// Loops until all spaces in the diagonal are checked
	for (cRow = 0; cRow < Max; cRow++)
	{
		
		if (XO[cRow][cRow] == 'X') // If an X is found increments VictorX
		{
			VictorX ++;
		}
		else if (XO[cRow][cRow] == 'O')   // If an O is found increments VictorO
		{
			VictorO ++;
		}
		else
		{
			StoreRow = cRow; // If the space is empty stores the row number in StoreRow	
		}
		
	}
	
	// If there is a blank space, the computer's letter is X, and there are two X's in the diagonal
	if ((VictorX == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
	{
		XO[StoreRow][StoreRow] = 'X'; // Computer places an X in the empty spot
		return 1; // Move confirmed
	}
	// If there is a blank space, the computer's letter is O, and there are two O's in the diagonal
	else if ((VictorO == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
	{
		XO[StoreRow][StoreRow] = 'O';// Computer places an O in the empty spot
		return 1; // Move Confirmed
	}
	
	// ** Winning Moves: Horizontal Tic-Tac-Toe **
	
	// Loops until all rows are checked	
	for(cRow = 0; cRow < Max; cRow++)
	{
		VictorX = 0; // Sets X's found to zero each time a new row is checked
		VictorO = 0; // Set's O's found to zero each time a new row is checked
		StoreRow = -1; // Sets StoreRow to -1. (If it remains -1 after the row is checked it means there are no empty spaces)
		
		// Checks each space in the row, counting the number of X's and O's
		for (cColumn = 0; cColumn < Max; cColumn++)
		{
			if (XO[cRow][cColumn] == 'X')
			{
				VictorX ++;
			}
			else if (XO[cRow][cColumn] == 'O')
			{
				VictorO ++;
			}
			else
			{
				StoreRow = cRow;
				StoreColumn = cColumn;	
			}
	
		}	
		
		// If there is a blank space, the computer's letter is X, and there are two X's in the row
		if ((VictorX == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'X'; // Places an X in the empty space
			return 1;
		}
		// If there is a blank space, the computer's letter is O, and there are two O's in the row
		else if ((VictorO == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'O'; // Places an O in the empty space
			return 1;
		}
	}
	
	// ** Winning Moves: Column Tic-Tac-Toe **
	
	// Loops until all columns are checked
	for(cColumn = 0; cColumn < Max; cColumn++)
	{
		VictorX = 0; // Sets X's found to zero each time a new column is checked
		VictorO = 0; // Set's O's found to zero each time a new column is checked
		StoreRow = -1; // Sets StoreRow to -1 each time a nem column is checked
		
		// Counts the number of X's and O's in each row and stores any empty space
		for (cRow = 0; cRow < Max; cRow++)
		{
			if (XO[cRow][cColumn] == 'X')
			{
				VictorX ++;
			}
			else if (XO[cRow][cColumn] == 'O')
			{
				VictorO ++;
			}
			else
			{
				StoreRow = cRow;
				StoreColumn = cColumn;	
			}
	
		}	
		
		// If there is a blank space, the computer's letter is X, and there are two X's in the colummn
		if ((VictorX == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'X';
			return 1;
		}
		// If there is a blank space, the computer's letter is O, and there are two O's in the column
		else if ((VictorO == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'O';
			return 1;
		}
	}
		
	// ** Winning Moves: Diagonal Spaces R3C1, R2C2, R1C3 **
	
	cColumn = 0; // Sets cColumn to 0 (it is incremented in the loop
	VictorX = 0; // Sets X's found to zero each time a new column is checked
	VictorO = 0; // Set's O's found to zero each time a new column is checked
	StoreRow = -1; // Sets StoreRow to -1 each time a nem column is checked
		
	// Loops until each space of the diagonal is checked, moving up a row with each run	
	for(cRow = 2; cRow > -1; cRow--)
	{
		// Counts the number of X's and O's in each row and stores any empty space
		if (XO[cRow][cColumn] == 'X')
		{
			VictorX ++;
		}
		else if (XO[cRow][cColumn] == 'O')
		{
			VictorO ++;
		}
		else
		{
			StoreRow = cRow;
			StoreColumn = cColumn;	
		}
			
		cColumn++; // Increments the column number
	}
	
	// If there is a blank space, the computer's letter is X, and there are two X's in the diagonal
	if ((VictorX == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
	{
		XO[StoreRow][StoreColumn] = 'X'; // Places a X in the empty space
		return 1;
	}
	// If there is a blank space, the computer's letter is O, and there are two O's in the diagonal
	else if ((VictorO == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
	{
		XO[StoreRow][StoreColumn] = 'O'; // Places and O in the empty space
		return 1;
	}
		
	// ** Check for Blocking moves **
		
	// ** Blocking Moves: Diagonal Spaces Row1 Column1, R2C2, R3C3**
		
	// In this loop cRow represents row and column 
		
	VictorX = 0; // Sets the number of X's found in the diagonal to 0
	VictorO = 0; // Sets the number of O's found in the diagonal to 0
	StoreRow = -1; // initializes StoreRow
	
	// Loops until all spaces in the diagonal are checked
	for (cRow = 0; cRow < Max; cRow++)
	{
		
		if (XO[cRow][cRow] == 'X') // If an X is found increments VictorX
		{
			VictorX ++;
		}
		else if (XO[cRow][cRow] == 'O')   // If an O is found increments VictorO
		{
			VictorO ++;
		}
		else
		{
			StoreRow = cRow; // If the space is empty stores the row number in StoreRow	
		}
		
	}
	
	// If there is a blank space, the computer's letter is X, and there are two O's in the diagonal
	if ((VictorO == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
	{
		XO[StoreRow][StoreRow] = 'X'; // Computer places an X in the empty spot
		return 1; // Move confirmed
	}
	// If there is a blank space, the computer's letter is O, and there are two X's in the diagonal
	else if ((VictorX == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
	{
		XO[StoreRow][StoreRow] = 'O';// Computer places an O in the empty spot
		return 1; // Move Confirmed
	}
	
	// ** Blocking Moves: Horizontal Tic-Tac-Toe **
	
	// Loops until all rows are checked	
	for(cRow = 0; cRow < Max; cRow++)
	{
		VictorX = 0; // Sets X's found to zero each time a new row is checked
		VictorO = 0; // Set's O's found to zero each time a new row is checked
		StoreRow = -1; // Sets StoreRow to -1. (If it remains -1 after the row is checked it means there are no empty spaces)
		
		// Checks each space in the row, counting the number of X's and O's
		for (cColumn = 0; cColumn < Max; cColumn++)
		{
			if (XO[cRow][cColumn] == 'X')
			{
				VictorX ++;
			}
			else if (XO[cRow][cColumn] == 'O')
			{
				VictorO ++;
			}
			else
			{
				StoreRow = cRow;
				StoreColumn = cColumn;	
			}
	
		}	
		
		// If there is a blank space, the computer's letter is X, and there are two O's in the row
		if ((VictorO == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'X'; // Places an X in the empty space
			return 1;
		}
		// If there is a blank space, the computer's letter is O, and there are two X's in the row
		else if ((VictorX == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'O'; // Places an O in the empty space
			return 1;
		}
	}
	
	// ** Blocking Moves: Column Tic-Tac-Toe **
	
	// Loops until all columns are checked
	for(cColumn = 0; cColumn < Max; cColumn++)
	{
		VictorX = 0; // Sets X's found to zero each time a new column is checked
		VictorO = 0; // Set's O's found to zero each time a new column is checked
		StoreRow = -1; // Sets StoreRow to -1 each time a nem column is checked
	
		// Counts the number of X's and O's in each row and stores any empty space
		for (cRow = 0; cRow < Max; cRow++)
		{
			if (XO[cRow][cColumn] == 'X')
			{
				VictorX ++;
			}
			else if (XO[cRow][cColumn] == 'O')
			{
				VictorO ++;
			}
			else
			{
				StoreRow = cRow;
				StoreColumn = cColumn;	
			}
		
		}	
			
		// If there is a blank space, the computer's letter is X, and there are two O's in the colummn
		if ((VictorO == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'X';
			return 1;
		}
		// If there is a blank space, the computer's letter is O, and there are two X's in the column
		else if ((VictorX == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
		{
			XO[StoreRow][StoreColumn] = 'O';
			return 1;
		}
	}
		
	// ** Blocking Moves: Diagonal Spaces R3C1, R2C2, R1C3 **
	
	cColumn = 0; // Sets cColumn to 0 (it is incremented in the loop
	VictorX = 0; // Sets X's found to zero each time a new column is checked
	VictorO = 0; // Set's O's found to zero each time a new column is checked
	StoreRow = -1; // Sets StoreRow to -1 each time a nem column is checked
	
	// Loops until each space of the diagonal is checked, moving up a row with each run	
	for(cRow = 2; cRow > -1; cRow--)
	{
		// Counts the number of X's and O's in each row and stores any empty space
		if (XO[cRow][cColumn] == 'X')
		{
			VictorX ++;
		}
		else if (XO[cRow][cColumn] == 'O')
		{
			VictorO ++;
		}
		else
		{
			StoreRow = cRow;
			StoreColumn = cColumn;	
		}
			
		cColumn++; // Increments the column number
	}
		
	// If there is a blank space, the computer's letter is X, and there are two O's in the diagonal
	if ((VictorO == 2) && (TurnNumber%2 == 1) && (StoreRow != -1))
	{
		XO[StoreRow][StoreColumn] = 'X'; // Places a X in the empty space
		return 1;
	}
	// If there is a blank space, the computer's letter is O, and there are two X's in the diagonal
	else if ((VictorX == 2) && (TurnNumber%2 == 0) && (StoreRow != -1))
	{
		XO[StoreRow][StoreColumn] = 'O'; // Places and O in the empty space
		return 1;
	}

	return 0;
}

// Makes a random move for the computer
int Board_2D::FailsafeCompTurn(int fTurn)
{
	srand(time(0)); // Makes the rand function based off of time
	int failsafe; // Checks if a move has been made by the computer
	int fRow; // Represents the board's row
	int fColumn; // Represents the board's column
	
	// ** If First Turn **
	
	// If it is turn number 1 the computer makes a random move and places an 'X'
	if (fTurn == 1)
	{
		// Selects a random row and column
		fRow = rand()%3;
		fColumn = rand()%3;
		
		// Sets that space to X
		XO[fRow][fColumn] = 'X';
		return 1; // Confirms that a move was made
	}
	
	
	// While the computer has not successfully chosen a move
	while (failsafe == 0)
	{
		fRow = rand()%3; // Computer pick a random row
		fColumn = rand()%3; // Computer pick a random column
		
		// If the space is occupied the move fails
		if ((XO[fRow][fColumn] == 'X') || (XO[fRow][fColumn] == 'O'))
		{
			failsafe = 0;
		}
		// Else if the turn count is odd place a X
		else if (fTurn%2 == 1)
		{
			XO[fRow][fColumn] = 'X';
			failsafe = 1;
			return 1;
		}
		// Else the turn count is even, place an O
		else if (fTurn%2 == 0)
		{
			XO[fRow][fColumn] = 'O';
			failsafe = 1;
			return 1;
		}
		
	}
	
	return 0;
}

// Checks if victory is achieved
int Board_2D::victory()
{
	int e; // Row loop counter
	int f; // Column loop counter
	int winnerX = 0; // Counts the number of X's in a row/column/diagonal
	int winnerO = 0; // Counts the number of O's in a row/column/diagonal
	
	// ** Diagonal R1C1, R2C2, R3C3 Check **
	
	// loops until all spaces in the diagonal are checked
	for (e = 0; e < Max; e++)
	{
		// Counts the X's and O's in the diagonal
		if (XO[e][e] == 'X')
		{
			winnerX ++;
		}
		else if (XO[e][e] == 'O')
		{
			winnerO ++;
		}
		
		// If there are three X's or three O's in the diagonal
		if ((winnerX == 3) || (winnerO == 3))
		{
			return 1; // Returns 1 (Winner Confirmed
		}
		
	}
	
	// ** Horizontal Check
	
	// Loops until all rows are checked
	for(e = 0; e < Max; e++)
	{
		winnerX = 0; // Set's X's found to zero when starting a new row
		winnerO = 0; // Set's O's found to zero when starting a new row
		
		for (f = 0; f < Max; f++)
		{
			// Checks for X's and O's
			if (XO[e][f] == 'X')
			{
				winnerX ++;
			}
			else if (XO[e][f] == 'O')
			{
				winnerO ++;
			}
			
			// If there are three X's or three O's in the row
			if ((winnerX == 3) || (winnerO == 3))
			{
				return 1; // Winner Confirmed
			}
		
		}
	}
	
	// ** Column Check **
	
	// Loops until all columns are checked
	for(f = 0; f < Max; f++)
	{
		winnerX = 0; // Set's X's found to zero when starting a new column
		winnerO = 0; // Set's O's found to zero when starting a new column
		
		for (e = 0; e < Max; e++)
		{
			// Checks for X's and O's
			if (XO[e][f] == 'X')
			{
				winnerX ++;
			}
			else if (XO[e][f] == 'O')
			{
				winnerO ++;
			}
			
			// If there are three X's or three O's in the row
			if ((winnerX == 3) || (winnerO == 3))
			{
				return 1; // Winner Confirmed
			}
		
		}
	}
	
	// Diagonal R3C1, R2C2, R1C3 Check
	
	
	f = 0; // Start at column zero (Column 1 on the board) (incremented in the loop)
	winnerX = 0; // Sets X's found to zero
	winnerO = 0; // Sets O's found to zero
		
	// Loops until the diagonal is checked
	for(e = 2; e > -1; e--)
	{
		// Checks for X's and O's
		if (XO[e][f] == 'X')
		{
			winnerX ++;
		}
		else if (XO[e][f] == 'O')
		{
			winnerO ++;
		}
			
		// If there are three X's or three O's in the row
		if ((winnerX == 3) || (winnerO == 3))
		{
				return 1; // Winner Confirmed
		}
		
		f++; // Increments the column number
	}
	
	 // ** No Winner **

	return 0; // If no winner then the function fails and returns 0
}

// Declares the winner
void Board_2D::winner(int turn)
{
	
	cout << endl; // Moves the line down
	
	// If it is the user's (odd number) turn then it says the user wins
	if (turn%2 == 1)
	{
		cout << "YOU WIN!!!\n";
	}
	
	// If it is the computer's (even number) turn then it says the computer wins
	else
	{
		cout << "Computer wins.\n";
	}
}

// Checks to see if the board is full
int Board_2D::BoardFull()
{
	int EmptySpace;
	
	for(int fRow = 0; fRow < Max; fRow++)
	{
		for(int fColumn = 0; fColumn < Max; fColumn++)
		{
			if (XO[fRow][fColumn] == ' ')
			{
				return 1; // Returns 1 if there is an empty space on the board
			}
		}
	}
	return 0; // Returns 0 if the board is full.
}

// Returns the character stored in the initial row and column
char Board_2D::getvalue(int Row,int Column)
{
	return XO[Row][Column];
}

// Places a X on the board for the computer
void Board_2D::CompPlaceX(int XRow, int XColumn, int XBoard)
{
	XO[XRow][XColumn] = 'X'; 
	
}

// Places an O on the board for the computer
void Board_2D::CompPlaceO(int ORow, int OColumn, int OBoard)
{
	XO[ORow][OColumn] = 'O';
}

// ** 3-D Commands **

// Display the 3D Board
void Board_3D::display3D()
{
	cout << "1.\n";
	XO3D[0].display();
	cout << "2.\n"; 
	XO3D[1].display();
	cout << "3.\n";
	XO3D[2].display();
}

// Places an X for the user on the 3D board
void Board_3D::place_X3D()
{
	int BoardNumberX; // Holder for the board number chosen by the user
	int BoardCheck; // A check to make sure the board chosen is not full
	
	// Prompts the user for a board number
	cout << "Choose a board to place the X\n"
		 << "Board: ";
	cin >> 	BoardNumberX;
	BoardCheck = XO3D[BoardNumberX-1].BoardFull(); // Checks if the selected board is full
	
	while(BoardCheck !=1)
	{
		
		cout << "Please choose a board that is not full. (You may choose 1-3)\n";
		display3D(); 
		cin >> BoardNumberX;
		BoardCheck = XO3D[BoardNumberX-1].BoardFull(); // Allows the user to place a X
	}
	XO3D[BoardNumberX-1].place_X(); // Allows the user to place a X on the board of their choice
	
	
}

// Places an O for the user on the 3D board
void Board_3D::place_O3D()
{
	int BoardNumberO;
	int BoardCheck;
	
	cout << "Choose a board to place the O\n"
		 << "Board: ";
	cin >> 	BoardNumberO;
	BoardCheck = XO3D[BoardNumberO-1].BoardFull();
	
	while(BoardCheck !=1)
	{
		cout << "Please choose a board that is not full. (You may choose 1-3)\n";
		display3D();
		cin >> BoardNumberO;
		BoardCheck = XO3D[BoardNumberO-1].BoardFull();
	}
	XO3D[BoardNumberO-1].place_O(); // Same function except this one allows the user to place an O
	
	
}

int Board_3D::ComputerTurn3D(int TurnNum3D)
{
	srand(time(0)); // Bases rand() off the computer time 
	int cBoard=-1; // Counter variable that represents the board number
	int CBoardCheck = 0; // Checks if a move hasd been made by the computer

	int StoreBoard=-1; // Storage variable for board number when there is an empty space
	int StoreRow3D = -1; // Storage variable for row number. Initialized to -1 for a check in the program
	int StoreColumn3D=-1; // Storage variable for column number when there is an empty space

	char Xcheck1;// These keep track of where an X has been placed for the competiton class

	
		// ** Random move **
		while(CBoardCheck == 0)
		{
                                                                          
			cBoard = rand()%3;
			StoreRow3D = rand()%3;
			StoreColumn3D = rand()%3;
            CBoardCheck = XO3D[cBoard].BoardFull();
            Xcheck1 = XO3D[cBoard].getvalue(StoreRow3D, StoreColumn3D);
			if (Xcheck1 == ' ')
			{                         
				XO3D[cBoard].CompPlaceX(StoreRow3D, StoreColumn3D, cBoard);
				whichboardIsIt = cBoard;
				whichrow = StoreRow3D;
				whichcolumn = StoreColumn3D;
			}
			else
			{
                CBoardCheck = 0;             
            }             
		}
    
	return 1;
}

// This function counts the wins for each player
char Board_3D::WinCount3D()
{
	int BoardWin;
	int RowWin;
	int ColumnWin;
	int XCounter = 0;
	int OCounter = 0;
	int WinnerX = 0;
	int WinnerO = 0;
	
	// ** Win Counter **
	
	// ** Boards Parallel to front face of 3D board **
	
	// ** Horizontal Wins **
	// Ex. (B1, R1, C1; B1, R1, C2; B1, R1, C3)
	
	for(BoardWin = 0; BoardWin < Max; BoardWin++)
	{
		for(RowWin = 0; RowWin < Max; RowWin++)
		{
			XCounter = 0; // Resets count for each Row loop
			OCounter = 0;
			for(ColumnWin = 0; ColumnWin < Max; ColumnWin++)
			{
				if(XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
				{
					XCounter ++;
				}
				else if(XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
				{
					OCounter ++;
				}
			}
			// Increments Winner X if X got a tic-tac-toe
			if(XCounter == 3)
			{
				WinnerX++;
			}
			// Increments Winner O if O got a tic-tac-toe
			else if(OCounter == 3)
			{
				WinnerO++;
			}
		}
	}
	
	// ** Vertical Wins **
	// Ex. (B1, R1, C1; B1, R2, C1; B1, R3, C1)
	
	for(BoardWin = 0; BoardWin < Max; BoardWin++)
	{
		for(ColumnWin = 0; ColumnWin < Max; ColumnWin++)
		{
			XCounter = 0; // Resets Counter for each Column Loop
			OCounter = 0;
			for(RowWin = 0; RowWin < Max; RowWin++)
			{
				if(XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
				{
					XCounter ++;
				}
				else if(XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
				{
					OCounter ++;
				}
			}
			if(XCounter == 3)
			{
				WinnerX++;
			}
			else if(OCounter == 3)
			{
				WinnerO++;
			}
		}
	}
	
	// ** Diagonal Wins **
	
	// ** Diagonal 1 **
	// Ex. (B1, R1, C1; B1, R2, C2; B1, R3, C3)
	// RowWin will represent Row and Column
	
	XCounter = 0;
	OCounter = 0;
	for(BoardWin = 0; BoardWin < Max; BoardWin++)
	{
		XCounter = 0; // Resets loop counter
		OCounter = 0;
		for(RowWin = 0; RowWin < Max; RowWin++)
		{
			if(XO3D[BoardWin].getvalue(RowWin, RowWin) == 'X')
			{
				XCounter ++;
			}
			else if(XO3D[BoardWin].getvalue(RowWin, RowWin) == 'O')
			{
				OCounter ++;
			}
		}
		if(XCounter == 3)
		{
			WinnerX++;
		}
		else if(OCounter == 3)
		{
			WinnerO++;
		}
	}
	
	// ** Diagonal 2 **
	// Ex. (B1, R3, C1; B1, R2, C2; B1, R1, C3)
	
	for(BoardWin = 0; BoardWin < Max; BoardWin++)
	{
		ColumnWin = 0; // Resets Column number to 0 for each Row
		XCounter = 0; // Resets Count to 0
		OCounter = 0;
		
		for(RowWin = 2; RowWin > -1; RowWin--)
		{
		
			if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
			{
				XCounter++; // Increments X if a X is found in a space
			}
			else if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
			{
				OCounter++; // Increments O if an O is found in a space
			}
			
			ColumnWin++;
		}
		
		if(XCounter == 3)
		{
			WinnerX++;
		}
		else if(OCounter == 3)
		{
			WinnerO++;
		}
	}
	
	// ** Boards parallel to side of 3D board ** (Vertical wins alreadys covered by the front parallel check)
		
	// ** Horizontal check **
	// Ex. (Board 1, Row 1, Column 1; B2, R1, C1; B3, R1, C1)
	
	for(RowWin = 0; RowWin < Max; RowWin++)
	{
		for(ColumnWin = 0; ColumnWin < Max; ColumnWin++)
		{
			XCounter = 0; // Resets Count to 0
			OCounter = 0;
				
			for(BoardWin = 0; BoardWin < Max; BoardWin++)
			{
				if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
				{
					XCounter++; // Increments X if a X is found in a space
				}
				else if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
				{
					OCounter++; // Increments O if an O is found in a space
				}
				
			}
			// Counts the number of tic-tac-toes made
			if (XCounter == 3)
			{
				WinnerX++;
			}
			else if (OCounter == 3)
			{
				WinnerO++;
			}
		}
	}
		
	// ** Diagonal check **
	// Ex. (B1, R1, C1; B2, R2, C1; B3, R3, C1)
	// BoardWin shall represent board and row number
	
	for(ColumnWin = 0; ColumnWin < Max; ColumnWin++)
	{
		XCounter = 0; // Resets Count to 0
		OCounter = 0;
		
		for(BoardWin = 0; BoardWin < Max; BoardWin++)
		{
			if (XO3D[BoardWin].getvalue(BoardWin, ColumnWin) == 'X')
			{
				XCounter++; // Increments X if a X is found in a space
			}
			else if (XO3D[BoardWin].getvalue(BoardWin, ColumnWin) == 'O')
			{
				OCounter++; // Increments O if an O is found in a space
			}
		}
		// Counts the number of tic-tac-toes made
		if (XCounter == 3)
		{
			WinnerX++;
		}
		else if (OCounter == 3)
		{
			WinnerO++;
		}
	}
		
	// ** Second Diagonal check **
	// Ex. (B1, R3, C1; B2, R2, C1; B3, R1, C1)
			
	for(ColumnWin = 0; ColumnWin < Max; ColumnWin++)
	{
		BoardWin = 0; // Resets Board number to 0 for each column
		XCounter = 0; // Resets Count to 0
		OCounter = 0;
			
		for(RowWin = 2; RowWin > -1; RowWin--)
		{
			
			if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
			{
				XCounter++; // Increments X if a X is found in a space
			}
			else if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
			{
				OCounter++; // Increments O if an O is found in a space
			}
				
			BoardWin++;
		}
		// Counts the number of tic-tac-toes made
		if (XCounter == 3)
		{
			WinnerX++;
		}
		else if (OCounter == 3)
		{
			WinnerO++;
		}
	}
		
	// ** Boards parallel to bottom ** (Horizontal and Vertical tic-tac-toes found by other loops)
	
	// ** Diagonal check **
	// Ex. (B1, R1, C1; B2, R1, C2; B3, R1, C3)
	// BoardWin shall represent Board and Column number
	
	for(RowWin = 0; RowWin < Max; RowWin++)
	{
		XCounter = 0; // Resets Count to 0
		OCounter = 0;
		
		for(BoardWin = 0; BoardWin < Max; BoardWin++)
		{
			if (XO3D[BoardWin].getvalue(RowWin, BoardWin) == 'X')
			{
				XCounter++; // Increments X if a X is found in a space
			}
			else if (XO3D[BoardWin].getvalue(RowWin, BoardWin) == 'O')
			{
				OCounter++; // Increments O if an O is found in a space
			}
		}
		// Counts the number of tic-tac-toes made
		if (XCounter == 3)
		{
			WinnerX++;
		}
		else if (OCounter == 3)
		{
			WinnerO++;
		}
	}
		
	// ** Second Diagonal check **
	// Ex. (B1, R1, C3; B2, R1, C2; B3, R1, C1)
	
	for(RowWin = 0; RowWin < Max; RowWin++)
	{
		BoardWin = 0; // Resets Board number to 0 for each column
		XCounter = 0; // Resets Count to 0
		OCounter = 0;
		
		for(ColumnWin = 2; ColumnWin > -1; ColumnWin--)
		{
			
			if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'X')
			{
				XCounter++; // Increments X if a X is found in a space
			}
			else if (XO3D[BoardWin].getvalue(RowWin, ColumnWin) == 'O')
			{
				OCounter++; // Increments O if an O is found in a space
			}
					
			BoardWin++;
		}
		// Counts the number of tic-tac-toes made
		if (XCounter == 3)
		{
			WinnerX++;
		}
		else if (OCounter == 3)
		{
			WinnerO++;
		}
	}
		
	// ** Diagonal Boards **
	// Vertical and horizantal wins already found
		
	// ** Diagonal check **	
	// (B1, R1, C1; B2, R2, C2; B3, R3, C3)
	// RowWin shall represent Row, Column, and Board
	
	XCounter = 0; // Resets Count to 0
	OCounter = 0;
	
	for(RowWin = 0; RowWin < Max; RowWin++)
	{
		if (XO3D[RowWin].getvalue(RowWin, RowWin) == 'X')
		{
			XCounter++; // Increments X if a X is found in a space
		}
		else if (XO3D[RowWin].getvalue(RowWin, RowWin) == 'O')
		{
			OCounter++; // Increments O if an O is found in a space
		}
	}
	// Counts the number of tic-tac-toes made
	if (XCounter == 3)
	{
		WinnerX++;
	}
	else if (OCounter == 3)
	{
		WinnerO++;
	}
	
	// ** Second Diagonal check **
	// (B1, R3, C1; B2, R2, C2; B3, R1, C3)
	// BoardWin shall represent Board and column
	
	
	BoardWin = 0; // Resets Board number to 0 for each column
	XCounter = 0; // Resets Count to 0
	OCounter = 0;
		
	for(RowWin = 2; RowWin > -1; RowWin--)
	{
		
		if (XO3D[BoardWin].getvalue(RowWin, BoardWin) == 'X')
		{
			XCounter++; // Increments X if a X is found in a space
		}
		else if (XO3D[BoardWin].getvalue(RowWin, BoardWin) == 'O')
		{
			OCounter++; // Increments O if an O is found in a space
		}
			
		BoardWin++;
	}
	// Counts the number of tic-tac-toes made
	if (XCounter == 3)
	{
		WinnerX++;
	}
	else if (OCounter == 3)
	{
		WinnerO++;
	}
		
	// ** Third Diagonal check **
	// (B1, R3, C3; B2, R2, C2; B3, R1, C1)
	// RowWin shall represent Row and Column
	
	BoardWin = 0; // Resets Board number to 0 for each column
	XCounter = 0; // Resets Count to 0
	OCounter = 0;
	
	for(RowWin = 2; RowWin > -1; RowWin--)
	{
		
		if (XO3D[BoardWin].getvalue(RowWin, RowWin) == 'X')
		{
			XCounter++; // Increments X if a X is found in a space
		}
		else if (XO3D[BoardWin].getvalue(RowWin, RowWin) == 'O')
		{
			OCounter++; // Increments O if an O is found in a space
		}
				
		BoardWin++;
	}
	// Counts the number of tic-tac-toes made
	if (XCounter == 3)
	{
		WinnerX++;
	}
	else if (OCounter == 3)
	{
		WinnerO++;
	}	
	
	// ** Fourth Diagonal check **
	// (B1, R1, C3; B2, R2, C2; B3, R3, C1)
	// BoardWin shall represent Board and Row
	
	BoardWin = 0; // Resets Board number to 0 for each column
	XCounter = 0; // Resets Count to 0
	OCounter = 0;
	
	for(ColumnWin = 2; ColumnWin > -1; ColumnWin--)
	{
		
		if (XO3D[BoardWin].getvalue(BoardWin, ColumnWin) == 'X')
		{
			XCounter++; // Increments X if a X is found in a space
		}
		else if (XO3D[BoardWin].getvalue(BoardWin, ColumnWin) == 'O')
		{
			OCounter++; // Increments O if an O is found in a space
		}
			
		BoardWin++;
	}
	// Counts the number of tic-tac-toes made
	if (XCounter == 3)
	{
		WinnerX++;
	}
	else if (OCounter == 3)
	{
		WinnerO++;
	}
	
	if(WinnerX > WinnerO)
	{
		return 'X'; // Returns X if X got the most tic-tac-toes
	}
	
	else if(WinnerX < WinnerO)
	{
		return 'O'; // Returns O if O got the most tic-tac-toes
	}
	
	else if(WinnerX == WinnerO)
	{
		return 'N'; // Returns N if X and O got an equal amount of tic-tac-toes
	}

}

void Board_3D::resetboard3d()
{
     XO3D[0].XO[0][0]=' ';
     XO3D[0].XO[0][1]=' ';
     XO3D[0].XO[0][2]=' ';
     XO3D[0].XO[1][0]=' ';
     XO3D[0].XO[1][1]=' ';
     XO3D[0].XO[1][2]=' ';
     XO3D[0].XO[2][0]=' ';
     XO3D[0].XO[2][1]=' ';
     XO3D[0].XO[2][2]=' '; 

     XO3D[1].XO[0][0]=' ';
     XO3D[1].XO[0][1]=' ';
     XO3D[1].XO[0][2]=' ';
     XO3D[1].XO[1][0]=' ';
     XO3D[1].XO[1][1]=' ';
     XO3D[1].XO[1][2]=' ';
     XO3D[1].XO[2][0]=' ';
     XO3D[1].XO[2][1]=' ';
     XO3D[1].XO[2][2]=' ';      
     
     XO3D[2].XO[0][0]=' ';
     XO3D[2].XO[0][1]=' ';
     XO3D[2].XO[0][2]=' ';
     XO3D[2].XO[1][0]=' ';
     XO3D[2].XO[1][1]=' ';
     XO3D[2].XO[1][2]=' ';
     XO3D[2].XO[2][0]=' ';
     XO3D[2].XO[2][1]=' ';
     XO3D[2].XO[2][2]=' '; 
     }

int competition::ComputerCmove()
{
    MakeRandomMove3d();
    
}

int competition::ComputerTmove(int turn)
{
  ComputerTurn3D(turn);  
    
}

void competition::convertTboard()
{
if ((whichrow==0) &&(whichcolumn==0))
whichmovemade=1;
else if ((whichrow==0) &&(whichcolumn==1))
whichmovemade=2;
else if ((whichrow==0) &&(whichcolumn==2))
whichmovemade=3;
else if ((whichrow==1) &&(whichcolumn==0))
whichmovemade=4;
else if ((whichrow==1) &&(whichcolumn==1))
whichmovemade=5;
else if ((whichrow==1) &&(whichcolumn==2))
whichmovemade=6;
else if ((whichrow==2) &&(whichcolumn==0))
whichmovemade=7;
else if ((whichrow==2) &&(whichcolumn==1))
whichmovemade=8;
else if ((whichrow==2) &&(whichcolumn==2))
whichmovemade=9;     

whichboardmove=whichboardIsIt;

square3d[whichboardmove].square[whichmovemade]='X';   
     }

void competition::convertCboard()
{
     if(whichmovemade == 1)
     {
         whichrow = 0;  
         whichcolumn = 0;           
     }
     else if(whichmovemade == 2)
     {
         whichrow = 0;  
         whichcolumn = 1;           
     }
     else if(whichmovemade == 3)
     {
         whichrow = 0;  
         whichcolumn = 2;           
     }
     else if(whichmovemade == 4)
     {
         whichrow = 1;  
         whichcolumn = 0;           
     }
     else if(whichmovemade == 5)
     {
         whichrow = 1;  
         whichcolumn = 1;           
     }
     else if(whichmovemade == 6)
     {
         whichrow = 1;  
         whichcolumn = 2;           
     }
     else if(whichmovemade == 7)
     {
         whichrow = 2;  
         whichcolumn = 0;           
     }
     else if(whichmovemade == 8)
     {
         whichrow = 2;  
         whichcolumn = 1;           
     }
     else if(whichmovemade == 9)
     {
         whichrow = 2;  
         whichcolumn = 2;           
     }
     
     whichboardIsIt = whichboardmove;
     
     XO3D[whichboardIsIt].CompPlaceO(whichrow, whichcolumn, whichboardIsIt);
}


void competition::displayboard4d()
{
     DisplayBoard3d();
     
     }
void competition::checkforscore4d()
{
     Checkforscore3d();
     
     }

void competition::reset4d()
{
     reset3d();
     resetboard3d();
     
     }
void competition::resetscore4d()
{
     resetscore3d();
     }
