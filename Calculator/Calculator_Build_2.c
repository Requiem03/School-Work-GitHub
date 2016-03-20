//Christopher Bass
//CECS 130 Lab 4
//Calculator
//1-22-13


#include <stdio.h>
#include <conio.h>


float addTwoNumbers(float, float);//Addition Function Function
float SubtractTwoNumbers(float, float); //Subtraction Function
float MultiplyTwoNumbers(float, float); //Multiply Function
float DivideTwoNumbers(float, float); //Divide Function
int ModulusTwoNumbers (int, int); //Modulus Function
int TestifPrime(int); //Test Prime Function
int Factorial(int); //Factorial Function
int Power(int); //Power Function
float averagenumbers(int tennumbers[]);//Average Array Function

int main()
{
int x;
int a; //Declared user input menu selection
      //Calculator Menu
int m, n, z; //Declared for modulus
float b; //floats declared for addition,subtraction,multiplication, and division
float c;
float d;      
int h,  j=2;//declared for test if prime function
int f, g; //declared for factorial 
int p; //declared for power

float arrayofnumbers[10];//for average array function
int i;//declared for array
float avg;//for average array function
avg=0;//for average array function

x=1;
while(x==1) //infinite loop with user able to break
{

printf("\nCalculator Menu\n");
printf("(1) Addition\n");      
printf("(2) Subtraction\n");
printf("(3) Multiplication\n");
printf("(4) Division\n");
printf("(5) Modulus (integers only)\n");
printf("(6) Test if prime (integers only)\n");      
printf("(7) Factorial(integers only)\n");
printf("(8) Power\n");
printf("(9) Average Array\n");
printf("(0) Exit\n");

printf("\n please choose an operation:\n");
scanf("%d",&a);

if(a==1)// addition
{

printf("Enter the first number:\n");       
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=addTwoNumbers(b,c);
printf("\n%.2f+%.2f=%.2f\n",b,c,d);

          }
if (a==2) //subtraction
{

printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=SubtractTwoNumbers(b,c);
printf("\n%.2f-%.2f=%.2f\n",b,c,d);

}

if (a==3)//multiplication
{
printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=MultiplyTwoNumbers(b,c);
printf("\n%.2f*%.2f=%.2f\n",b,c,d);
                         }

if (a==4)//Division
{
printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=DivideTwoNumbers(b,c);
printf("\n%.2f/%.2f=%.2f\n",b,c,d);
                   }

if (a==5)//Modulus

{

printf("Enter the first number:\n");
scanf("%d",&n);
printf("Enter the second number:\n");
scanf("%d",&z);      
m=ModulusTwoNumbers(n,z);
printf("/n%d (%%) %d=%d\n",n,z,m);         
         }


if (a==6)//Test if Prime
{        

printf("Enter a number to test if it is prime:\n");
scanf("%d", &h);

TestifPrime (h);
           }

if (a==7)
{ 
printf("Enter a Number:\n");
scanf("%d", &f);
printf("%d!=%ld\n", f, Factorial(f));        
         }
         
if (a==8)
{

printf("Enter a Number:\n");
scanf("%i", &p);
Power (p);        
         }


if (a==9)
{
for (i=0;i < 10; i++) //Enter numbers into array
{
 printf ("Enter value # %d\n", i+1);
 scanf("%d", &arrayofnumbers[i]);
    
}   

for(i=0; i < 10; i++)//show what is stored in the array
{
printf("Value stored at cell %d is %d\n", i, arrayofnumbers[i]);         
         }   

avg=averagenumbers(arrayofnumbers);
         }





if (a==0)// Exit

{
x=7;        
         }         
         






}
getch();
return 0;
     }

float addTwoNumbers(float operand1, float operand2) 
{
 return operand1 + operand2;   
}// Addition Function

float SubtractTwoNumbers (float operand1, float operand2)
{
return operand1 - operand2;
      }//Subtraction Function

float MultiplyTwoNumbers (float operand1, float operand2)
{
return operand1 * operand2;
      }//Multiply Function
      
float DivideTwoNumbers (float operand1, float operand2)
{
return operand1/operand2;
      }//Divide Function
      
int ModulusTwoNumbers (int operand1, int operand2)
{
return operand1 % operand2;   
}//Modulus Function


int TestifPrime (int operand1)
{
int h, j=2 ;
h=operand1;
   for (j=2; j <= h -1; j++)
{
    if (h%j == 0)
    
   { printf ("%d is not prime.\n", h); break;}}
    
   if (j == h) printf("%d is prime.\n", h);
   

           
}//Test if Prime Function


int Factorial( int g)
{
 int l;
  long result = 1;
 
  for (l = 1; l <= g; l++)
    result = result * l;
 
  
  return result;
    
}//Factorial Function 


int Power(int p)
 {
int i;
for(i=1; i<p; i++)
{
         p *= i;
        printf("%d, %d\n", i, p);
                                 }
    return p;
}//Powers Function

float averagenumbers(int tennumbers[])
{
int i;
float avg;
avg=0;
         
for(i=0; i < 10; i++)//Find the Average of the Array
{
avg=avg+tennumbers[i];         
         }
avg=avg/10;
printf("Average is %.2f\n", avg);
return avg;
          }//Average Array Function

