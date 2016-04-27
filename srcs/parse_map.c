#include "lem_in.h"

int parse_map(t_map *graph)
{
  char *line;
  int ret;

  while ((ret = get_next_line(0, &line)) >= 0)
    {
      printf("%s\n", line);
      if (ret == 0)
        break;
    }
  return 1;
}
