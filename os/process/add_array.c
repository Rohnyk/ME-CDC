#include<stdio.h>

int main()
{
    int a[1000],i,n,sum=0; // declartion of variables.
   
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
     printf("sum of array is : %d",sum);
 
    return 0;
}
