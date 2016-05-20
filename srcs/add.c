#include "lem_in.h"

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
      if (ft_strequ(tmpvert->name, new->name))
	return -1;
      tmpvert = tmpvert->next;
      i++;
    }
  tmpvert->next = new;
  return 1;
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
      tmpedge = tmpedge->next;
      i++;
    }
  tmpedge->next = newedge;
  return 1;
}

int add_vert(t_map *graph, char *line, bool start, bool end)
{
  t_vert *new;
  char **tab;

  new = init_vert();
  tab = ft_strsplit(line, &ft_isspace);
  if (tab[0] != 0)
    new->name = ft_strdup(tab[0]);
  if (tab[1])
    {
      new->x = ft_atoi(tab[1]);
      if (tab[2])
        new->y = ft_atoi(tab[2]);
    }
  free_tab(tab);
  if (start)
    {
      new->start = true;
      *(new->wt) = 0;
      graph->start = new;
    }
  if (end)
    {
      graph->end = new;
      new->end = true;
    }
  if (add_vert_to_map(&(graph->vertices), new) == -1)
    return -1;
  return 1;
}

int my_isline(char c)
{
  if (c == '-')
    return (1);
  return (0);
}

int add_edge(t_map *graph, char *line)
{
  char **tab;
  t_vert *v1;
  t_vert *v2;

  tab = ft_strsplit(line, &my_isline);
  v1 = find_vert(graph->vertices, tab[0]);
  v2 = find_vert(graph->vertices, tab[1]);
  free_tab(tab);
  if (!v1 || !v2)
    return -1;
  if (add_edge_to_map(&(v1->edges), v2) == -1)
    return -1;
  if (add_edge_to_map(&(v2->edges), v1) == -1)
    return -1;
  return 1;
}
