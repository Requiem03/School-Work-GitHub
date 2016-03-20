//Christopher Bass
//CECS 130 Lab 3
//Calculator
//1-22-13


#include <stdio.h>
#include <conio.h>




int main()
{
int x;
int a; //Declared user input menu selection
      //Calculator Menu
int m, n, z; //Declared for modulus
float b; //floats declared for addition,subtraction,multiplication, and division
float c;
float d;      
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
printf("(7) Exit\n");

printf("\n please choose an operation:\n");
scanf("%d",&a);

if(a==1)// addition
{

printf("Enter the first number:\n");       
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=b+c;
printf("\n%.2f+%.2f=%.2f\n",b,c,d);

          }
if (a==2) //subtraction
{

printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=b-c;
printf("\n%.2f-%.2f=%.2f\n",b,c,d);

}

if (a==3)//multiplication
{
printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=b*c;
printf("\n%.2f*%.2f=%.2f\n",b,c,d);
                         }

if (a==4)//Division
{
printf("Enter the first number:\n");
scanf("%f",&b);
printf("Enter the second number:\n");
scanf("%f",&c);
d=b/c;
printf("\n%.2f/%.2f=%.2f\n",b,c,d);
                   }

if (a==5)//Modulus

{

printf("Enter the first number:\n");
scanf("%d",&n);
printf("Enter the second number:\n");
scanf("%d",&z);      
m=n%z;
printf("%d(%%)%d= %d\n",n,z,m);         
         }


if (a==6)//Test if Prime
{        
int h,  j=2;

printf("Enter a number to test if it is prime:\n");
scanf("%d", &h);

for (j=2; j <= h - 1; c++)
{
    if (h%j == 0)
    
    printf ("%d is not prime.\n", h); 
   else printf("%d is prime.\n", h);
   break;

           }
           }
if (a==7)// Exit

{
x=7;        
         }         
         






}
getch();
return 0;
     }
