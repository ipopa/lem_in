#include "lem_in.h"

int parse_map(t_map *graph)
{
  char *line;
  int ret;
  bool start;
  bool end;

  start = false;
  end = false;

  printf("%f\n", INFINITY);

  while ((ret = get_next_line(0, &line)) >= 0)
    {
      printf("%s\n", line);
      if (ft_strequ(line, "##start"))
	{
	  printf("start\n");
	  start = true;
	}
      else if (ft_strequ(line, "##end"))
	{
	  printf("end\n");
	  end = true;
	}
      else {
      }
      if (ret == 0)
        break;
    }
  return 1;
}
