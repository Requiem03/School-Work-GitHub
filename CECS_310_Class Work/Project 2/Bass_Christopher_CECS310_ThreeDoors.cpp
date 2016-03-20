//Christpher Bass
//CECS 310
//4/11/13
//Three Doors Assigment

#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

using namespace std;

int selectdoor();//prototype for function that randomly picks number 1-3


int main()
{
  int gamecount3=0;
  int gamecount2=0;
  int gamecount=0;
  int playerchosendoor=0; 
  int playerchosendoor2=0;
  int goatdoor=0;
  int showndoor=0;
  int cardoor=0; 
  int option=0;
  int staywins=0; 
  int switchwins=0;
  int otherprize=0;
  int randomwins=0;
  srand(time(NULL));  
  


do//Always keep origional choice
{    
    do
    {
    cardoor=selectdoor(); //chooses which door the car is behind   
    otherprize=selectdoor();//which door the other prize is behind
    goatdoor=selectdoor();//chooses which door the goat is behind
    
    }while(cardoor==goatdoor||cardoor==otherprize||goatdoor==otherprize);//makes each door is different
    
        playerchosendoor=selectdoor();//player chooses door 1-3
       
       do//player is shown the door that is neither goat or car then keeps choice
       { 
       showndoor=selectdoor();                                                                     
       }while (playerchosendoor==showndoor||showndoor==cardoor);

       
       if(playerchosendoor==cardoor)//Increases count each time player wins
       {staywins++;}                          
                                 
                                      
                                 
                                 gamecount++;
                                 }while(gamecount < 10000);


do//Always switch doors
{    
    do
    {
    cardoor=selectdoor(); //chooses which door the car is behind   
    otherprize=selectdoor();//chooses which door the host shows
    goatdoor=selectdoor();//chooses which door the goat is behind
    
    }while(cardoor==goatdoor||cardoor==otherprize||goatdoor==otherprize);//makes each door is different
    
      
      playerchosendoor=selectdoor();//player chooses door 1-3                                                                    
       
       do//player is shown 1 of the three doors
       { 
        showndoor=selectdoor();//player chooses door 1-3                                                                    
       }while (playerchosendoor==showndoor||showndoor==cardoor);
       
       do//player decides to switch door
       {
          playerchosendoor2=selectdoor();//player switches choice    
              
              }while(playerchosendoor2==showndoor||playerchosendoor==playerchosendoor2); 
       
       if(playerchosendoor2==cardoor)//Increases count each time player wins
       {switchwins++;}                          
                                 
                                 gamecount2++;
                                 }while(gamecount2 < 10000);
                                     
                                     
                                     
                                     
do//Randomly Decide to switch or stay
{
  option=(rand()%2) +1;           
           if (option==1)
           {
              do
              {
              cardoor=selectdoor(); //chooses which door the car is behind   
              otherprize=selectdoor();//which door the other prize is behind
              goatdoor=selectdoor();//chooses which door the goat is behind
    
              }while(cardoor==goatdoor||cardoor==otherprize||goatdoor==otherprize);//makes each door is different
    
              playerchosendoor=selectdoor();//player chooses door
       
              do//player is shown the door that is neither goat or car then keeps choice
              { 
              showndoor=selectdoor();                                                                     
              }while (playerchosendoor==showndoor||showndoor==cardoor);

       
              if(playerchosendoor==cardoor)//Increases count each time player wins
              {randomwins++;}               
                        
           }                                 
           
           if (option==2)
           {
            do
            {
            cardoor=selectdoor(); //chooses which door the car is behind   
            otherprize=selectdoor();//chooses which door the host shows
            goatdoor=selectdoor();//chooses which door the goat is behind
    
            }while(cardoor==goatdoor||cardoor==otherprize||goatdoor==otherprize);//makes each door is different
    
      
            playerchosendoor=selectdoor();//player chooses door 1-3                                                                    
       
            do//player is shown 1 of the three doors
            { 
            showndoor=selectdoor();//player chooses door 1-3                                                                    
            }while (playerchosendoor==showndoor||showndoor==cardoor);
       
            do//player decides to switch door
            {
            playerchosendoor2=selectdoor();//player switches choice    
              
            }while(playerchosendoor2==showndoor||playerchosendoor==playerchosendoor2); 
       
            if(playerchosendoor2==cardoor)//Increases count each time player wins
            {randomwins++;}          
              
            }                                   
                                     
                                     
                                     
                                     gamecount3++;
                                     }while(gamecount3 < 10000);                                     
                                     
                                     
                                     
                                     
                                     
int percentagestay=(100*staywins)/10000;
int percentageswitch=(100*switchwins)/10000;
int percentagerandom=(100*randomwins)/10000;
                                                                  
cout<<"The player won the car "<<staywins<<" times by not switching "<<percentagestay<<"%"<<endl;
cout<<"The player won the car "<<switchwins<<" times by switching "<<percentageswitch<<"%"<<endl;    
cout<<"The player won the car "<<randomwins<<" times by randomly switching "<<percentagerandom<<"%"<<endl;    
getch();    
return 0;   
}

int selectdoor()
{
  return (rand()%3)+1;  
    
}
