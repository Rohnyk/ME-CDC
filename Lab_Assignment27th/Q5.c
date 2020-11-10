#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Telephone
{
	char fname[20];
	char lname[20];
	char tnumber[10];
};

void main()
{
    FILE *file; 
    struct Telephone input; 
      
     
    file = fopen ("Q5file.txt", "r"); 
    if (file == NULL) 
    { 
        printf("Cannot) open file \n"); 
        exit(0); 
    } 
      

    while(fread(&input, sizeof(struct Telephone), 1, file)) 
        printf ("name = %s %s,Telephone=%s\n", input.fname, input.lname,input.tnumber); 
  
    fclose (file); 
}