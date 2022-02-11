#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define __TRUE         1
#define __FALSE        0
#define _STRING_LENGTH 100
#define _INVALID_VALUE -919949

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

Circle _read_coordinates(char *figure)
{
  Circle coordinates = {
      .x = _INVALID_VALUE, .y = _INVALID_VALUE, .radius = _INVALID_VALUE};
  char coordinateX[_STRING_LENGTH];
  char coordinateY[_STRING_LENGTH];
  char radius[_STRING_LENGTH];
  int i = 0;

  while (figure[i] < '0' || figure[i] > '9')
  {
    if (i == strlen(figure))
      return coordinates;

    i++;
  }

  int j = 0;

  while (figure[i] != ' ')
  {
    if (i == strlen(figure))
      return coordinates;

    coordinateX[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (figure[i] != ',')
  {
    if (i == strlen(figure))
      return coordinates;

    coordinateY[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (figure[i] < '0' || figure[i] > '9')
  {
    if (i == strlen(figure))
      return coordinates;

    i++;
  }

  while (figure[i] != ')')
  {
    if (i == strlen(figure))
      return coordinates;

    radius[j] = figure[i];
    j++;
    i++;
  }

  coordinates.x = atof(coordinateX);
  coordinates.y = atof(coordinateY);
  coordinates.radius = atof(radius);

  return coordinates;
}

int _if_coordinates(Circle coordinates)
{
  if (coordinates.x == _INVALID_VALUE || coordinates.y == _INVALID_VALUE ||
      coordinates.radius == _INVALID_VALUE)
    return 0;
}