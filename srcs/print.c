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

void add_to_tab(char **tab, int i, int nb, t_path *path, t_map *graph)
{
  char *tmpStr;
  t_path *tmp;
  char ant[4];
  char *str;

  tmp = path->next;

  //il faut ft_itoa [ 
  ant[0] = 'L';
  ant[1] = nb + 48 + 1;
  ant[2] = '-';
  ant[3] = 0;
  // ]

  while (tmp)
    {
      str = ft_strjoin(ant, tmp->vertices->name);
      tmpStr = ft_strjoin(str, " ");
      free(str);
      if (tab[i])
	{
	  str = ft_strjoin(tab[i], tmpStr);
	  free(tmpStr);
	  free(tab[i]);
	  tab[i] = ft_strdup(str);
	  free(str);
	}
      else
	{
	  tab[i] = ft_strdup(tmpStr);
	  free(tmpStr);
	}
      i++;
      tmp = tmp->next;
    }
}

void print_graph(t_map *graph, int **tab)
{
  int i;
  int nb;
  t_listpath *tmpLP;
  char **tabAll;
  int wpath;
  int j;

  tabAll = (char **)malloc(sizeof(char *) * (graph->ants + 1));
  wpath = 1;
  i = 0;
  nb = 0;
  while(nb < graph->ants)
    {
      if (tab[wpath - 1][1] > 0)
	{
	  tmpLP = graph->listpath;
	  j = 0;
	  while (j < wpath - 1)
	    {
	      tmpLP = tmpLP->next;
	      j++;
	    }
	  if (tmpLP)
	    {
	      add_to_tab(tabAll, i, nb, tmpLP->path, graph);
	      tab[wpath - 1][1]--;
	    }
	}
      wpath++;
      if (wpath > graph->nbpath)
	{
	  wpath = 1;
	  i++;
	}
      nb++;
    }

  j = 0;
  while(j < graph->ants && tabAll[j])
    {
      ft_putendl(tabAll[j]);
      j++;
    }
}
