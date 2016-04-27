#include "lem_in.h"


int error(char *err)
{
  ft_putstr(err);
  return 1;
}

void print_vertice(t_vert *vert)
{
  if (vert->end)
    printf("- vertice end -\n");
  if (vert->start)
    printf("- vertice start -\n");
  printf("name = %s; wt = %d; x = %d; y = %d\n", vert->name, vert->wt, vert->x, vert->y);
  if (vert->occ)
    printf("- vertice occuped -\n");
}
