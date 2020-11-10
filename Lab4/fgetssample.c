#include <stdio.h>
#include <string.h>

int main(void)

{

  char buffer[16];

  int pass=0;

  printf("\n Enter the password : \n");

  if(fgets(buffer,sizeof(buffer),stdin)!=NULL)

  {
   if(strcmp(buffer,"pass\n"))

   {

     printf ("\n Wrong Password \n");

   }

   else

   {      printf ("\n Correct Password \n");

     pass = 1;

   }     if(pass)

    {

     printf ("\n You are root \n");

    }

    return 0; 

  }

}