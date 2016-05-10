#include "lem_in.h"


t_path *set_p(t_map *graph, int nbpath)
{
  t_listpath *tmp;
  int  i;
  
  tmp = graph->listpath;
  i = 1;

  while (i < nbpath)
    {
      tmp = tmp->next;
      i++;
    }
  return tmp->path;
}

void next(t_path **tab, int max)
{
  int i;
  
  i = 0;
  while (i < max)
    {
      if (tab[i])
	tab[i] = tab[i]->next;
      i++;
    }
}


void print_tab(t_path **tab, int max)
{
  int i;
  
  i = 0;
  while (i < max)
    {
      if (tab[i])
	{
	  ft_putchar('L');
	  ft_putnbr(i);
	  ft_putchar('-');
	  ft_putstr((tab[i])->vertices->name);
	  ft_putchar(' ');
	}
      i++;
    }

}

void test(t_map *graph)
{
  t_path **tab;
  int ants;
  int nbpath;
  int maxants;

  maxants = graph->ants;
  ants = 1;
  nbpath = 1;
  tab = (t_path **)malloc(sizeof(t_path) * graph->ants);
  int y = 0;
  while (y < graph->ants)
    tab[y++] = NULL;
  while (ants <= maxants)
    {
      tab[ants] = set_p(graph, nbpath);
      
      nbpath++;
      if (nbpath > graph->nbpath)
	{
	  next(tab, graph->ants);
	  print_tab(tab, graph->ants);
	  ft_putchar('\n');
	  nbpath = 1;
	}
      ants++;
    }
  free(tab);
}
