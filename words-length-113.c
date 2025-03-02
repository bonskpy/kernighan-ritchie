/*
 * Simple script printing a histogram showing number of letters in words
 * bonskpy
 *
 * 02/03 added MAX_LENGTH for maintainability
 * */

#include <stdio.h>

#define IN 1
#define OUT 0
#define MAX_LENGTH 10

int main()
{
  int c, i, j, nletters, lwords, state;
  int nletters_arr[MAX_LENGTH];

  for (i = 0; i < MAX_LENGTH; ++i)
    nletters_arr[i] = 0;

  nletters = 0;
  state = OUT;
  lwords = 0;

  while ((c = getchar()) != EOF)
  {
    if (c != ' ' && c != '\t' && c != '\n')
    {
      state = IN;
      ++nletters;
    }
    else
    {
      if (state == IN)
      {
        state = OUT;
        if (nletters < MAX_LENGTH)
        {
          ++nletters_arr[nletters];
        }
        else
        {
          ++lwords;
        }
        nletters = 0;
      }
    }
  }
  
  // handling last word that could be ommited
  if (state == IN)
  {
    if (nletters < MAX_LENGTH)
    {
      ++nletters_arr[nletters];
    }
    else
    {
      ++lwords;
    }
  }

  printf("\nHistogram z rozkładem liter w słowach\n");

  for (i = 0; i < MAX_LENGTH; ++i)
  {
    printf("%3d :: ", (i + 1));
    for (j = 0; j < nletters_arr[i]; ++j)
      printf("*");
    printf("\n");
  }
  printf("\n");
  printf("Słowa dłuższe niż 10 znaków: %d\n", lwords);

  return 0;
}
