#include<stdio.h>

int main(){
int pid;
pid =fork();
if(pid == 0){
	for(;;)
	{
		sleep(10);
		printf("The number of users logged in are:");
		system("who | wc -l");
	}
}
}
