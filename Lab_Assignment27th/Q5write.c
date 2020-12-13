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
    struct Telephone input[10]={{"Nabila","Southern","5705827048"},
                                {"Freja", "Gilmour", "9819783428"},
                                {"Cruz","Whittington","6823595045"}};
                                /*{"Zayyan","Power","5667117899"},
								{"Ed","Cunningham","2257824681"},
							    {"Hallam","Rawlings","7456760513"},
							    {"Layla-Mae","Mckeown","2945263119"},
							    {"Alanna","Bullock","8595520082"},
							    {"Jaxon","Hastings","9943515235"},
							    {"Fenton","Cohen","6117194799"}};*/
    file = fopen ("Q5file.txt", "w"); 
    if (file == NULL) 
    { 
        printf("Cannot) open file \n"); 
        exit(0); 
    } 
      
    for(int i=0;i<3;i++)
    		fwrite(&input[i], sizeof(struct Telephone),1, file);
    
    
    fclose (file); 
}		