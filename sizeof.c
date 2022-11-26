#include <stdio.h>
#include <limits.h>
/* Prints sizeof() values of data types */

int main (void)
{
  printf ("sizeof(short)=%ld\n", sizeof (short int));
  printf ("sizeof(unsigned)=%lu\n", sizeof (unsigned int));
  printf ("sizeof(int)=%ld\n", sizeof (int));
  printf ("sizeof(long)=%ld\n", sizeof (long));
  printf ("sizeof(unsigned long)=%lu\n", sizeof (unsigned long));
  printf ("sizeof(double)=%ld\n", sizeof (double));
  printf ("sizeof(long double)=%ld\n", sizeof (long double));

}







