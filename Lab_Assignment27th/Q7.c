#include <stdio.h>
#include <string.h>

void main()
{
	char str1[50];
	int i,l = 0;
	printf("\n\nFind the length of a string:\n ");
	printf("-------------------------------------\n");
	printf("Input a string : ");
	fgets(str1, 50, stdin);
	for (i = 1; str1[i] != '\0'; i++) //donot count null char
	{
		l++;
	}
	printf("The string contains %d number of characters. \n",l);
	printf("So, the length of the string %s is : %d\n\n", str1, l);
}