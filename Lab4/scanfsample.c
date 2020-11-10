
#include<stdio.h>

int main() {
   int n ;	
   double x ;
   char name[101] ;    // this is a string or char array


   printf ("Enter an integer value for n: ") ;
   scanf("%d", &n) ;   // don't forget the ampersand

   printf ("Enter a floating point value for x: ") ;
   scanf("%lf", &x) ;  // double requires lf, not f

   printf ("Enter your first name (no spaces): ") ;
   scanf("%100s", name) ;  // arrays do not need the &

   printf ("Hello %s, you typed in %d for n and %f for x.\n", name, n, x) ;
}