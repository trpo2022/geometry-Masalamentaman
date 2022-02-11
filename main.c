#include <stdio.h>
#include <string.h>
#define _STRING_LENGTH 100

typedef struct
{
  float x;
  float y;
  float radius;
} Circle;

int main()
{
  Circle circle;
  char Figure[_STRING_LENGTH];

  printf("Введите фигуру: ");
  fgets(Figure, _STRING_LENGTH, stdin);
  printf("%s", Figure);
}