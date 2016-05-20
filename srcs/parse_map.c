#include "lem_in.h"

t_vert *find_vert(t_vert *vert, char *name)
{
  t_vert *tmp;

  tmp = vert;
  while (tmp != NULL)
    {
      if (ft_strequ(tmp->name, name))
        return (tmp);
      tmp = tmp->next;
    }
  return NULL;
}

int parse_line(t_map *graph, char *line, bool start, bool end)
{
  if (ft_searchchr(line, &ft_isspace) && ft_words(line, &ft_isspace) == 3)
    {
      if (add_vert(graph, line, start, end) == -1)
	{
	  graph->error = true;
	  return -1;
	}
    }
  else if (ft_searchchr(line, &my_isline) && ft_words(line, &my_isline) == 2)
    {
      if (add_edge(graph, line) == -1)
	return -1;
    }
  else
    {
      return -1;
    }
  return 1;
}

int count_edge(t_vert *vert)
{
  int i;
  t_edge *tmp;

  i = 0;
  tmp = vert->edges;
  while(tmp != NULL)
    {
      i++;
      tmp = tmp->next;
    }
  return i;
}

void get_map(t_map *graph)
{
  char *line;
  int ret;

  while ((ret = get_next_line(0, &line)) >= 0)
    {
      if (ft_strequ(line, "##start"))
	graph->startB = true;
      else if (ft_strequ(line, "##end"))
	graph->endB = true;
      else if(line[0] == '#')
	{
	  free(line);
	  continue ;
	}
      else if(line[0] == 'L')
	{
	  graph->error = true;
	  break ;
	}
      else
	{
	  if (parse_line(graph, line, graph->startB, graph->endB) == -1)
	    break ;
	  graph->startB = false;
	  graph->endB = false;
	}
      free(line);
      line = NULL;
      if (ret == 0)
	break ;
    }
  if (line)
    free(line);
}

int parse_map(t_map *graph)
{
  graph->startB = false;
  graph->endB = false;
  graph->error = false;
  get_map(graph);
  if (graph->endB || graph->startB || !graph->start || !graph->end || graph->error)
    {
      error();
      return -1;
    }
  if (ft_algo(graph) == -1)
    {
      error();
      return -1;
    }
  return 1;
}
