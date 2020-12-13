#include <stdio.h>
#include <stdlib.h>

int main()
{
 FILE *fp;
 char path[100];
 char ch;
 int characters, words, lines;
 /* Input path of files to merge to third file */
 printf("Enter source file path: ");
 scanf("%s", path);
 /* Open source files in 'r' mode */
 fp = fopen(path, "r");
 /* Check if file opened successfully */
 if (fp == NULL)
 {
  printf("\nUnable to open file.\n");
  printf("Please check if file exists and you have read privilege.\n");
  exit(EXIT_FAILURE);
 }
 /* Logic to count characters, words and lines.*/
 characters = words = lines = 0;
 while ((ch = fgetc(fp)) != EOF)
 {
  characters++;
  /* Check new line */
  if (ch == '\n' || ch == '\0')
  lines++;
  /* Check words */
  if (ch == ' ' || ch == '\t' || ch == '\n' || ch == '\0')
   words++;
 }
  /* Increment words and lines for last word */
 if (characters > 0)
 {
  words++;
  lines++;
 }
 /* Print file statistics */printf("\n");
 printf("Total characters = %d\n", characters);
 printf("Total words = %d\n", words);
 printf("Total lines = %d\n", lines);
 /* Close files to release resources */
 fclose(fp);
 return 0;
}