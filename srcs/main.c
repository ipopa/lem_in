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
  //get_ants(line);
  while ((ret = get_next_line(fd, &line)) >= 0)
    {
      if (parse_map(line, graph) == -1)
	return 0;
      if (ret == 0)
	break;
    }

  return 0;
}
