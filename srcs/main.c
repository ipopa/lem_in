#include "lem_in.h"
 

int init_vert(t_vert *vert)
{
  vert->start = false;
  vert->end = false;
  vert->occ = false;
  vert->wt = 100000;
  if ((vert->edges = (t_vert *)malloc(sizeof(t_vert))) == null)
    return 0;
  vert->edges = null;
  if ((vert->orig = (t_vert *)malloc(sizeof(t_vert))) == null)
    return 0;
  vert->orig = null;
  if ((vert->next = (t_vert *)malloc(sizeof(t_vert))) == null)
    return 0;
  vert->next = null;
  vert->x = 0;
  vert->y = 0;
  return 1;
}

int init_map(t_map *graph)
{
  if ((graph->vertices = (t_map *)malloc(sizeof(t_map))) == null)
    return 0;
  graph->vertices = null;
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

  i = 0;

  fd = 0;
  graph = (t_map *)malloc(sizeof(t_map));
  init_map(graph);
  if ((ret = get_next_line(fd, &line)) == -1)
    return 0;
  if ((graph->ants = ft_atoi(line)) == 0 && !ft_strequ(line, "0"))
       return 0;
  printf("nb ants = %d\n", graph->ants);
  if (parse_map(graph) == -1)
	return 0;
  return 0;
}
