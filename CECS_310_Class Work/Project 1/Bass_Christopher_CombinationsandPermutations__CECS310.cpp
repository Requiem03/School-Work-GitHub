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
#include<vector>


using namespace std;




void recursiveFunc(int num, string &fullString, string partString, int maxNum);
void ListPermutations(string curritem, string currentcomb);


int main()
{
int n=0;//number of total items
int r=0;//number in group
int choice=0;
string curritem[300];
string curritem2[300];
string tmp;
string tmp2;
string origionalcomb[300];
string currentcomb2[300];
string currentcomb[300];
string lastcomb[300];
char pORc;
int numtodo;//number of things to do
int k=0;
int idx;
int  minIndex;
string newcurritem[300];
string newcurrentcomb[300];
int indecie;
int idx2; 
while (choice!=2)    
{
cout<<"(1)Run Program"<<endl;
cout<<"(2)Exit Program"<<endl;    
cin>>choice;    
    
switch (choice)
{
       case 1://Runs the program and sorts the data
       {
       ifstream unsorted;
       unsorted.open("infile.dat");     
       unsorted>>numtodo;//reads first number into variable numtodo
                       
                         
                         for(int i=0; i<numtodo; i++)
                         {
                         unsorted>>pORc;//reads p or c pORc
                         unsorted>>n; //reads second number into n (#of total items)
                         unsorted>>r; //reads third number into r (# of items in combination)
  
                                     for(int j=0; j<n; j++)//loop reads in the rest of the items into string currentitem
                                     {unsorted>>curritem[j];}
                                               
                                       for(int i=0; i< n-1; i++)//Bubble sort puts curritem string into alphabetical order
                        {
                        minIndex=i;
                
                                   for(int j=i+1;j<n;j++)
                                   {
                                   if(curritem[j]<curritem[minIndex])
                                   {   
                                   minIndex=j;
                         
                                   }
                                              if(minIndex !=i)
                                              {
                                              tmp=curritem[i];
                                              curritem[i]=curritem[minIndex];
                                              curritem[minIndex]=tmp;
                                              }
                                   }
                         }
        
                                   for(int j=0; j<n; j++)//loop reads copies curritem into curritem2
                                     {curritem2[j]=curritem[j];}
                                   //for(int m=0; m<n;m++)//print out string
                                   //{cout<<curritem2[m]<<endl;}
                                   
                                  
                                  int k2=0;
                                  for(int i=0; i<r; i++)//saves the last combination of R to string lastcomb
                                   {       
                                   lastcomb[k2]=curritem[n-r+i+1];
                                   k2++;
                                   }
                                  
                                   for(int j=0; j<r-1; j++)//loop reads copies curritem into currentcomb
                                     {currentcomb[j]=curritem[j];}
                                     
                                     
                                   for(int j=0; j<n; j++)//loop reads copies curritem into curritem2
                                     {origionalcomb[j]=curritem[j];}
                                   
                                   for(int j=0; j<n; j++)//loop reads copies curritem into curritem2
                                     {currentcomb2[j]=curritem[j];} 
                                     
                                     
                                   
                                     if(pORc=='p'||pORc=='P')//List all Permutations
                                     {
                                       cout<<"Permutations:"<<endl<<endl;  
                                       
                                       ListPermutations(curritem[n], currentcomb[r]);      
                                       
                                       for(int gq=0; gq<r;gq++)
                                       {cout<<currentcomb[gq]<<" ";}
                                       cout<<endl<<endl;


                                          
                                            
                                                                                   
                                       }
                                     }//end for loop
                             
                              unsorted.close();    
                                   
                                   
                                   
                       
                                   
                                 
                                                       
                                
                                cout<<"Combinations:"<<endl;              
                                for(idx=r-1; idx >=0; idx--)//sets idx equal to the last item in the origional comb 2, then 1, then 0 in this case
                                {
                                  indecie=n-r+idx;//in the case indecie starts at 4 then 3, 2, 1, 0
                                                
                                 
                                  //if(origionalcomb[n-r+idx] != currentcomb[idx])
                                  //break; //idx is the location of the item not equal to the max     
                                 
                                   
                           
                                currentcomb[idx]=origionalcomb[indecie];//saves orgionalcomb indecie position to currentcomb idx position
                                
                                 for(int gq=0; gq<r-1;gq++)//prints out current combination
                                {cout<<currentcomb[gq]<<" ";}
                                cout<<endl;
                                  
                                if(currentcomb[idx]<lastcomb[idx])
                                {
                                                                
                                
                                currentcomb[idx]=origionalcomb[indecie+1];
                                
                                for(int gq=0; gq<r-1;gq++)
                                {cout<<currentcomb[gq]<<" ";}
                                cout<<endl;
                                } 
                                
                               
                               }
                              
                                 
                                
                                
                                    
                                 
                                 
                                  
                                   break;
        }//end case 1 statement


case 2:
{

//exits program     
     
     break;
     }    
    


}
}    
getch();    
return 0;   
}

void ListPermutations(string curritem, string currentcomb)
{
if (currentcomb == "") 
{
    cout << curritem << endl;
} 
else 
{   
    for (int i = 0; i < currentcomb.length(); i++) 
    {


        //test if rest[i] is unique.
        bool found = false;
        for (int j = 0; j < i; j++) 
        {
            if (currentcomb[j] == currentcomb[i])
                found = true;
        }
        if(found)
            continue;
       
       


        string newcurritem = curritem + currentcomb[i];
        string newcurrentcomb = currentcomb.substr(0, i) + currentcomb.substr(i+1);  
        ListPermutations(newcurritem, newcurrentcomb);           
    }    
}
}
