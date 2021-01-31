#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <stdlib.h>

int count =0;
int flag1=0;
void *fun1(void *);
void *fun2(void *);

int main()
{
pthread_t id1,id2;
pthread_create (&id1,NULL,&fun1,NULL);
pthread_create (&id2,NULL,&fun2,NULL);
pthread_join(id1,NULL);
pthread_join(id2,NULL);
return 0;
}
void *fun1(void *p)
{
for(;count<10;)
{
if(flag1 ==0)
{
printf ("%d ",count++);
flag1=1;
}
}
}

void *fun2(void *p)
{
for(;count<10;)
{
if(flag1 ==1)
{
printf ("%d ",count++);
flag1=0;
}
}
}
