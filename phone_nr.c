#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Program translates an alphabetic phone number into numeric form */
/* 2=ABC, 3=DEF, 4=GHI, 5=JKL, 6=MNO, 7=PRS, 8=TUV, 9=WXY*/

int main (void)
{
  char str_letters[10];
  int i;
  int index;
  i = 0;

  printf ("Enter the phone number: ");
  while ((str_letters[i] = getchar ()) != '\n')
    {
      i++;
      index = i;
    }

  i = 0;
  while (i < index)
    {
      if (str_letters[i] == 81)
        {
          printf ("\n***Q is not a proper input)***\n");
          return 0;
        }
      if (str_letters[i] == 45 || (str_letters[i] >= 48 && str_letters[i] <= 57))
        {
          printf ("%c", str_letters[i]);
        }
      if (str_letters[i] >= 65 && str_letters[i] <= 67)
        {
          printf ("2");
        }
      if (str_letters[i] >= 68 && str_letters[i] <= 70)
        {
          printf ("3");
        }
      if (str_letters[i] >= 71 && str_letters[i] <= 73)
        {
          printf ("4");
        }
      if (str_letters[i] >= 74 && str_letters[i] <= 76)
        {
          printf ("5");
        }
      if (str_letters[i] >= 77 && str_letters[i] <= 79)
        {
          printf ("6");
        }
      if (str_letters[i] >= 80 && str_letters[i] <= 83)
        {
          printf ("7");
        }
      if (str_letters[i] >= 84 && str_letters[i] <= 86)
        {
          printf ("8");
        }
      if (str_letters[i] >= 87 && str_letters[i] <= 89)
        {
          printf ("9");
        }
      i++;
    }
  return 0;
}
