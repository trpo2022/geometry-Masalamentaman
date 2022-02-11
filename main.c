#include "iffigure.c"

int main()
{
  Circle circle;
  char Figure[_STRING_LENGTH];
  int flagCircle = 0;
  int flagStaples = 0;
  int flagCoordinates = 0;

  printf("Введите данные фигуры согласно образцу:\n");
  printf("circle(0 0, 1.5)\n");
  printf("Ввод: ");
  fgets(Figure, _STRING_LENGTH, stdin);

  flagStaples = _if_staples(Figure);
  flagCircle = _if_circle(Figure);
  circle = _read_coordinates(Figure);
  flagCoordinates = _if_coordinates(circle);

  if (flagCircle)
  {
    printf("Название фигуры: ");

    if (flagCircle == __IS_CIRCLE)
      printf("Circle");

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

  if (flagCoordinates != 0)
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