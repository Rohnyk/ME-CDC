#include <stdio.h>
#include <stdlib.h>

int main(){
	int p[2], retval,i=0;
	
	while(1){
		retval = pipe(p);
		if(retval == -1){
			printf("Max no of pipes that can be openeed concurrently are %d\n",i);
			exit(1);
		}
		i++;
		printf("%d %d\n",p[0],p[1]);
	
	}

}
