
// Work in progress.
//EXIT_FAILURE EXIT_SUCCESS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  ROWS 8
#define COLS 2
int main (void)
{
  int arr_departure[ROWS][COLS] =
	  {{8, 00},
	   {9, 43},
	   {11, 19},
	   {12, 47},
	   {2, 00},
	   {3, 45},
	   {7, 00},
	   {9, 45}};

  int arr_arrival[ROWS][COLS] =
	  {{10, 16},
	   {11, 55},
	   {1, 31},
	   {3, 00},
	   {4, 8},
	   {5, 55},
	   {9, 20},
	   {11, 58}};
  char *departure_specifiers[] = {"am", "am", "am", "pm", "pm", "pm", "pm", "pm"};
  int i = 0;
  int index = 0;
  /*printing departure time*/
  while (i < ROWS)
	{
	  printf ("Departure times: %.2d:%.2d %s \n", arr_departure[i][0], arr_departure[i][1], departure_specifiers[i]);
	  i++;
	}

}