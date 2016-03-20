//Christopher Bass
//CECS 130 Lab 5
//Interactive Stories
//2-5-13


#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>

main()
{
srand(time(NULL));
int irandomplace, irandomday, irandomobjects, irandomcolors, irandomotherplaces, randomstuffidid, randomending; //declare randoms
char age[3];
char firstname [16];
char lastname [16];
char colors[][100]={"black", "green", "yellow", "blue", "red", "orange"};
char objects[][100]={"wallet", "cell phone", "laptop", "car"};
char *pplace[]={"Park", "Store", "Gym", "Mall"};
char *pday[]={"Monday", "Tuesday", "Wednsday", "Thursday", "Friday"};
char otherplaces[][100]={"home", "friends house", "job"};
char stuffidid[][100]={"got in a fight", "picked up a stray cat", "spent way to much money"};
char alternateending[][100]={"but somebody must have already taken it", "and someone had turned it into the lost and found"};


randomending=rand()%2;
randomstuffidid=rand()%3;
irandomotherplaces=rand()%3;
irandomplace=rand()%4;
irandomday=rand()%5;
irandomobjects=rand()%4;
irandomcolors=rand()%6;
*pplace[irandomplace];
*pday[irandomday];
objects[irandomobjects];
colors[irandomcolors];
otherplaces[irandomotherplaces];
stuffidid[randomstuffidid];
alternateending[randomending];





printf("Enter your first name:\n");
scanf("%s", firstname);
printf("\nEnter your last name:\n");
scanf("%s", lastname);
printf("\nEnter your age:\n");
scanf("%s", age);

printf("\nMy name is %s %s and I am %s years old.\n", firstname,lastname, age);
printf("I went to the %s on %s. \nWhile I was there I %s. \n", pplace[irandomplace], pday[irandomday], stuffidid[randomstuffidid]);      
printf("I did not realize until I got to my %s later that day, \nthat I had left my %s %s at the %s.\n", otherplaces[irandomotherplaces], colors[irandomcolors] ,objects[irandomobjects],pplace[irandomplace]);
printf("I went back the next day %s\n",alternateending[randomending]);      
printf("\n                   The End\n");



      
      
      
      
      
getch();    
return 0;       
      }

