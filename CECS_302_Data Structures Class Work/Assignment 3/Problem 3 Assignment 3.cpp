//Christopher Bass
//10/19/14
//CECS 302
//3.22 Write a Program to evaluate a postfix expression.

#include<iostream>
#include<cctype>
#include<stack>
#include<conio.h>
using namespace std;

//Returns value when used on two operands
int evalTwo(int op1, int op2, char operate) {
   switch (operate) {
      case '*': return op2 * op1;
      case '/': return op2 / op1;
      case '+': return op2 + op1;
      case '-': return op2 - op1;
      default : return 0;
   }
}

//Evaluate Postfix Expression
int evaluatePost(char postfix[], int size) {
   stack<int> stack;
   int i = 0;
   char ch;
   int newValue;
   while (i < size) {
      ch = postfix[i];
      if (isdigit(ch)) {
         stack.push(ch-'0');
      }
      else {
         int op1 = stack.top();
         stack.pop();
         int op2 = stack.top();
         stack.pop();
         newValue = evalTwo(op1, op2, ch);
         stack.push(newValue);
      }
      i++;
   }
   return newValue;
}

// Main Start
int main() {
   int choice; 
   char postfix[] = {};
   
   cout<<"Enter in your expression with no spaces:"<<endl;
   cin>>postfix;
   int size = (int) strlen(postfix);
   int value = evaluatePost(postfix, size);
   cout<<"\nPostfix Expression = "<<value;
   cout<<endl;
  


   getch();
   return 0;
}

