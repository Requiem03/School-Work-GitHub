//Christopher Bass
//Programming Assignment 2
//3/7/13
//CECS 230

#include <algorithm>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include<cmath>


using namespace std;



int main()
{
srand((unsigned)time(0));
int choice;
string numbers1[20000];
ifstream inData;   
int exit=0;   
unsigned short int Numbers[10000], x;

int j, l, n, minIndex, tmp;
    
	while (exit!=3)
    {
    cout<<"(1)Generate 10,000 Random Numbers and Save to File"<<endl;
    cout<<"(2)Sort integers using select sort and Save to File"<<endl;
    cout<<"(3)Exit"<<endl;
    cin >> choice ;
    
    switch(choice)
    {
    
       
	case 1://Generate 10,000 random numbers 1-100 and save to integers.txt as well as store it to an array.
		{
         ofstream fout;
         fout.open("integers.txt");
         
         for (int count =0; count<10000; count++)
         {
             int y;
             Numbers[count]=(rand()%100)+1; //Changing the 100 in this line of code to whatever number you want will generate numbers 1-x (x being the highest number to generate too)
             cout<<Numbers[count]<<endl;   
             
             fout<<Numbers[count]<<"\n";
             
          }
             fout.close("integers.txt");  
         
         break;
		}
         

	case 2://Selection sort (sort the data stored in the array and save it to file sortedintegers.txt)
		{
        ofstream fout;
        fout.open("sortedintegers.txt");
        int compares=0;
        int copies=0;
        for(int i=0; i< 10000-1; i++)
        {
                minIndex=i;
                
                for(j=i+1;j<10000;j++)
                    if(Numbers[j]<Numbers[minIndex])
                      {   minIndex=j;
                          compares++;
                      }
                if(minIndex !=i)
                {
                            tmp=Numbers[i];
                            Numbers[i]=Numbers[minIndex];
                            Numbers[minIndex]=tmp;
                            copies++;
                }
         cout<<Numbers[i]<<endl;   
             
         fout<<Numbers[i]<<"\n";
        }
        fout.close();
        
        cout<<"# Of Compares:"<< compares <<endl;
        cout<<"# Of Copies:"<< copies <<endl;    
             
          
              
        
               break;
        }
    
    
    case 3://Exit Program
		{
           exit=3;   
              }
		break;
    }
     }

getch();
return 0;
}
