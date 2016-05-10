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
	  ft_putnbr(i + 1);
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

  nbpath = 1;
  tab = (t_path **)malloc(sizeof(t_path *) * (graph->ants + 1));
  ants = 0;
  while (ants < graph->ants)
    tab[ants++] = NULL;
  ants = 0;
  while (42)
    {
      if (!tab[ants])
	tab[ants] = set_p(graph, nbpath);
      nbpath++;
      if (nbpath > graph->nbpath)
	{
	  next(tab, graph->ants);
	  print_tab(tab, graph->ants);
	  ft_putchar('\n');
	  nbpath = 1;
	}
      if (ants < (graph->ants - 1))
	ants++;
      if (ants == (graph->ants - 1) && tab[ants] && (tab[ants])->vertices->end)
	break ;
    }
  free(tab);
}
