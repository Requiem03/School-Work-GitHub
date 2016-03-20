//Christopher Bass
//CECS 130 Lab 7
//Phone Book
//2-19-13


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
int x, m, z, i, test, n;
char fname[20];
char lname[20];
char fname2[20];
char lname2[20];
x=0;
int entrycount=0;
int randomphonenumber, randomfirstname, randomlastname;
int choice;



while (choice!=8)
{
       printf("\nPhone Book Application\n");
 printf("(1)Add Friend\n");
 printf("(2)Delete Friend\n");
 printf("(3)Show Phone Book\n");
 printf("(4)Sort Alphabetically by last name\n");
 printf("(5)Search for a phone number\n");
 printf("(6)Randomly Select Number\n");
 printf("(7)Delete All\n");
 printf("(8)Exit\n");
 printf("Select a Task to Perform:\n");
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
                 
                 printf("\n\n(3)Phone Book Entries\n:"); 
                 for (i=0;i<entrycount;i++)
                 { 
                 printf("\n%s\n%s\n%s\n\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number);       
                 }   
                 break;
                           
     
             case 4:
                  printf("\nSort By Last Name:\n");
             int f, j;            
             phone_book temp1;
             int didswap=1, limit = entrycount-1;
             
             while (didswap)
             {
                  didswap=0;
                   for (f=0; f<limit; f++)
                   {
                       if (strcmp(myphonebook[f].lastname, myphonebook[f+1].lastname)>0)
                       {
                                                           temp1=myphonebook[f];
                                                           myphonebook[f]=myphonebook[f+1];
                                                           myphonebook[f+1]=temp1;
                                                           didswap=1;
                       } 
                   }
                                                           limit--;
             }
                printf("Sorted\n");                                          
                                                          
                  
             
             
             
             
                  break;
             
             case 5:
                  printf("Search for a Phone Number\n");
                  printf("Enter First Name:\n");
                  scanf("%s",&fname2);
                  printf("Enter Last Name:\n");
                  scanf("%s",&lname2);
                  
                  for (i=0;i<entrycount;i++)
                          {
                          if (strcmp(fname2, myphonebook[i].firstname)==0)
                             {
                             
                                               if (strcmp(lname2, myphonebook[i].lastname)==0)
                                               {                    
                                               printf("\n%s\n%s\n%s\n\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number);
                                               }
                                                  else
                                                  {
                                                  printf("Invalid Entry\n\n");
                                                  }break;  
                             }
                          }
                  
                  break;
             
             case 6:
                  printf("Randomly Select Phone Number\n");
                  randomlastname=rand()%entrycount;
                  myphonebook[randomlastname];
             
                  printf("%s\n %s\n %s\n\n",myphonebook[randomlastname].firstname, myphonebook[randomlastname].lastname, myphonebook[randomlastname].phone_number);
                  break;
             
             case 7:
                  printf("Delete All Phone Numbers\n\n");
             
                  myphonebook=(phone_book *)realloc(myphonebook,(0)*sizeof(phone_book));
                  entrycount=0;
                  printf("Recods Deleted from Phone Book\n\n");
             
                  break;
             
             case 8:
                free(myphonebook);
                
                break;
       
             default:
                     printf("Not a Valid Choice\n"); 
                     break;
       }      
}      

      
getch();
return 0;      
      }
