#include "lem_in.h"


int add_to_map(t_map *map, t_vert *vertice)
{
  
  return 1;
}

int add_vert(t_map *graph, char *line, bool start, bool end)
{
  t_vert *new;
  char **tab;

  new = (t_vert *)malloc(sizeof(t_vert));
  init_vert(new);
  tab = ft_strsplit(line, ' ');
  
  if (tab[0])
    new->name = ft_strdup(tab[0]);
  if (tab[1])
    new->x = ft_atoi(tab[1]);
  if (tab[2])
    new->y = ft_atoi(tab[2]);
  if (start)
    new->start = true;
  if (end)
    new->end = true;
  if (add_to_map(graph, new) == -1)
      return -1;
  print_vertice(new);
  return 1;

}

int add_edge(t_map *graph, char *line)
{
  char **tab;
  
  tab = ft_strsplit(line, ' ');
  return 1;
}


int parse_line(t_map *graph, char *line, bool start, bool end)
{
  if (add_vert(graph, line, start, end) == -1)
    return -1;
  else if (add_edge(graph, line) == -1)
    return -1;
  return 1;
}


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
	  start = true;
      else if (ft_strequ(line, "##end"))
	  printf("end\n");
      else if(line[0] == '#')
	continue ;
      else
	{
	  if (parse_line(graph, line, start, end) == -1)
	    return -1;
	  start = false;
	  end = false;
	}
      if (ret == 0)
        break;
    }
  return 1;
}
