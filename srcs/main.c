#include "lem_in.h"

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
  free(line);
  graph = (t_map *)malloc(sizeof(t_map));
  init_map(graph);
  graph->ants = ants;
  printf("nb ants = %d\n", graph->ants);
  parse_map(graph);
  destroy_map(graph);
  return 0;
}
