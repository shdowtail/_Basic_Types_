#include <stdio.h>
#include <stdlib.h>

/* Program prints a user defined amount of squares. 
* Every 24 squares program prompts the user to press enter to continue */

int main (void)
{
  int i, square;
  long num;
  char n[4];
  char *endptr;
  int separate_counter;
  int index;
  index = 0;

  printf ("Enter a number of entries in table: ");

  while (index < 4)
    {
      n[index] = getchar ();
      index++;
    }

  num = strtol (n, &endptr, 10);
  i = 1;
  separate_counter = 1;
  for (;;)
    {
      while (i <= num)
        {
          square = i * i;
          printf ("nr %d squared is %d\n", i, square);
          if (separate_counter == 24)
            {
              char entr;
              while ((entr = getchar ()) != '\n');
              separate_counter = 0;
              printf ("Press enter to continue\n");
            }
          if (i == num)
            {
              return 0;
            }
          separate_counter++;
          i++;
        }
    }
}
