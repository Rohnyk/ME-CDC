// C program for implementation of FCFS scheduling  
// base code  Shivi_Aggarwal
// Modified by Mohan Kumar J

#include<stdio.h>  
// Function to find the waiting time for all   
// processes  
void findWaitingTime(int processes[], int n,int bt[], int wt[])  
{  
    // waiting time for first process is 0  
    wt[0] = 0;  
    
    // calculating waiting time  
    for (int  i = 1; i < n ; i++ )  
        wt[i] =  bt[i-1] + wt[i-1];  
}  
    
// Function to calculate turn around time  
void findTurnAroundTime( int processes[], int n,int bt[], int wt[], int tat[])  
{  
    // calculating turnaround time by adding  
    // bt[i] + wt[i]  
    for (int  i = 0; i < n ; i++)  
        tat[i] = bt[i] + wt[i];  
}  
    
//Function to calculate average time  
//wt -> wait time | tat -> turn around time | 
void findavgTime( int processes[], int n, int bt[])  
{  
    int wt[n], tat[n], total_wt = 0, total_tat = 0;  
    
    //Function to find waiting time of all processes  
    findWaitingTime(processes, n, bt, wt);  
    
    //Function to find turn around time for all processes  
    findTurnAroundTime(processes, n, bt, wt, tat);  
    
    //Display processes along with all details  
    printf("Processes   Burst time   Waiting time   Turn around time\n");  
    
    // Calculate total waiting time and total turn   
    // around time  
    for (int  i=0; i<n; i++)  
    {  
        total_wt = total_wt + wt[i];  
        total_tat = total_tat + tat[i];  
        printf("%d\t",(i+1)); 
        printf("%3d\t", bt[i] ); 
        printf("%5d\t",wt[i] ); 
        printf("%5d\n",tat[i] );  
    }  
    int s=(float)total_wt / (float)n; 
    int t=(float)total_tat / (float)n; 
    printf("Average waiting time = %d",s); 
    printf("\n"); 
    printf("Average turn around time = %d ",t);  
}  
    
// Driver code  
int main()  
{  
    //process id's  
    //defining a structure- assignment
    int processes[] = { 1, 2, 3};  

    
    //effecicy ? include 1 unit waste time, usefule time 
    
    // pointer?
    
    //what is the difference between sizeof operator and sizeof() function
    printf("sizeof processes %d\n",sizeof processes);
    printf("sizeof(processes) %d\n",sizeof(processes));
    printf("sizeof(int) %d\n",sizeof(int));
    printf("sizeof(float) %d\n",sizeof(float));
    printf("sizeof(double) %d\n",sizeof(double));
    printf("sizeof(processes[0]) %d\n",sizeof(processes[0]));
    printf("size of processes[0] %d\n",sizeof processes[0]);
 
    int n = sizeof processes / sizeof processes[0];  
    
    //Burst time of all processes  
    int  burst_time[] = {10, 5, 8};  
    
    findavgTime(processes, n,  burst_time);  
    return 0;  
}  
 
