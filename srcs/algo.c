#include "lem_in.h"

void reset_vertices(t_vert *vertices)
{
  t_vert *tmp;

  tmp = vertices;
  while (tmp != NULL)
    {
      tmp->visited = false;
      if (!tmp->start) {
	*(tmp->wt) = INT_MAX;
      }
      tmp = tmp->next;
    }
}

void set_path(int **tab, t_map *graph)
{
  int i;
  int total;
  int tmpTotal;
  float tmp;
  int tmpNbPath;

  i = 0;
  total = graph->ants;
  while (i < graph->nbpath)
    {
      total += tab[i][0];
      i++;
    }
  i = 0;
  tmpTotal = 0;
  while (i < graph->nbpath)
    {
      tmp = (float)(total - (graph->nbpath * tab[i][0])) / graph->nbpath;
      tab[i][1] = (int)tmp;
      tmpTotal += tab[i][1];
      i++;
    }
  tab[0][1] = graph->ants - tmpTotal + tab[0][1];
}

int test_nbelem(int **tab, int total, t_map *graph)
{
  int i;
  float tmp;
  int tmpFirst;
  int cof;

  i = 1;
  tmpFirst = graph->ants - tab[0][0];
  while (i <= total && total > 0)
    {
      tmpFirst += tab[i][0];
      i++;
    }
  tmp = (float)tmpFirst / (total + 1);
  if ((int)tmp < (int)(tmp + 0.5))
    tmp++;
  tmpFirst = (int)tmp;
  if (tmpFirst < tab[total][0] - 1)
    return -1;
  return 1;
}

int ft_algo(t_map *graph)
{
  int i;

  i = 0;
  graph->maxpath = count_edge(graph->end);
  graph->tabpath = (int **)malloc(sizeof(int *) * graph->maxpath);
  while (ft_dijkstra(graph->vertices, graph->start, 1) != 0 && i < graph->maxpath)
    {
      graph->tabpath[i] = (int *)malloc(sizeof(int) * 2);
      graph->tabpath[i][0] = create_path(graph, graph->end);
      if (i != 0 && test_nbelem(graph->tabpath, i, graph) == -1)
	{
	  reset_vertices(graph->vertices);
	  break ;
	}
      graph->nbpath++;
      reset_vertices(graph->vertices);
      i++;
    }
  if (i == 0)
    return -1;
  graph->maxpath = i;
  set_path(graph->tabpath, graph);
  print_graph(graph);
  return 1;
}
