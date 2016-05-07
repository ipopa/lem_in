#include "lem_in.h"
 

int init_vert(t_vert *vert)
{
  vert->start = false;
  vert->end = false;
  vert->occ = false;
  vert->wt = (int *)malloc(sizeof(int));
  *(vert->wt) = INT_MAX; 
  vert->edges = NULL;
  vert->orig = NULL;
  vert->next = NULL;
  vert->x = 0;
  vert->y = 0;
  vert->visited = false;
  return 1;
}

int init_map(t_map *graph)
{
  graph->vertices = NULL;
  graph->ants = 0;
  graph->listpath = NULL;
  graph->maxpath = 0;
  graph->end = NULL;
  graph->start = NULL;
  return 1;
}

int main(int ac, char **av)
{
  char *line;
  t_map *graph;
  int fd;
  int ret;
  int ants;

  fd = 0;
  ants = 0;
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
