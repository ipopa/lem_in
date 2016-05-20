#include "lem_in.h"

int main(void)
{
  char *line;
  t_map *graph;
  int ret;
  int ants;

  line = NULL;
  if ((ret = get_next_line(0, &line)) != -1 && (ants = ft_atoi(line)) > 0)
    {
      graph = init_map();
      graph->ants = ants;
      parse_map(graph);
      destroy_map(graph);
    }
  else
    error();
  if (line)
    free(line);
  return (0);
}
