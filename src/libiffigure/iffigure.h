#pragma once
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE          1
#define FALSE         0
#define STRING_LENGTH 100
#define INVALID_VALUE -919939
#define IS_CIRCLE     11

typedef struct
{
  float x;
  float y;
  float radius;
  int flag_x;
  int flag_y;
  int flag_radius;
} Circle;

int _if_circle(char *figure);
int _if_staples(char *figure);
Circle _read_coordinates(char *figure);
void _check_coordinates(Circle *coordinates);
double _area_of_circle(Circle coordinates);
double _perimeter_of_circle(Circle coordinates);