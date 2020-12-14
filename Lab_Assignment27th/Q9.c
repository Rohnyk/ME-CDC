#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc,char *argv[])
{
	char str[strlen(argv[1])];
	char ustr[strlen(argv[1])];
	int i;
	for (i = 0; i < strlen(argv[1]); ++i)
	{
		ustr[i]=toupper(argv[1][i]);
	}
	ustr[i]='\0';
	strcpy(str,ustr);
	printf("%s\n",ustr);
    if(strstr(str,"FFF")==NULL)
    	exit(0);
    int option;
    if(str[strlen(str)-1]!=48 && str[strlen(str)-1]!=49)
    	option=3;
    else
        option=(int)str[strlen(str)-1]-48;
    switch(option)
    {
    	case 0:
    			if(strstr(str,"MCIS")!=NULL)
    				printf("MSIS is a substring of given string");
    			else
    				printf("MSIS is not a substring of given string");
    		    break;

    	case 1:
                if(strstr(str,"SOIS")!=NULL)
    				printf("SOIS is a substring of given string");
    			else
    				printf("SOIS is not a substring of given string");
    		    break;
    	default:
    	        printf(" ");
    	        int lenstr=strlen(str)-3;
    			printf("Length of the word excluding FFF=%d",lenstr);
    }
}