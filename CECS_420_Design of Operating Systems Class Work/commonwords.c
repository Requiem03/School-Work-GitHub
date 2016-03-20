//Christopher Bass
//ID#: 1408401
//CECS 420
//Project 1

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct commonWords
{
  int entries;
  char words[50];
//------------------------------------------------------------------------------------ 
//Linked List
 struct commonWords *next;
} commonList;
//------------------------------------------------------------------------------------- 
commonList *MergeSort (commonList *head);
commonList *Merge (commonList *num1, commonList *num2);
 
commonList *talloc (void)//returns size of commonList
{
  return (commonList *)malloc(sizeof(commonList));
}
//--------------------------------------------------------------------------------------
//Bubblesort


//--------------------------------------------------------------------------------------------
//Output to file and print the list.
void PrintList (commonList *head)
{
  FILE *outtext = fopen("out.txt", "w");
  fprintf(outtext,"Common Words List\n");
  while (head != NULL){
        fprintf(outtext,"%s, (%i)\n", head->words, head->entries);
        head = head->next;
  }
  //fprintf(newtext);
  fclose(outtext);
}
//-------------------------------------------------------------------------------------------

commonList *MergeSort (commonList *head)
{
  commonList *num1, *num2;
  if ((head == NULL) || (head->next == NULL))
     return head;
  num1 = head;
  num2 = head->next;
  while ((num2 != NULL) && (num2->next != NULL)){
        head = head->next;
        num2 = num2->next->next;
  }   
  num2 = head->next;
  head->next = NULL;
  return Merge(MergeSort(num1), MergeSort(num2));  
}
//----------------------------------------------------------------------------------- 
commonList *Merge (commonList *num1, commonList *num2)
{
  commonList *num3;
  if (num1 == NULL)
     return num2;
  if (num2 == NULL)
     return num1;
  
  if (num1->words[0] < num2->words[0]){	//sorted alphebetically by first letter.
	num3 = num1;
	num3->next = Merge(num1->next, num2);
		}

  else{
     num3 = num2;
     num3->next = Merge(num1, num2->next);
	}
	
  return num3;
} 
//-------------------------------------------------------------------------------------------
commonList *countEntries (commonList *head, char word[])
{
  commonList *current = NULL;
  commonList *ptr = head;
  int found = 0;
 
  while (ptr != NULL){ //Compare and count how many times each word appears.
     if (strcmp(ptr->words, word) == 0){ 
        ptr->entries++;
        found = 1;
     }
     ptr = ptr->next;
  }
   
  if ((head != NULL) && (found == 0)){
     current = talloc();
     strcpy (current->words, word);
     current->entries = 1;
     current->next = head;
     head = current;
  }
  if (head == NULL) {
    head = talloc();       
    head->next = NULL;
    strcpy (head->words, word);
    head->entries = 1;
  }
 
  return head;
}

//----------------------------------------------------------------------------------------------
//Start of Main Program
int main (int argc, char *argv[])
{
  char d;
  char c;
  int i, j = 0;
  char word[50];
  FILE *doc;    
  FILE *doc2;     
  commonList *list = NULL;
  if ((doc = fopen (argv[1],"r")) == NULL)
     printf("You did not specify a document or the document cannot be found!");
   else {//start of else   
       for (i = 0; (c = fgetc(doc)) != EOF; ++i){//start of for
           if (isalpha(c))
            word[j++] = tolower(c);
           else if ((!isalpha(c)) && (j != 0)){//start else if
              word[j++] = '\0';
              list = countEntries (list, word);
              	j = 0;
           }//end else if
       }//end for
     fclose(doc);
             
  }//end else
//----------------------------------------------------------------------------------
//Second File

if ((doc2 = fopen (argv[2],"r")) == NULL)
     printf("You did not specify a document or the document cannot be found!");
   else {//1   
       for (i = 0; (d = fgetc(doc2)) != EOF; ++i){//1
           if (isalpha(d))
              word[j++] = tolower(d);
           else if ((!isalpha(d)) && (j != 0)){//3
              word[j++] = '\0';
              list = countEntries (list, word);
              j = 0;
           }//1
       }//2
     fclose(doc2);

       PrintList(MergeSort(list));
       free(list); 
       
            
  }//3
//-----------------------------------------------------------------------------------

  return 0;
}
