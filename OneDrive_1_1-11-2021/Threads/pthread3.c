/*find min and max in an array using thread*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#define arrSize 5

struct StructMaxMin
{
    int iMax; //hold max value 
    int iMin; // hold min value
};

int arr[arrSize]; //input array of size 10

void *thread_search_min_max(void *); // thread task declaration

int main()
{
    pthread_t tid;
    struct StructMaxMin *st_main,*st_th;
    int FinalMax,FinalMin;
    
    st_main=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
    
    int iCount;
    for(iCount=0;iCount<arrSize;iCount++)
    {
        printf("Enter Value of arr[%d] :",iCount);
        scanf("%d",&arr[iCount]);
    }        
    int *ptr = arr;
   iCount=0;
    printf("%d\n",iCount);    
    printf("%d\n",arr[iCount]);
    printf("arr[0] %d\n",arr[0]); // value of first index
    printf("&arr[0] %d\n",&arr[0]); // address of first index
    printf("ptr %d\n",ptr); // address of first index
    printf("&ptr %d\n",&ptr); //address of ptr
    printf("*ptr %d\n",*ptr); // address of first index
    printf("*(ptr+1) %d\n",*(ptr+1)); // address of first index
    printf("ptr+1 %d\n",ptr+1); // address of first index
    printf("&arr[1] %d\n",&arr[1]); // address of first index
    printf("arr %d\n",arr);//address pointing to startign of the address
 
 
 //Thread creation
    pthread_create(&tid,NULL,thread_search_min_max,NULL);
    
    st_main->iMax=arr[0];
    st_main->iMin=arr[0];
    
    for(iCount=1;iCount<arrSize/2;iCount++)
    {
        if(arr[iCount] > st_main->iMax)
        {
            st_main->iMax=arr[iCount];
        }
        
        if(arr[iCount] < st_main->iMin)
        {
            st_main->iMin=arr[iCount];
        }
    }    
    
    pthread_join(tid,(void**)&st_th);    
    
    if(st_main->iMax >= st_th->iMax)
    {
        FinalMax=st_main->iMax;
    }    
    else
    {
        FinalMax=st_th->iMax;
    }
        
    if(st_main->iMin <=st_th->iMin)
    {
        FinalMin=st_main->iMin;
    }
    else
    {
        FinalMin=st_th->iMin;
    }
    
    printf("Final Max : %d \n",FinalMax);
    printf("Final Min : %d \n",FinalMin);
    return 0;
}

/*thread task*/
void *thread_search_min_max(void *para)
{
    struct StructMaxMin *st;
    st=(struct StructMaxMin*)malloc(sizeof(struct StructMaxMin));
        
    int iCount;
    st->iMax=arr[arrSize/2];
    st->iMin=arr[arrSize/2];
        
    
    for(iCount=arrSize/2 + 1;iCount<arrSize;iCount++)
    {
        if(arr[iCount] > st->iMax)
        {
            st->iMax=arr[iCount];
        }
        if(arr[iCount] < st->iMin)
        {
            st->iMin=arr[iCount];
        }
    }    
    
    pthread_exit((void*)st);        
}
