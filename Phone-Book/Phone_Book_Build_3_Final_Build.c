//Christopher Bass
//CECS 130 Lab 8
//Phone Book
//2-26-13


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
char answer[20];
char Y[20]="Y";
char N[20]="N";
x=0;
int entrycount=0;
int randomphonenumber, randomfirstname, randomlastname;
int choice;
FILE *fp, *fwrite, *fread; //file pointers
int filecount=0;
char filename[30];
char userfilename[30];

while (choice!=9)
{
       printf("\nPhone Book Application\n");
 printf("(0)Open Phonebook File\n");
 printf("(1)Add Friend\n");
 printf("(2)Delete Friend\n");
 printf("(3)Show Phone Book\n");
 printf("(4)Sort Alphabetically by last name\n");
 printf("(5)Search for a phone number\n");
 printf("(6)Randomly Select Number\n");
 printf("(7)Delete All\n");
 printf("(8)Save to File\n");
 printf("(9)Exit\n");
 printf("Select a Task to Perform:\n");
 scanf("%i", &choice);
      
      switch (choice)
      {
             case 0://read from file
                  entrycount=0;
                  printf("Would you like to open a file Y/N?\n");
                  scanf("%s", &answer);
                              if (strcmp(answer, Y)==0)
                              {
                                 printf("Would You Like to open a specific file(Y/N):\n");//asks user if the would like to open a specific file or default file
                                 scanf("%s",&answer);
                                 if (strcmp(answer, Y)==0)
                                 {
                                 printf("Enter File Name:\n");
                                 scanf("%s",filename);
                                 fread=fopen(filename, "r");
                                                       if (fread!=NULL)
                                                       {
                                                       while(!feof(fread))
                                                       {
                                          
                                                       myphonebook=(phone_book *)realloc(myphonebook,(entrycount+1)*sizeof(phone_book));
                                             
                                                       fscanf(fread,"\n%s\n%s\n%s\n",myphonebook[entrycount].firstname, myphonebook[entrycount].lastname, myphonebook[entrycount].phone_number);
                                                       printf("\n%s\n%s\n%s\n",myphonebook[entrycount].firstname, myphonebook[entrycount].lastname, myphonebook[entrycount].phone_number);                  
                                          
                                                       entrycount++;
                                                       }
                                                       fclose(fread);    
                                                       }
                                                    
                                 }
                                 else
                                 {
                                 fread=fopen("input.txt", "r");
                                 if (fread!=NULL)
                                 {
                                    while(!feof(fread))
                                    {
                                          
                                             myphonebook=(phone_book *)realloc(myphonebook,(entrycount+1)*sizeof(phone_book));
                                             
                                             fscanf(fread,"\n%s\n%s\n%s\n",myphonebook[entrycount].firstname, myphonebook[entrycount].lastname, myphonebook[entrycount].phone_number);
                                             printf("\n%s\n%s\n%s\n",myphonebook[entrycount].firstname, myphonebook[entrycount].lastname, myphonebook[entrycount].phone_number);                  
                                          
                                             entrycount++;
                                    }
                                    fclose(fread);    
                                 }
                                 }
                              }
                
                  break;
             case 1://Add Friend
                 
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
                  
             case 2://Delete Friend
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
         
         
          
             case 3://Lists all phone book entries
                 
                 printf("\n\n(3)Phone Book Entries:\n"); 
                 for (i=0;i<entrycount;i++)
                 { 
                 printf("\n%s\n%s\n%s\n\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number);       
                 }   
                 break;
                           
     
             case 4://Sorts phone book entries by Last Name
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
             
             case 5://Searches for Phone Number
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
             
             case 6://Randomly Selects Phone Number
                  printf("Randomly Select Phone Number\n");
                  randomlastname=rand()%entrycount;
                  myphonebook[randomlastname];
             
                  printf("%s\n %s\n %s\n\n",myphonebook[randomlastname].firstname, myphonebook[randomlastname].lastname, myphonebook[randomlastname].phone_number);
                  break;
             
             case 7://Deletes all Phone Book Entries
                  printf("Delete All Phone Numbers\n\n");
             
                  myphonebook=(phone_book *)realloc(myphonebook,(0)*sizeof(phone_book));
                  entrycount=0;
                  printf("Recods Deleted from Phone Book\n\n");
             
                  break;
             
             case 8://Saves file
               
                            
                printf("Would you like to save your file (Y/N)?\n");
                scanf("%s", &answer);
                
                if (strcmp(answer, Y)==0)
                {
                 printf("Would you like to name your file(Y/N)?\n");//Asks user if they would like to name the file if not it gets a default name.
                 scanf("%s",&answer);
                                     if (strcmp(answer, Y)==0)
                                     {
                                     printf("Enter File Name:");                   
                                     scanf("%s",&userfilename);
                                     fwrite=fopen(userfilename, "w");
                                           if (fwrite!=NULL)//Check if File was opened Successfully
                                           {
                                              for (i=0; i<entrycount; i++)
                                              {
                                              fprintf(fwrite,"\n%s\n%s\n%s\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number); 
                                              
                                              }
                                           
                                           fclose(fwrite);//close file after use
                                           }
                
                                           else 
                                           {printf("Error Opening File");}
                                           
                                           
                                     }
                 else
                {
                fwrite=fopen("input.txt", "w");
                                           if (fwrite!=NULL)//Check if File was opened Successfully
                                           {
                                              for (i=0; i<entrycount; i++)
                                              {
                                              fprintf(fwrite,"\n%s\n%s\n%s\n",myphonebook[i].firstname, myphonebook[i].lastname, myphonebook[i].phone_number); 
                                              
                                              }
                                          
                                           fclose(fwrite);//close file after use
                                           }
                
                                           else 
                                           {printf("Error Opening File");}
                
                                           }
              
                }
                
                
                break;
       
            case 9:
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
