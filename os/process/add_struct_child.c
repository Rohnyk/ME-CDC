#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

typedef struct st{
	int num1;
	int num2;
	int sum;
}st;



int main(){
	struct st set1;
	int status;
	pid_t pid;
	pid = fork();
	
	if(pid == 0){
		printf("Enter the num1 and num2 values\n");
		scanf("%d %d",&set1.num1,&set1.num2);
//		printf("Sum: %d",set1.num1 + set1.num2);
		set1.sum=set1.num1 + set1.num2;
/*If you want to do it without using any way of communication i.e pipes, shared memory then you will have to use exit() system call. The exit system call return a signal that is then caught by wait() system call in parent process. Here I am giving you a code in which I am sending a value from child to parent. One last thing you have to divide the signal caught by wait by 255 to get the exact value. `IF the child send more than 255 it will not get the correct value. after 255 it will take value (return_value - 255)
*/
		exit(set1.sum);
	}
	if(pid > 0){
		wait(&status);//catching signal sent by exit of(child) 
		printf("parent %d\n",status/255);//changing signal to exact value
	
	}
}
