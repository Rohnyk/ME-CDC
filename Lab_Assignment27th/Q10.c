#include <stdio.h>
#include <stdlib.h>


/* Function declarations */
int isEven(const int NUM);
 
int main()
{
 /* File pointer to hold reference to different files */
 FILE * fPtrIn,
 * fPtrEven,
 * fPtrOdd;
 int num, success;
 /* Open all files to perform read/write.*/
 fPtrIn = fopen("input.txt", "r");
 fPtrEven = fopen("evennumbers.txt" , "w");
 fPtrOdd = fopen("oddnumbers.txt" , "w");
 /* fopen() return NULL if unable to open file in given mode. */
 if(fPtrIn == NULL || fPtrEven == NULL || fPtrOdd == NULL)
 {
  /* Unable to open file hence exit */
  printf("Unable to open file.\n");
  printf("Please check whether file exists and you have read/write privilege.\n");
  exit(EXIT_FAILURE);
 }
 printf("File opened successfully. Reading integers from file. \n\n");
 // Read an integer and store read status in success.
 while (fscanf(fPtrIn, "%d", &num) != -1)
 {
  /* Write even and odd numbers to different files.*/
  if (isEven(num))
   fprintf(fPtrEven, "%d\n", num);
  else
   fprintf(fPtrOdd, "%d\n", num);
 }
 /* Done with all files, hence close all. */
 fclose(fPtrIn);
 fclose(fPtrEven);
 fclose(fPtrOdd);
 printf("Data written to files successfully.");return 0;
}

int isEven(const int NUM)
{
  return !(NUM & 1);
}