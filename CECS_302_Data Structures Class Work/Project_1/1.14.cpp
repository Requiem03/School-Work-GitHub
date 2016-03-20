//Christopher Bass
//CECS 302 Assignment 1
//Problem 1.14 pg 48
//9/6/2014

#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

template <class T>
class OrderedCollection
{
      public:
      OrderedCollection()
      {
      int choice, size=0, entry, entries=0, i=0, min=0, max=0;
      T myArray[size]; 
      

   
  
 while(choice!=7)//Displays Menu after each function until you select exit
 {
    cout<<"(1) Display array Size and array."<<endl;
    cout<<"(2) Find Min"<<endl;
    cout<<"(3) Find Max"<<endl;
    cout<<"(4) Insert"<<endl;
    cout<<"(5) Remove Entry"<<endl;
    cout<<"(6) Clear Array"<<endl;
    cout<<"(7) Exit"<<endl;
    
    cin>>choice;
    if (choice==0||choice>7)
    cout<<"invalid option please try again"<<endl;
 
    switch(choice)//Switches between functions
    {
    case 1://Current Size
         entries=0;
         cout<<"\n"<<"The current size of the array is "<< size<<"\n"<<endl;
         for (i=0; i<size; i++){
         cout<<"Array Entry #"<<entries+1<<".) "<<myArray[i]<<"\n"<<endl;
         
         entries++;
         }
         break;
    
    case 2://Find Min
         min=0;
        // cout<<"\n Array Size is "<<size<<"\n";
         if (size==0){
         cout<<"\nThe array is empty\n"<<endl;
          break;
          }
        
         for(i=0; i < size; ++i){
                  if(myArray[min]>myArray[i]){
                       min=i;
                       }
                  }
                  
                  cout<<"\n"<<myArray[min]<<" is the min\n"<<endl;
         
         break;
    
    case 3://Find Max
          max=0;
         //cout<<"\n Array Size is "<<size<<"\n";
        if (size==0){
        cout<<"\nThe array is empty\n"<<endl;
        break;
        }
        
         for(i=0; i < size; i++){
                  if(myArray[max]<myArray[i]){
                       max=i;
                       }
                  }
                  cout<<"\n"<<myArray[max]<<" is the Max\n"<<endl;
         
         break;
    
    case 4://Insert
         
         cout<<"\nEnter a number:\n"<<endl;
         cin>>myArray[size];
         size=size+1;
        
         break;
    
    case 5://Remove Entry
         entry=0;
         if(size==0){
         cout<<"\nThe Array is Empty\n"<<endl;
         }
         else{
        size=size-1;
         }
         
         break;
    
    case 6: //Clear Array
         size=0;
         myArray[size]=0;
         cout<<"\n The array is now empty.\n"<<endl;
         break;
    
    case 7:
       //Exits the Program
         break;  
                  
    }
 
 }  
    }
      private:
              
             
      
};
      
     
      
int main()//start of Main Program
{
OrderedCollection<int> Numbers; 

getch();
return 0;    
}
//End of Main Program



