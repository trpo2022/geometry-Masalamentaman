#include "iffigure.c"

int main()
{
  Circle circle;
  char Figure[_STRING_LENGTH];
  int flagCircle = 0;
  int flagStaples = 0;
  int flagCoordinates = 0;
  int i;

  printf("Введите фигуру: ");
  fgets(Figure, _STRING_LENGTH, stdin);

  i = 0;

  flagStaples = _if_staples(Figure);
  flagCircle = _if_circle(Figure);
  circle = _read_coordinates(Figure);
  flagCoordinates = _if_coordinates(circle);

  if (flagCircle)
  {
    printf("Название фигуры: ");

    for (i = 0; Figure[i] != '('; i++)
    {
      printf("%c", Figure[i]);
    }

    printf("\n");
  }

  else
  {
    printf("Название фигуры: INCORRECT\n");
  }

  if (!flagStaples)
  {
    printf("Скобки введены не по образцу.\n");
  }

  if (flagCoordinates)
  {
    printf("Координата X: %.4f\n", circle.x);
    printf("Координата Y: %.4f\n", circle.y);
    printf("Радиус: %.4f\n", circle.radius);
  }

  else
  {
    printf("Координата X: INCORRECT\n");
    printf("Координата Y: INCORRECT\n");
    printf("Радиус: INCORRECT\n");
  }

  return 0;
}