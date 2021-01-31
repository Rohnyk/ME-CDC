#include <stdio.h>
#define MAX 10


/*
     
int array_size(int array[])    
{    
    //Initialize array     
    int arr[] = array;
        
    //Number of elements present in an array can be calculated as follows    
    int length = sizeof(arr)/sizeof(arr[0]);    
        
    printf("Number of elements present in given array: %d", length);     
     
    return len;    
} 
*/   

//function of selection sort; 
//unsort_list -> an array of unsorted elements, n is the total bumber of elements in the array
void SelectionSort(int unsort_list[],int n){

	for(int i =0;i<n-1;i++){
		int iMin=i; //intialize the first value to as min and keep updating for every stage
		for(int j =i+1;j<n;j++){ // loop check for min value
			if(unsort_list[j] <unsort_list[iMin]){
				iMin = j;
			}
		}
		int temp = unsort_list[i]; //bring the min value to the lower index 
		unsort_list[i] = unsort_list[iMin];
		unsort_list[iMin] = temp;
	}
	

}
/*
int main(int argc,char *argv[]){
	int unsort_list[MAX];
	int n;
	int *sort=NULL;

	printf("Enter number of elements in an array:");
	scanf("%d",&n);

	printf("Enter the values:");	
	for(int i =0;i<n;i++){
		scanf("%d",&unsort_list[i]);
	}
	sort=SelectionSort(unsort_list,n);	
	
	printf("The sorted list:");
	for(int i =0;i<n;i++){
		printf("%d ",unsort_list[i]);
	}
	
	return 0;
}
*/
