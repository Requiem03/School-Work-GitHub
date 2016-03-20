#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//#define true 1
//#define false 0
//Linked List 1
typedef struct node {
	int wait;	
	int finish;
	int ftime;
	int wtime;	
	int  pid;
	int atime;
	int btime;  
	struct node *next; // pointer to next node in linked list
	struct node *prev; //pointer to the previous node in the linked list
} node;


//-------------------------------------------------------------------------------------- 
//Function to swap data of two nodes a and b
void swap(struct node *a, struct node *b)
{
    int temp = a->atime;
    a->atime = b->atime;
    b->atime = temp;

    int temp2 = a->pid;
    a->pid = b->pid;
    b->pid = temp2;

    int temp3 = a->btime;
    a->btime = b->btime;
    b->btime = temp3;

    int temp4 = a->wtime;
    a->wtime = b->wtime;
    b->wtime = temp4;

    int temp5 = a->ftime;
    a->ftime = b->ftime;
    b->ftime = temp5;

}

//-------------------------------------------------------------------------------------

// Bubble sort linked list for arrival time for FCFS
void bubbleSort(struct node *item)
{
    int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = item;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->atime > ptr1->next->atime)
            {
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
//-------------------------------------------------------------------------------------- 
//Bubblesort linked list for shortest burst time for Finish Time
void sortFinish(struct node *item)
{
        int swapped, i;
    struct node *ptr1;
    struct node *lptr = NULL;
 
    /* Checking for empty list */
    if (ptr1)
        return;
 
    do
    {
        swapped = 0;
        ptr1 = item;
 
        while (ptr1->next != lptr)
        {
            if (ptr1->ftime > ptr1->next->ftime)
            { 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }
    while (swapped);
}
//--------------------------------------------------------------------------------------



//--------------------------------------------------------------------------------------
//Start of Main Program
int main(int argc, char* argv[]) {
    int i;
    node *top = NULL;
    node *cur = NULL;
    node *tail= NULL;
    node *prev1 =   NULL;
    int p, a, b;
    
   struct node *item;
//Read Files into linked lists----------------------------------------
	int count;
	int process_num=0;
    FILE* fp = fopen(argv[1], "r"); //read first file to linked list  
    if (!fp) {
        perror("fopen");
        exit(1);
    }

    while (fscanf(fp, "%d %d %d", &p, &a, &b)!=EOF)
    {
        //node *item = malloc(sizeof(node));
	item = malloc(sizeof(node));        
	item->pid = p;
	item->atime=a;
	item->btime=b;
	//item->wait=1;
	item->finish=0;  //initilizing finish to false      
	item->next = NULL;
	//item->prev = NULL;        
	if (!cur) {
            // first time, store top.
            top = cur = item;
	    process_num++;
	    //cur->prev = top;
        } else {
            // chain nexts.
            cur->next = item;
            cur = item;
	process_num++;

        }
	if(count>0){
	cur->prev=prev1;
	prev1=cur;
	}
	
	if(cur->next==NULL){
	tail=cur;
	}
    }
    

   fclose(fp);
//---------------------------------------------------------------------------
//Sort by arrival time
cur=top;
item=top;
bubbleSort(item);

//---------------------------------------------------------------------------
//FCFS 

if (strcmp(argv[3], "FCFS")==0){//start FCFS
cur=top;


int curr_time=0;
while (cur)
{
	
	
	if(cur->finish==0 && (cur->wait==0 && curr_time>=cur->atime))//check wait check atime
	{
			
		cur->btime--;//reduce burst time
		//cur->ftime++;//increment finish time
	}
	
	else if(cur->finish==0 && (cur->wait==1 && curr_time>=cur->atime))//chec wait is true check arrival 
	{
		cur->wtime++;//incriment wait time
		//cur->ftime++;//incriment finish time
	}
	
	
	
	
	
	if(cur->next !=NULL && cur->finish == 0){//Sets next node to wait if process unfinished
	cur->next->wait=1;
	}
	else if(cur->next !=NULL && cur->finish == 1){
	cur->next->wait=0;
	}	

	if(cur->btime==0 && cur->finish==0){ //if nodes burst = 0 then finish switches to true
	cur->finish=1;
	cur->ftime=curr_time+1;
	}

	//printf("%d %d %d %d %d\n", cur->pid, cur->atime, cur->ftime, cur->wtime, curr_time);
	//cur=cur->next;	//Traverse the node
	
		
	if(cur->next==NULL && cur->btime > 0){ //Loop until last process burst=0
	cur=top;
	curr_time++;//Increment current time every time through	
	}
	else if(cur->next==NULL && cur->btime ==0){//if last nodes burst=0 break out of loop
	break;
	}
        else {
	cur=cur->next;	//Traverse the node
	}
	
}//end while

}//end FCFS

//---------------------------------------------------------------------------
//SRTF
if (strcmp(argv[3], "SRTF")==0){//Start STRF


item=top;
cur=top;
cur->wait=0;
int processing_btime=cur->btime+1;
int curr_time=0;
while (process_num >=0)
{
	if(cur->finish==0)
	{
		if((processing_btime==0) && (cur->atime >= curr_time))
		{	//if process is finished chang processing_btime to next process
			processing_btime=cur->btime+1;
		}

		if((cur->atime >= curr_time) && (cur->btime < processing_btime))
		{
 		
 			cur->btime--;
		}
		else if((cur->atime >= curr_time) && (cur->btime >= processing_btime))
		{
 			cur->wtime++;
 		
		}

	}	

	if(cur->btime==0){ //if nodes burst = 0 then finish switches to true
	cur->finish=1;
	cur->ftime=curr_time+1;	
	process_num--;
	}

	printf("%d %d %d %d %d %d\n", cur->pid, cur->atime, cur->ftime, cur->wtime, cur->btime, curr_time);
	
		
	if(cur->next==NULL && process_num > 1){ //Loop until last process burst=0
	cur=top;
	curr_time++;//Increment current time every time through	
	}
	else if(cur->next==NULL && process_num ==1){//if last nodes burst=0 break out of loop
	break;
	
	}
        else {
	cur=cur->next;	//Traverse the node
	}
	
}//end while



}//End STRF

//---------------------------------------------------------------------------
   // print node to Terminal  
  /*  cur = top;//print first list
    while (cur) {
        printf("%d %d %d %d\n", cur->pid, cur->atime, cur->ftime, cur->wtime);
        cur = cur->next;
    }	
	cur=tail;	
	while (cur) {
        printf("%d %d %d %d\n", cur->pid, cur->atime, cur->ftime, cur->wtime);
        cur = cur->prev;
    }*/	
//-------------------------------------------------------------------------------


//-------------------------------------------------------------------------------
cur=top;
item=top;
sortFinish(item);

//------------
//Output File
  cur = top;
  FILE *outtext = fopen(argv[2], "w");
  //fprintf(outtext,"\n");
  while (cur){
        fprintf(outtext, "%d %d %d %d\n", cur->pid, cur->atime, cur->ftime, cur->wtime);
        cur = cur->next;
  
	}
	fclose(outtext);
//--------------------------------------------------------------
    // free datas
    cur = top;
    while (cur) {
        node *item = cur->next;
        free(cur);
        cur = item;
    }


    return 0;
}
