#include "lem_in.h"

void print_vertice(t_vert *vert)
{
  if (vert->end)
    printf("- vertice end -\n");
  if (vert->start)
    printf("- vertice start -\n");
  printf("name = %s; wt = %d; x = %d; y = %d\n", vert->name, *(vert->wt), vert->x, vert->y);
  if (vert->occ)
    printf("- vertice occuped -\n");
}

void print_path(t_path *path)
{
  while (path != NULL)
    {
      print_vertice(path->vertices);
      path = path->next;
    }
}
