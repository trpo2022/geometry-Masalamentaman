#include <libiffigure/iffigure.h>

int _if_circle(char *figure)
{
  int i = 0;

  while ((figure[i] < 'a' || figure[i] > 'z') &&
         (figure[i] < 'A' || figure[i] > 'Z'))
    i++;
  if ((figure[i + 0] == 'c' || figure[i + 0] == 'C') &&
      (figure[i + 1] == 'i' || figure[i + 1] == 'I') &&
      (figure[i + 2] == 'r' || figure[i + 2] == 'R') &&
      (figure[i + 3] == 'c' || figure[i + 3] == 'C') &&
      (figure[i + 4] == 'l' || figure[i + 4] == 'L') &&
      (figure[i + 5] == 'e' || figure[i + 5] == 'E'))
  {
    return IS_CIRCLE;
  }
  else
    return FALSE;
}

int _if_staples(char *figure)
{
  size_t i = 0;
  int first = 0, second = 0;

  for (i = 0; i < strlen(figure); i++)
  {
    if (figure[i] == '(')
      first++;
    if (figure[i] == ')')
      second++;
  }

  if (first != 1 || second != 1)
    return FALSE;

  return TRUE;
}

Circle _read_coordinates(char *figure)
{
  Circle coordinates = {.x = INVALID_VALUE,
                        .y = INVALID_VALUE,
                        .radius = INVALID_VALUE,
                        .flag_x = 1,
                        .flag_y = 1,
                        .flag_radius = 1};
  char coordinateX[STRING_LENGTH];
  char coordinateY[STRING_LENGTH];
  char radius[STRING_LENGTH];
  size_t i = 0;

  while (!(isdigit(figure[i])))
  {
    if (i == strlen(figure))
      break;

    i++;
  }

  int j = 0;

  while (figure[i] != ' ')
  {
    if (i == strlen(figure))
      break;

    coordinateX[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (figure[i] != ',')
  {
    if (i == strlen(figure))
      break;

    coordinateY[j] = figure[i];
    j++;
    i++;
  }

  j = 0;

  while (!(isdigit(figure[i])))
  {
    if (i == strlen(figure))
      break;

    i++;
  }

  while (figure[i] != ')')
  {
    if (i == strlen(figure))
      break;

    radius[j] = figure[i];
    j++;
    i++;
  }

  i = 0;
  while (coordinateX[i] != '.')
  {
    if (i == strlen(coordinateX))
      break;
    i++;
  }

  if (coordinateX[i] == '.' && !(isdigit(coordinateX[i + 1])))
    coordinates.flag_x = 0;

  i = 0;
  while (coordinateY[i] != '.')
  {
    if (i == strlen(coordinateY))
      break;
    i++;
  }

  if (coordinateY[i] == '.' && !(isdigit(coordinateY[i + 1])))
    coordinates.flag_y = 0;

  i = 0;
  while (radius[i] != '.')
  {
    if (i == strlen(radius))
      break;
    i++;
  }

  if (radius[i] == '.' && !(isdigit(radius[i + 1])))
    coordinates.flag_radius = 0;

  for (i = 0; i < strlen(coordinateX); i++)
  {
    if (isdigit(coordinateX[i]) &&
        (!(isdigit(coordinateX[i + 1])) && coordinateX[i + 1] != '.') &&
        isdigit(coordinateX[i + 2]))
      coordinates.flag_x = 0;
  }

  for (i = 0; i < strlen(coordinateY); i++)
  {
    if (isdigit(coordinateY[i]) &&
        (!(isdigit(coordinateY[i + 1])) && coordinateY[i + 1] != '.') &&
        isdigit(coordinateY[i + 2]))
      coordinates.flag_y = 0;
  }

  for (i = 0; i < strlen(radius); i++)
  {
    if (isdigit(radius[i]) &&
        (!(isdigit(radius[i + 1])) && radius[i + 1] != '.') &&
        isdigit(radius[i + 2]))
      coordinates.flag_radius = 0;
  }

  coordinates.x = atof(coordinateX);
  coordinates.y = atof(coordinateY);
  coordinates.radius = atof(radius);

  return coordinates;
}

void _check_coordinates(Circle *coordinates)
{
  if (coordinates->x == INVALID_VALUE)
    coordinates->flag_x = 0;
  if (coordinates->y == INVALID_VALUE)
    coordinates->flag_y = 0;
  if (coordinates->radius == INVALID_VALUE)
    coordinates->flag_radius = 0;

  return;
}

double _area_of_circle(Circle coordinates)
{
  return (coordinates.radius * coordinates.radius) * M_PI;
}

double _perimeter_of_circle(Circle coordinates)
{
  return 2 * coordinates.radius * M_PI;
}