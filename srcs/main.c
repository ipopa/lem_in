#include "lem_in.h"


int parse_map(char *line, t_map *graph)
{


  return 1;
}

int main(int ac, char **av)
{
  char *line;
  t_map *graph;
  int fd;
  int i;

  i = 0;
  fd = 1;

  if (get_next_line(fd, &line) == -1)
    return 0;
  //get_ants(line);
  while(get_next_line(fd, &line) == 1)
    {
      if (parse_map(line, graph) == -1)
	return 0;     
    }

  printf("%s\n", "hello world");

  return 0;
}
