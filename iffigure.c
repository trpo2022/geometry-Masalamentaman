#include <stdio.h>
#include <string.h>
#define __TRUE         1
#define __FALSE        0
#define _STRING_LENGTH 100

typedef struct
{
  float x;
  float y;
  float radius;
} Circle;

int _if_circle(char *figure)
{
  if (figure[0] == 'c' && figure[1] == 'i' && figure[2] == 'r' &&
      figure[3] == 'c' && figure[4] == 'l' && figure[5] == 'e')
  {
    return __TRUE;
  }
  else
    return __FALSE;
}

int _if_staples(char *figure)
{
  int i = 0;

  while (figure[i] != '(')
  {
    if (i == strlen(figure))
      return __FALSE;
    i++;
  }

  return __TRUE;
}