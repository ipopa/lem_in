#include "lem_in.h"
 
int parse_map(char *line, t_map *graph)
{
  printf("%s\n", line);

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
  if ((ret = get_next_line(fd, &line)) == -1)
    return 0;
  if ((graph->ants = ft_atoi(line)) == 0 && !ft_strequ(line, "0"))
       return 0;
  printf("nb ants = %d\n", graph->ants);
  while ((ret = get_next_line(fd, &line)) >= 0)
    {
      if (parse_map(line, graph) == -1)
	return 0;
      if (ret == 0)
	break;
    }
  return 0;
}
