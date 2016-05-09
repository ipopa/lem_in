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

int next(t_path **tab, int max)
{
  int i;
  
  i = 0;
  while (i < max)
    {
      if (tab[i])
	tab[i] = tab[i]->next;
      i++;
    }
  return (1);
}


void print_tab(t_path **tab, int max)
{
  int i;
  
  i = 0;
  while (i < max)
    {
      if (tab[i])
	printf("L%d-%s\n", i, (tab[i])->vertices->name);
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
  while (maxants)
    {
       tab[ants] = set_p(graph, nbpath);
      
      nbpath++;
      if (nbpath > graph->nbpath)
	{
	  next(tab, graph->ants);
	  print_tab(tab, graph->ants);
	  printf("FIN DE TOUR\n\n");
	  nbpath = 1;
	}
      maxants -= 1;
      ants += 1;
    }
}
