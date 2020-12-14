#include <stdio.h>
#include <string.h>

int main()

{
  FILE *fe;
  FILE *fo;
  FILE *fg;
  int i;
  int j,l;
  char ch;
  char tmp[100] ;

 fo = fopen("odd.txt","w");
 if (fo == NULL)
 {
  perror("ODDFILE");
 }
 fclose(fo);

 fe = fopen("even.txt","w");
 if (fe == NULL)
 {
  perror("EVENFILE");
 }
 fclose(fe);

 fg = fopen("input.txt","r");
 if (fg == NULL)
 {
  perror("GENERALFILE");
 }

 while((ch = fgetc(fg))!=EOF)
 {
    if (ch != '\n' && ch != '\t' && ch != ' ')
    {
      if(ch!='.' && ch!=',')
      {
        tmp[i] = ch;
        i++;
      }
    }
    else 
    {
        tmp[i++]='\n';
        tmp[i]='\0';
        i=0;
        printf("%s",tmp);
        l =strlen(tmp)-1;
        j = l % 2;
        if (j == 0)
        {
          fe = fopen("even.txt","a");
            if (fe == NULL)
            {
                perror("EVENFILE");
             }  
         fputs(tmp,fe);
         fclose(fe);

        }

        else
        {
          fo = fopen("odd.txt","a");
            if (fo == NULL)
            {
                perror("ODDFILE");
             }  
         fputs(tmp,fo);
         fclose(fo);

        }
    }

 }
 fclose(fg);
}   