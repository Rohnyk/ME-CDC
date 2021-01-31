#include<stdio.h>
#include "selectionsort.c"
#define MAX 20
 
void main()
{

//bt -> burst time, p-> processes wt-> waittime , tat - turn aroudn time 
    int bt[MAX],p[MAX],wt[MAX],tat[MAX],i,j,n,total=0,pos,temp;
    //int *sort=NULL;
    
//avg -> average wait time , avg_tat -> average turn around time 
    float avg_wt,avg_tat;
    
    printf("Enter total number of process:");
    scanf("%d",&n);
 
    printf("\nEnter Burst Time of each process:\n");
 
    for(i=0;i<n;i++)
    {
        printf("p%d:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
 
    //sorting burst time in ascending order using selection sort
 /*   for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }*/
    
    
    SelectionSort(p,n);
    
    printf("The sorted list:");
	for(int i =0;i<n;i++){
		printf("%d ",p[i]);
	}
 
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //average waiting time
    total=0;
    
 //display
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np%d\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
}
