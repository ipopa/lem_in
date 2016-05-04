#include "lem_in.h"


void print_map(t_map *map)
{
  t_map *tmp;
  
  tmp = map;
  printf("\n- MAP -\n");
  while (tmp->vertices != NULL)
    {
      print_vertice(tmp->vertices);
      tmp->vertices = tmp->vertices->next;
    }
}

int add_vert_to_map(t_vert **vert, t_vert *new)
{
  int i;
  t_vert *tmpvert;
  
  i = 0;
  tmpvert = *vert;
  if (*vert == NULL)
    {
      *vert = new;
      return 1;
     }
  while (tmpvert->next != NULL)
    {
      if (check_vert(tmpvert, new) == -1)
	return -1;
      tmpvert = tmpvert->next;
      i++;
    }
  tmpvert->next = new;
  return 1;
}

int add_edge_to_map(t_vert **edge, t_vert *new)
{
  int i;
  t_vert *tmpedge;
  
  i = 0;
  tmpedge = *edge;

  if (*edge == NULL)
    {
      *edge = new;
      return 1;
     }
  if (tmpedge->next == NULL) {
    printf("next null\n");
  }
  while (tmpedge->next != NULL)
    {
      if (check_vert(tmpedge, new) == -1)
	return -1;
      tmpedge = tmpedge->next;
      i++;
    }
  tmpedge->next = new;
  return 1;
}

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

int add_vert(t_map *graph, char *line, bool start, bool end)
{
  t_vert *new;
  char **tab;

  new = (t_vert *)malloc(sizeof(t_vert));
  init_vert(new);

  tab = ft_strsplit(line, ' ');

  if (tab[0] != 0) 
    new->name = ft_strdup(tab[0]);
  if (tab[1])
    {
      new->x = ft_atoi(tab[1]);
      if (tab[2])
	new->y = ft_atoi(tab[2]);
    }
 if (start)
    new->start = true;
  if (end)
    new->end = true;

  if (add_vert_to_map(&(graph->vertices), new) == -1)
      return -1;
  return 1;

}

int add_edge(t_map *graph, char *line)
{
  char **tab;
  t_vert *v1;
  t_vert *v2;

  
  tab = ft_strsplit(line, '-');
  printf("add egde\n");
  v1 = find_vert(graph->vertices, tab[0]);
  v2 = find_vert(graph->vertices, tab[1]);
  print_vertice(v1);
  print_vertice(v2);
  if (add_edge_to_map(&(v1->edges), v2) == -1)
      return -1;
  if (add_edge_to_map(&(v2->edges), v1) == -1)
    return -1;
  printf("fin egde\n");
  
  return 1;
}


int parse_line(t_map *graph, char *line, bool start, bool end)
{
  if (ft_searchchr(line, '-') && ft_words(line, '-') == 2)
    {
      if (add_edge(graph, line) == -1)
	return -1;
    }
  else {
    add_vert(graph, line, start, end);
   
  }
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
      if (ft_strequ(line, "##start"))
	  start = true;
      else if (ft_strequ(line, "##end"))
	end = true;
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
  print_map(graph);
  if (end || start)
    error("manque le vertice start ou end\n");
  return 1;
}
