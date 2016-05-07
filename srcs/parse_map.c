#include "lem_in.h"


void print_map(t_map *map)
{
  t_vert *tmp;
  t_edge *tmpE;
  
  tmp = map->vertices;
  printf("\n- MAP -\n");
  while (tmp != NULL)
    {
      print_vertice(tmp);
      tmpE = tmp->edges;
      while (tmpE != NULL)
	{
	  printf("\t Connect To %s\n", tmpE->connectTo->name);
	  tmpE = tmpE->next;

	}
      tmp = tmp->next;
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

t_edge *init_edge(t_vert *new)
{
  t_edge *newedge;

  if ((newedge = (t_edge *)malloc(sizeof(t_edge))) == NULL)
    return NULL;
  newedge->connectTo = new;
  newedge->next = NULL;
  return newedge;
}

int add_edge_to_map(t_edge **edge, t_vert *new)
{
  int i;
  t_edge *tmpedge;
  t_edge *newedge;
  
  i = 0;
  tmpedge = *edge;
  newedge = init_edge(new);
  if (*edge == NULL)
    {
      *edge = newedge;
      return 1;
    }
  while (tmpedge->next != NULL)
    {
      //if (check_vert(tmpedge, new) == -1)
      //return -1;
      tmpedge = tmpedge->next;
      i++;
    }
  tmpedge->next = newedge;
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
  int j;

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

  free_tab(tab);
 
  if (start) {
    new->start = true;
    *(new->wt) = 0;
    graph->start = new;
  }
  if (end) {

    graph->end = new;
    new->end = true;
  }
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
  v1 = find_vert(graph->vertices, tab[0]);
  v2 = find_vert(graph->vertices, tab[1]);
 
  free(tab);
  if (add_edge_to_map(&(v1->edges), v2) == -1)
    return -1;
  if (add_edge_to_map(&(v2->edges), v1) == -1)
    return -1;
    
  return 1;
}


int parse_line(t_map *graph, char *line, bool start, bool end)
{
  if (ft_searchchr(line, '-') && ft_words(line, '-') == 2)
    {
      if (add_edge(graph, line) == -1)
	return -1;
    }
  else if (ft_searchchr(line, ' ') && ft_words(line, ' ') == 3)
    {
      if (add_vert(graph, line, start, end) == -1)
	return -1;   
    }
  else {
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

int parse_map(t_map *graph)
{
  char *line;
  int ret;
  bool start;
  bool end;
  int i;

  start = false;
  end = false;
  i = 0;

  printf("%d\n", INT_MAX);

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
  if (end || start) 
    {

      error("manque le vertice start ou end\n");
      return -1;
    }
  graph->maxpath = count_edge(graph->end);
  printf("graph->maxpath = %d\n", graph->maxpath);
  print_map(graph);
  while (ft_dijkstra(graph->vertices, graph->start, 1) != 0 && i < graph->maxpath) 
    {
      printf("ok\n");
      create_path(graph, graph->end);

      clean_vertices(graph->vertices);
      i++;
    }
  set_path(graph);
  return 1;
}
