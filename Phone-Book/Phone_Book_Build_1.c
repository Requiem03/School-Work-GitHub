//Christopher Bass
//CECS 130 Lab 6
//Phone Book
//2-12-13


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

typedef struct
{
char firstname[20];
char lastname[20];
char phone_number[20];
       
       } phone_book;
       
main()
{
phone_book *myphonebook=NULL;      
int x, m, z, i,test;
char fname[20];
char lname[20];
x=0;
int entrycount=0;

int choice;

while (choice!=4)
{
       printf("Phone Book Application\n");
 printf("(1)Add Friend\n");
 printf("(2)Delete Friend\n");
 printf("(3)Show Phone Book\n");
 printf("(4)Exit\n");
 scanf("%i", &choice);
      
      switch (choice)
      {
             case 1:
                 
                  myphonebook=(phone_book *)realloc(myphonebook,(entrycount+1)*sizeof(phone_book));
                  
                  printf("(1)Add Friend Selected\n");
                  printf("First Name:\n");
                  scanf("%s",myphonebook[entrycount].firstname);
                  printf("\nLast Name:\n");
                  scanf("%s",myphonebook[entrycount].lastname);      
                  printf("\nPhone Number:\n");
                  scanf("%s",myphonebook[entrycount].phone_number);
                  printf("\nRecord added to the phone book\n\n");
                  
                  entrycount++;
                  break;
                  
             case 2:
                  printf("\n(2)Delete Friend Selected\n");         
                  printf("Enter First Name:\n");
                  scanf("%s",fname);
                  test=-1;
                          for (i=0;i<entrycount;i++)
                          {
                          if ( strcmp(fname, myphonebook[i].firstname)==0)
                             {
                             printf("Enter Last Name:\n");
                             scanf("%s",lname);
                                               if ( strcmp(lname, myphonebook[i].lastname)==0)
                                               {                    
                                               test=i;
                                               }
                            else
                            {
                            printf("Invalid Entry\n\n");
                                               }break;   
                             }
                                
                          }
                          if(test!=-1)
                          {          
                              for(i=test;i<entrycount-1;i++)
                              {
                              strcpy(myphonebook[i].firstname,myphonebook[i+1].firstname);
                              strcpy(myphonebook[i].lastname,myphonebook[i+1].lastname);
                              strcpy(myphonebook[i].phone_number,myphonebook[i+1].phone_number);
                              }
                              myphonebook=(phone_book *)realloc(myphonebook,(entrycount-1)*sizeof(phone_book));
                              entrycount--;
                              printf("Record Deleted From Phonebook.\n\n");
                              break;
                          }
         
         
          
             case 3:
                 
             printf("\n\n(3)Phone Book Entries:"); 
             for (i=0;i<entrycount;i++)
                 { 
                 printf("\n%s\n%s\n%s\n\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number);       
                 }   
                 break;
                           
     
             case 4:
                free(calloc);
                free(malloc);
                free(realloc);
                break;
       
             default:
                     printf("Not a Valid Choice\n"); 
                     break;
       }      
}      

      
getch();
return 0;      
      }
