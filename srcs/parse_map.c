#include "lem_in.h"


void print_map(t_map *map)
{
  t_map *tmp;
  
  tmp = map;
  while (tmp->vertices != NULL)
    {
      print_vertice(tmp->vertices);
      tmp->vertices = tmp->vertices->next;
    }
}

int add_to_map(t_vert **vert, t_vert *new)
{
  int i;
  t_vert *tmpvert;
  

  printf("ADD TO MAP\n");
  i = 0;
  tmpvert = (t_vert *)malloc(sizeof(t_vert));
  tmpvert = *vert;
  print_vertice(new);
  if (*vert == NULL)
    {
      printf("first elem\n");
      *vert = new;
      return 1;
     }
  while (tmpvert != NULL)
  {
    printf("+%d\n", i);
    tmpvert = tmpvert->next;
    i++;
  }
  if (tmpvert == NULL)
    {
      printf("ADD VERTICE\n");
      tmpvert = new;
    }
  //print_map(*map);
  print_vertice(*vert);
  
  if ((*vert)->next != NULL)
    print_vertice((*vert)->next);
  printf("FIN ADD\n");
  return 1;
}

int add_vert(t_map *graph, char *line, bool start, bool end)
{
  t_vert *new;
  char **tab;

  printf("ADD VERT\n");
  new = (t_vert *)malloc(sizeof(t_vert));
  init_vert(new);
  tab = ft_strsplit(line, ' ');
  
  //printf("tab[0] = %s\n", tab[0]);
  if (tab[0])
    new->name = strdup(tab[0]);
  //printf("TEST");
  if (tab[1])
    new->x = ft_atoi(tab[1]);
  //printf("TEST");
  if (tab[2])
    new->y = ft_atoi(tab[2]);
  //printf("TEST"); 
 if (start)
    new->start = true;
  if (end)
    new->end = true;
  //printf("TEST2");
  if (add_to_map(&(graph->vertices), new) == -1)
      return -1;
  return 1;

}

int add_edge(t_map **graph, char *line)
{
  char **tab;
  
  tab = ft_strsplit(line, ' ');
  return 1;
}


int parse_line(t_map *graph, char *line, bool start, bool end)
{
  printf("PARSE LINE\n");
  if (add_vert(graph, line, start, end) == -1)
    return -1;
  //else if (add_edge(&graph, line) == -1)
  //return -1;
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
  if (end || start)
    error("manque le vertice start ou end\n");
  return 1;
}
