#include "lem_in.h"

t_path *set_p(t_map *graph, int nbpath)
{
  t_listpath *tmp;
  
  tmp = graph->listpath;

  while (nbpath--)
    tmp = tmp->next;
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

void print_graph(t_map *graph)
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
  int tmpCoups = 0;
  while (42)
    {
      // printf("hello0\n");
      if (!tab[ants])
	{
	  printf("nbpath %d = %d\n", nbpath, graph->tabpath[nbpath - 1][1]);
	  if (graph->tabpath[nbpath - 1][1])
	    {
	      //   printf("hello1\n");
	      tab[ants] = set_p(graph, nbpath - 1);
	      graph->tabpath[nbpath - 1][1]--;
	    }
	  else
	    {
	      // printf("hello2\n");
	      nbpath++;
	      if (nbpath > graph->nbpath)
		{
		  next(tab, graph->ants);
		  print_tab(tab, graph->ants);
		  nbpath = 1;
		  tmpCoups++;
		}
	      continue ;
	    }
	}
      nbpath++;
      if (nbpath > graph->nbpath)
	{
	  next(tab, graph->ants);
	  print_tab(tab, graph->ants);
	  ft_putchar('\n');
	  nbpath = 1;
	  tmpCoups++;
	}
      if (ants < (graph->ants - 1))
	ants++;
      if (ants == (graph->ants - 1) && tab[ants] && (tab[ants])->vertices->end)
	break ;
    }
  ft_putnbr(graph->listpath->nbelem);
  ft_putchar('\n');
  ft_putnbr(tmpCoups);
  ft_putchar('\n');
  while (graph->listpath->path)
    {
      ft_putstr(graph->listpath->path->vertices->name);
      ft_putchar('-');
      graph->listpath->path = graph->listpath->path->next;
    }
  ft_putchar('\n');
  free(tab);
}
