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

void print_mypath(int *i, char **ants, t_path *path)
{
  int j;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  j = *i;
  tmp = path->next;
  while(tmpBool != 0)
    {
      if (ants[j])
	{
	  while (tmp != NULL)
	    {
	      if (ft_strequ(tmp->vertices->name, ants[j]))
		{
		  tmp = tmp->next;
		  break ;
		}
	      tmp = tmp->next;
	    }
	}
      else
	{
	  ants[j] = ft_strdup(tmp->vertices->name);
	  tmpBool = 0;
	}
      if (!tmp)
	break ;
      ft_putstr("L");
      ft_putnbr(j + 1);
      ft_putstr("-");
      ft_putstr(tmp->vertices->name);
      ft_putstr(" ");
      tmp = path->next;
      j++;
    }
}

void print_print(int i, char *str)
{
  ft_putstr("L");
  ft_putnbr(i);
  ft_putstr("-");
  ft_putstr(str);
  ft_putstr(" ");
}

int print_ant(int i, char **ants, t_path *path)
{
  int j;
  t_path *tmp;
  int tmpBool;

  tmpBool = 1;
  j = i;
  tmp = path->next;
  if (ants[j])
    {
      while (tmp != NULL)
	{
	  if (ft_strequ(tmp->vertices->name, ants[j]))
	    {
	      tmp = tmp->next;
	      break ;
	    }
	  j++;
	  tmp = tmp->next;
	}
      if (tmp)
	{
	  ants[j] = ft_strdup(tmp->vertices->name);
	  print_print(j + 1, ants[j]);
	}
    }
  else
    {
      ants[j] = ft_strdup(tmp->vertices->name);
      print_print(j + 1, ants[j]);
    }
  if (j > i)
    i++;
  return i;
}

void print_graph(t_map *graph, int **tab)
{
  int i;
  int j;
  t_listpath *tmpLP;
  char **ants;
  int *antsLP;

  printf("total: %d\n", tab[0][1]);
  i = 1;
  j = 0;
  tmpLP = graph->listpath;
  ants = (char **)malloc(sizeof(*ants) * (graph->ants + 1));
  antsLP = (int *)malloc(sizeof(antsLP) * (graph->nbpath + 1));

  while(j <= graph->ants)
    {
      ants[j] = 0;
      j++;
    }
  j = 0;
  int tmpJ;
  while(42)
    {
      tmpJ = j;
      if (!antsLP[j])
	{
	  antsLP[j] = i;
	}
      j = print_ant(j, ants, tmpLP->path);
      i++;
      tmpLP = tmpLP->next;
      if (!tmpLP)
	{
          i = 0;
	  if (j == tmpJ)
	    j = 0;
	  ft_putstr("\n");
	  tmpLP = graph->listpath;
	}
      else
	j++;
      if (j == graph->ants && i == graph->nbpath)
	break ;
    }
}
