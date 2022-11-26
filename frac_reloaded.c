/* Given program is a fraction calculator: you can perform adding, subtraction, division and multiplication.
 * Rounding up to whole numbers not yet implemented */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int gcd (int a, int b)
{
  while (b > 0)
    {
      int quotient = a / b;
      int remainder = a - quotient * b;
      a = b;
      b = remainder;
    }
  return a;
}

int main (void)
{
  bool flag_add = false;
  bool flag_subtract = false;
  bool flag_multiply = false;
  bool flag_divide = false;
  char frac_string[12];
  char *frac_token;
  char *original;
  char *for_editing;
  char *first_1;
  char *first_2;
  char *second_1;
  char *second_2;
  int dec_first_1;
  int dec_first_2;
  int dec_second_1;
  int dec_second_2;
  int count;

  printf ("Enter two fraction separated by either: +, -, * or /In following format \"w|x+y|z\": ");
  scanf ("%11s", frac_string);

  int index = 0;
  while (1)
    {
      if (frac_string[index] == '+')
        {
          flag_add = true;
          break;
        }
      if (frac_string[index] == '-')
        {
          flag_subtract = true;
          break;
        }
      if (frac_string[index] == '*')
        {
          flag_multiply = true;
          break;
        }
      if (frac_string[index] == '/')
        {
          flag_divide = true;
          break;
        }
      else
        {
          index++;
        }
    }
  original = strdup (frac_string);
  for_editing = original;
  count = 0;

/* Separates a string into numerator and denominator parts */
  while ((frac_token = strtok_r (for_editing, "|/+-* ", &for_editing)))
    {
      if (count == 0)
        {
          first_1 = frac_token;
        }
      else if (count == 1)
        {
          first_2 = frac_token;
        }
      else if (count == 2)
        {
          second_1 = frac_token;
        }
      else if (count == 3)
        {
          second_2 = frac_token;
        }
      count++;
    }
/* Converts the parts of strings gotten from the last function into integers */
  dec_first_1 = atoi (first_1);
  dec_second_1 = atoi (second_1);

  dec_first_2 = atoi (first_2);
  dec_second_2 = atoi (second_2);


/* Safety measure to avoid integer overflows */
  if (dec_first_1 > 2147483647 || dec_first_2 > 2147483647 || dec_second_1 > 2147483647
      || dec_second_2 > 2147483647)
    {

      printf ("bad value\n");
      return 0;
    }
  if (flag_add == true)
    {
      if (dec_first_2 != dec_second_2)
        {
          int unlike_frac_numerator_final;
          int unlike_frac_numerator_1;
          int unlike_frac_numerator_2;
          int unlike_frac_denominator;

          unlike_frac_numerator_1 = dec_second_2 * dec_first_1;
          unlike_frac_numerator_2 = dec_first_2 * dec_second_1;
          unlike_frac_numerator_final = unlike_frac_numerator_1 + unlike_frac_numerator_2;
          unlike_frac_denominator = dec_first_2 * dec_second_2;
          printf ("result = %d/%d\n", unlike_frac_numerator_final, unlike_frac_denominator);
        }
      else
        {
          int like_frac_numerator;
          int like_frac_denominator;

          like_frac_numerator = dec_first_1 + dec_second_1;
          like_frac_denominator = dec_first_2;
          printf ("result %d/%d", like_frac_numerator, like_frac_denominator);
        }

      return 0;
    }
  if (flag_subtract == true)
    {
      if (dec_first_2 == dec_second_2)
        {
          like_frac_numerator = dec_first_1 - dec_second_1;
          like_frac_denominator = dec_second_2;
          printf ("subtraction result = %d/%d", like_frac_numerator, like_frac_denominator);
        }
      else
        {
          int subtract_num_1;
          int subtract_num_2;
          int subtract_common_denominator = dec_first_2 * dec_second_2;

          subtract_num_1 = dec_first_1 * dec_second_2;
          subtract_num_2 = dec_second_1 * dec_first_2;

          int subtract_num_final = subtract_num_1 - subtract_num_2;
          int greatest_common_denominator = gcd (subtract_num_final, subtract_common_denominator);
          int rounded_sub_num_final = subtract_num_final / greatest_common_denominator;
          int rounded_sub_denom_final = subtract_common_denominator / greatest_common_denominator;

          printf ("result = %d/%d\n", subtract_num_final, subtract_common_denominator);
          printf ("rounded result = %d/%d\n", rounded_sub_num_final, rounded_sub_denom_final);

        }
    }
  if (flag_multiply == true)
    {
      int multiply_numerator = dec_first_1 * dec_second_1;
      int multiply_denominator = dec_first_2 * dec_second_2;
      printf ("result = %d/%d\n", multiply_numerator, multiply_denominator);

      int multiply_gcd = gcd (multiply_numerator, multiply_denominator);

      int rounded_multiply_numerator;
      int rounded_multiply_denominator;
      rounded_multiply_numerator = multiply_numerator / multiply_gcd;
      rounded_multiply_denominator = multiply_denominator / multiply_gcd;
      printf ("rounded result = %d/%d\n", rounded_multiply_numerator, rounded_multiply_denominator);
    }
  if (flag_divide == true)
    {
      int divide_numerator = dec_first_1 * dec_second_2;
      int divide_denominator = dec_first_2 * dec_second_1;
      printf ("result = %d/%d\n", divide_numerator, divide_denominator);

      int divide_gcd = gcd (divide_numerator, divide_denominator);

      int rounded_divide_numerator = divide_numerator / divide_gcd;
      int rounded_divide_denominator = divide_denominator / divide_gcd;
      printf ("rounded result = %d/%d\n", rounded_divide_numerator, rounded_divide_denominator);
    }
  return 0;
}
