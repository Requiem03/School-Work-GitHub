//Christopher Bass
//CECS 420
//Project 3

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>
#include <dirent.h>
#include <semaphore.h>
//------------------------------------------------------------------------------------
int linkedlistcount = 0;
int bufferSize = 1;
int threadcount = 0;
char * pexit;
int use  = 0;
int fill = 0;
char *buffer;
int my_fork_id = 0;
sem_t empty;
sem_t full;
sem_t mutex;
//-------------------------------------
struct args {
	char * keyword;
	char * directory;
	char * file_name;
};
//---------------------------------------------------------------------------------------------
void get() {
  
    if (strcmp(strdup(&buffer[use]), "") != 0 && strcmp(strdup(&buffer[use]), "exit") != 0)
    {
       
        printf("%s", &buffer[use]);
        
        if (my_fork_id == 11 && use == 0)
        {
          use += 2048; 
        }
        
        if (use >= bufferSize * 2048) 
	{
            use = 0;
        }
    }
    else if (strcmp(strdup(&buffer[use]), "exit") == 0)
    {
        pexit = "exit";
    }
}

//-----------------------------------------------------------------------------------------------
void fill_start(char * resultstring) {
   
  strcpy(&buffer[fill], resultstring);
  if (my_fork_id == 11 && fill == 0)
        {
          
        }
  fill += 2048;
  if (fill >= 2048*bufferSize) {
    fill = 0;
  }
 
}
//---------------------------------------------------------------------------------------
void *ReadFile (void * arg)
{
    struct args * arg1 = (struct args*)malloc(sizeof(struct args));
    arg1 = arg;
    
    char resulttext[2048];
    char * word, * item;
    char linestring[1024];
    char filename[200];
    char keyword[34];
    sprintf(keyword, "%s", arg1->keyword);
    sprintf(filename, "%s%s", arg1->directory, arg1->file_name);
    FILE *file = fopen ( filename, "r" );
    if (file != NULL) {
        char line [1024];
        int linenumber = 1;
        while(fgets(line, sizeof(line), file)!= NULL) // read a line from a file
        {
            
            strtok(line, "\n");
            strcpy(linestring, line);
            sprintf(line, " %s ", linestring);
            

            word = strtok_r(line, " ,.-;:", &item);
            while (word != NULL)
            {
                if (strcmp(word, keyword) == 0 )
                {
                    
                    sprintf(resulttext, "%s:%d:%s\n", arg1->file_name, linenumber, linestring);
                   
                    sem_wait(&empty);
                    sem_wait(&mutex);
                        fill_start(resulttext);
                        
                    sem_post(&mutex);
                    sem_post(&full);
                    break;
                }
                word = strtok_r(NULL, " ,.-;:", &item);
            }
            linenumber++;
        
        }
       
        fclose(file);
   }
    return(0);
   
}
//-----------------------------------------------------------------------------------------------

void *Reader()
{
    
    while(strcmp(pexit, "exit") != 0)
    {
            sem_wait(&full);
            sem_wait(&mutex);
                get();
            
            sem_post(&mutex);
            sem_post(&empty);
            continue;
    }
    
    return 0;
}
//----------------------------------------------------------------------------------------------


//Start of Main
int main(int argc, char **argv)
{


// initialize varibles
char *commandFile;
char line[1024];
int fork_id = 0;
pexit = "";

char * word, * item;
char directory[128];
char keyword[32];
int parse = 0;		
//---------------------------------------------------

// Read in the arguments
commandFile = argv[1];
bufferSize = atoi(argv[2]);

//-----------------------------------------------------

// loop and create child processes for each line in the file

FILE *file = fopen ( commandFile, "r" );

while(fgets(line, sizeof(line), file)!= NULL) // read a line from a file
   {//start while 1
        my_fork_id++;
        fork_id = fork();
        if (fork_id == 0)
   	{//start if 1
       
                      
                buffer = (char *)malloc((bufferSize * sizeof(char) * 2048) + (bufferSize));
                int i = 0;
                for(i =0; i < bufferSize; i++)
		{//start for1
                    strcpy(&buffer[i], "");
                }//end for1

                sem_init(&empty, 0, bufferSize); // max are empty
                sem_init(&full, 0, 0);    // 0 are full
                sem_init(&mutex, 0, 1);   // mutex

                // start the consumer
                pthread_t printthread;
                pthread_create(&printthread, NULL, Reader, NULL);

                word = strtok_r(line, " \n", &item);
	            while (word != NULL)
	            {//start while 2
	            	if (parse == 0)
			{
	            		strcpy(directory, word);
	            		
	            		parse++;
	            	}
		            else if (parse == 1) 
			   {
		            	strcpy(keyword, word);
	            		
	            		parse++;
		            	break;
		            }
		            else 
			    {
		            break;
		            }
	                word = strtok_r(NULL, " \n", &item);
	            }//end while 2

                struct dirent *ent;
                DIR * Directory;
            	int amount_of_files = 0;
            	int amount_of_files_2 = 0;

            	// open the directory
            	if ((Directory = opendir (directory)) != NULL)
			       {
			           while ((ent = readdir (Directory)) != NULL)
			           {
			              if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
			                {
			                    amount_of_files++;
			                }
			           }
			       }
			     pthread_t read_thread[amount_of_files];
		         if ((Directory = opendir (directory)) != NULL)
			       {
			           while ((ent = readdir (Directory)) != NULL)
			           {
			              if (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, ".."))
			                {
			                    continue;
			                }
			               
			                
                		struct args * t_args = (struct args*)malloc(sizeof(struct args));
                			t_args->directory = directory;
			                t_args->file_name = ent->d_name;
			                t_args->keyword = keyword;
			  pthread_create(&read_thread[amount_of_files_2], NULL, ReadFile, t_args);
			                pthread_join(read_thread[amount_of_files_2], NULL);
			                amount_of_files_2++;
			                free(t_args);
			           }
			       }
                
               
                fill_start("exit");
                closedir(Directory);
                break;
            }//end if1
            
	    else 
	    {
            continue;
            };
       }//end while1
			
                sem_destroy(&mutex);
                sem_destroy(&full);
                sem_destroy(&empty);
                free(buffer);
                fclose(file);
    return (0);
}//End of Main
