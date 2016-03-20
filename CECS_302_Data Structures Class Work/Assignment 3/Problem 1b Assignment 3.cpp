//Christopher Bass
//CECS 302
//10/19/14

/*
3.2   Swap two adjacent elements by adjusting only the links (and not the data) using:
      b.   Doubly linked list
    
*/
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <sstream>
#include <conio.h>
using namespace std;

typedef struct node {
	 int number;
	
    struct node *next; // pointer to next node in linked list
	struct node *prev;//pointer to the previous nodei in the linked list
} node;



int main(){

  
node *num0; //Create a few nodes
node *num1;
node *num2;
node *num3;
node *num4;
node *num5;

node *temp;
node *top=NULL;
node *cur=NULL; 

num0=new node;
num0->number=0;
num0->next=0;
num0->prev=0;

//----------------------------------------------
num1 = num0;
         
num1->next = new node;
num1 = num1->next;
num1->next = 0;
num1->prev=num0;
num1->number = 1; 

   
//-----------------------------------------------  
num2=num1;

num2->next = new node;
num2 = num2->next;
num2->next = 0;
num2->prev=num1;
num2->number = 2; 
//-----------------------------------------------
num3=num2;

num3->next = new node;
num3 = num3->next;
num3->next = 0;
num3->prev=num2;
num3->number = 3; 
//-----------------------------------------------
num4=num3;

num4->next = new node;
num4 = num4->next;
num4->next = 0;
num4->prev=num3;
num4->number = 4; 
//-----------------------------------------------
num5=num4;

num5->next = new node;
num5 = num5->next;
num5->next = 0;
num5->prev=num4;
num5->number = 5; 
//-----------------------------------------------
//List Nodes Before Swap
cout<<"Nodes before swapping"<<endl;
cur=num0;
while(cur){
           cout<<"Node #"<<cur->number<<"  "<<cur<<endl;
           cur=cur->next;
           }
//-----------------------------------------------
//Swat Adjacent Nodes
cout << endl;
    cout << "Now Swapping Nodes 2 and 3" << endl;
    //temp->next=num1->next;
    num1->next=num3;
    num2->next=num4;
    num3->next=num2;
    num2->prev=num3;
    num3->prev=num1;
    num4->prev=num2;
 

//-----------------------------------------------
//List Nodes After Swap
cout<<"\nTraversing the List of Nodes After swapping from Head to Tail"<<endl;
cur=num0;
while(cur){
           cout<<"Node #"<<cur->number<<"  "<<cur<<endl;
           cur=cur->next;
           }

//-----------------------------------------------
cout<<"\nTraversing the List of Nodes After swapping from Tail to Head"<<endl;
cur=num5;
while(cur){
                  cout<<"Node #"<<cur->number<<"  "<<cur<<endl;
                  cur=cur->prev;
                 }
//-----------------------------------------------
 getch();
 return 0;   
}
