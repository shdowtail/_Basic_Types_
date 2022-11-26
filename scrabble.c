#include <stdio.h>
#include <string.h>
/* Semi-simulation of the SCRABBLE crossword game . Program computes the value of a word by summing the values of it's letters, 1: AEILNORSTU, 2: DG, 3: BCMP, 4: FHVWY, 5: K, 8: JX, 10: QZ
  * Program allows for use of lower-case letters */

int main (void)
{
  char word[50];

  printf ("Enter a word: ");
  scanf ("%49s", word);

  int i = strlen (word);
  int index = 0;
  int total_value = 0;
  while (index <= i)
    {
      if (index == i)
        {
          printf ("total_value = %d\n", total_value);
          break;
        }
      if (word[index] == 65 || word[index] == 69 || word[index] == 73 || word[index] == 76
          || (word[index] > 77 && word[index] < 80)
          || (word[index] > 81 && word[index] < 86) || word[index] == 101 || word[index] == 105
          || word[index] == 108 || (word[index] > 109 && word[index] < 112)
          || (word[index] > 113 && word[index] < 118))
        {
          total_value += 1;
          index++;
        }
      if (word[index] == 68 || word[index] == 71 || word[index] == 100 || word[index] == 103)
        {
          total_value += 2;
          index++;
        }
      if ((word[index] > 65 && word[index] < 68) || (word[index] > 97 && word[index] < 100))
        {
          total_value += 3;
          index++;
        }
      if (word[index] == 70 || word[index] == 72 || (word[index] > 85 && word[index] < 88) || word[index] == 89
          || word[index] == 102 || word[index] == 104 || (word[index] > 117 && word[index < 120]) || word[index] == 121)
        {
          total_value += 4;
          index++;
        }
      if (word[index] == 75 || word[index] == 107)
        {
          total_value += 5;
          index++;
        }
      if (word[index] == 88 || word[index] == 120)
        {
          total_value += 8;
          index++;
        }
      if (word[index] == 81 || word[index] == 90 || word[index] == 113 || word[index] == 122)
        {
          total_value += 10;
          index++;
        }

    }

}
