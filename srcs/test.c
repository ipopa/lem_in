#include "lem_in.h"


t_path *set_p(t_map *graph, int nbpath)
{
  t_listpath *tmp;
  int  i;
  
  tmp = graph->listpath;
  i = 0;
  while (i++ < nbpath)
    tmp = tmp->next;
  return tmp->path;

}

int next(t_pat **tab)
{



}


void print_tab(t_path **tab, int max)
{
  int i;
  
  i = 0;
  while (i < max)
    {

      if (tab[i])
	printf("L-%s\n", (tab[i])->vertices->name);
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
  nbpath = 0;
  tab = (t_path **)malloc(sizeof(t_path) * graph->ants);
  while (maxants)
    {

      tab[ants] = set_p(nbpath);

      //next(tab);
      
      maxants -= 1;
      nbpath++;
      if (nbpath > graph->nbpath)
	{
	  print_tab(tab, graph->ants);
	  printf("FIN DE TOUR\n");
	  nbpath = 0;
	}
      ants += 1;
    }
}
