//Christopher Bass
//CECS 302 Assignment 1
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
         int choice=0, size=0, entry=0, entries=0, i=0, min=0, max=0;
         T myArray[size]; 
         }
         
         int collectionsize(T myArray[size]){//Current Size and Display array.
         int choice, size, entry, entries, i, min, max;
         entries=0;
         cout<<"\n"<<"The current size of the array is "<< size<<"\n"<<endl;
         for (i=0; i<size; i++){
         cout<<"Array Entry #"<<entries+1<<".) "<<myArray[i]<<"\n"<<endl;
         
         entries++;
                   }
         
         }//end function
         
      private:
              
             
      
};
      
     
      
int main()
{
int choice, size=0, entry, entries=0, i=0, min=0, max=0;
OrderedCollection<int> collection; 
  collection.myArray[size];  
  
 while(choice!=7)
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
 
    switch(choice)
    {
    case 1://Current Size
        /*
         entries=0;
         cout<<"\n"<<"The current size of the array is "<< size<<"\n"<<endl;
         for (i=0; i<size; i++){
         cout<<"Array Entry #"<<entries+1<<".) "<<collection.myArray[i]<<"\n"<<endl;
         
         entries++;
         }
         */
         collection.collectionsize();
         
         break;
    case 2://Find Min
         min=0;
        // cout<<"\n Array Size is "<<size<<"\n";
        
         for(i=0; i < size; ++i){
 
                  if (size==0){
                              cout<<"\nThe array is empty\n"<<endl;
                              }
                  else if(collection.myArray[min]>collection.myArray[i]){
                       min=i;
                       }
                  }
                  cout<<"\n"<<collection.myArray[min]<<" is the min\n"<<endl;
         
         break;
    case 3://Find Max
          max=0;
         //cout<<"\n Array Size is "<<size<<"\n";
        
         for(i=0; i < size; i++){
 
                  if (size==0){
                              cout<<"\nThe array is empty\n"<<endl;
                              }
                  else if(collection.myArray[max]<collection.myArray[i]){
                       max=i;
                       }
                  }
                  cout<<"\n"<<collection.myArray[max]<<" is the Max\n"<<endl;
         
         break;
    case 4://Insert
         
         cout<<"\nEnter a number:\n"<<endl;
         cin>>collection.myArray[size];
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
         collection.myArray[size]=0;
         cout<<"\n The array is now empty.\n"<<endl;
         break;
    case 7:
       //Exits the Program
         break;  
                  
    }
 
 }
getch();
return 0;    
}
//End of Main Program



