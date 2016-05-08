#include "lem_in.h"

void print_vertice(t_vert *vert)
{
  if (vert->end)
    printf("- vertice end -\n");
  if (vert->start)
    printf("- vertice start -\n");
  printf("name = %s; wt = %d; x = %d; y = %d\n", vert->name, *(vert->wt), vert->x, vert->y);
  if (vert->occ)
    printf("- vertice occuped -\n");
}

void print_path(t_path *path)
{
  t_path *tmp;

  tmp = path->next;
  while (tmp != NULL)
    {
      ft_putstr(tmp->vertices->name);
      tmp = tmp->next;
    }
}

void print_mypath(char **ants, t_path *path)
{
  int i;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  i = 0;
  tmp = path->next;
  while(tmpBool != 0)
    {
      while (tmp != NULL)
	{
	  if (!ants[i] || !ft_strcmp(tmp->vertices->name, ants[i]))
	    {
	      ft_putstr("L");
	      ft_putnbr(i + 1);
	      ft_putstr("-");
	      ft_putstr(tmp->vertices->name);
	      ft_putstr(" ");
	      if (!ants[i])
		tmpBool = 0;
	      ants[i] = ft_strdup(tmp->vertices->name);
	      //	      if (tmp->next == NULL)
	      //tmpBool = 0;
	      break;
	    }
	  tmp = tmp->next;
	}
      tmp = path->next;
      i++;
    }

}

void print_graph(t_map *graph, int **tab)
{
  int i;
  int j;
  t_listpath *tmpLP;
  char **ants;

  printf("total: %d\n", tab[0][1]);
  i = 1;
  j = 0;
  tmpLP = graph->listpath;
  ants = (char **)malloc(sizeof(*ants) * (graph->ants + 1));
  while(42)
    {
      print_mypath(ants, tmpLP->path);
      
      // print_path(tmpLP->path);
      ft_putstr(" \n");
      tmpLP = tmpLP->next;
      j++;
      if (!tmpLP)
	{
	  if (i == 2)
	    break ;
	  ft_putstr("\n");
	  i++;
	  tmpLP = graph->listpath;
	}
    }
}
