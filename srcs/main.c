#include "lem_in.h"
 

int init_vert(t_vert *vert)
{
  vert->start = false;
  vert->end = false;
  vert->occ = false;
  vert->wt = 100000;
  if ((vert->edges = (t_edge *)malloc(sizeof(t_edge))) == NULL)
    return 0;
  vert->edges = NULL;
  //  if ((vert->orig = (t_vert *)malloc(sizeof(t_vert))) == NULL)
  //  return 0;
  // vert->orig = NULL;
  vert->next = NULL;
  vert->x = 0;
  vert->y = 0;
  return 1;
}

int init_map(t_map *graph)
{
  if ((graph->vertices = (t_vert *)malloc(sizeof(t_vert))) == NULL)
    return 0;
  graph->vertices = NULL;
  graph->ants = 0;
  return 1;
}

int main(int ac, char **av)
{
  char *line;
  t_map *graph;
  int fd;
  int i;
  int ret;
  int ants;

  i = 0;

  fd = 0;

  if ((ret = get_next_line(fd, &line)) == -1)
    return 0;
  if ((ants = ft_atoi(line)) == 0 && !ft_strequ(line, "0"))
    return 0;
  graph = (t_map *)malloc(sizeof(t_map));
  init_map(graph);
  graph->ants = ants;
  printf("nb ants = %d\n", graph->ants);
  parse_map(graph);
  destroy_map(graph);
  return 0;
}
