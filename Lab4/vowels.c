#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/wait.h> 
#include<stdio.h>

int main(int argc,char* argv[])
{
	
  int cp[2];
  if(pipe(cp)<0)
    exit(0);
  int pid=fork();
	if(pid==-1)
    {
    	printf("can't fork,error\n");
    	exit(0);
    } 
    else
    	if(pid==0)
    	{
           close(cp[0]);
           int vowel_count=0;
           printf("child process, pid = %u\n",getpid());
           fflush(stdout);
           for(int i=1;i<argc;i++)
            for(int j=0;argv[i][j]!='\0';j++)
             { 
            
             switch(argv[i][j]){
              case 'a':vowel_count++;
                       break;
              case 'e':vowel_count++;
                       break;
              case 'i':vowel_count++;
                       break;
              case 'o':vowel_count++;
                       break;
              case 'u':vowel_count++;
                       break;
              default:
                      continue;
             }      
             }
             write(cp[1],&vowel_count,sizeof(vowel_count));
             close(cp[1]);
             exit(2);
    	}
      else
      {
        close(cp[1]);
        int vowel_count;
        printf("Parent id:%d\n",getpid());
        printf("Parent Process\n"); 
        wait(NULL);
        printf("Parent Printing\n");
        read(cp[0],&vowel_count,sizeof(vowel_count));
        close(cp[0]);
        printf("vowel count in command line arrgument is %d\n",vowel_count);
        exit(2);
      }
}