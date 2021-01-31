#include<stdio.h>
#include <sys/types.h>
#include<unistd.h> // required for fork() call
#include<sys/wait.h> // need to add for wait(&status) parent wait for child to finish

int main()
{
    int a[1000],i,n,sum=0; // declartion of variables.
    int status;
    pid_t pid;
    pid = fork();
    
    if(pid == 0){ //child process
      
    printf("Enter size of the array : "); 
    scanf("%d",&n); // get the size of arrary
 
    printf("Enter elements in array : ");

    for(i=0; i<n; i++) 
    {
        scanf("%d",&a[i]); // get the elements of an array
    }
 
    
    for(i=0; i<n; i++)
    {
         
        sum+=a[i];		// add the sum
    }
     printf("sum of array is : %d\n",sum);
	}
	
	if(pid >0){
		wait(&status);
		printf("parent\n");
	}
	
	 
    return 0;
}
