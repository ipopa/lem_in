#include "lem_in.h"

t_vert *find_small_vertice(t_vert *vertice) 
{
  t_vert *tmp;
  t_vert *ret;
  int nb;

  ret = NULL;
  nb = INT_MAX;
  tmp = vertice;
  while (tmp != NULL)
    {
      if (!tmp->visited && *(tmp->wt) < nb && !tmp->occ)
	{
	  nb = *(tmp->wt);
	  ret = tmp;
	}
      tmp = tmp->next;
    }
  return ret;
}

int ft_dijkstra(t_vert *vertices, t_vert *startP, int nb)
{
  t_edge *edgeP;
  int tmpNb;
 
  if (startP == NULL) 
      return 0;
  startP->visited = true;
  if (startP->end)
      return 1;
  edgeP = startP->edges;
  while (edgeP != NULL)
    {
      if (!edgeP->connectTo->occ && !edgeP->connectTo->visited && (*(edgeP->connectTo->wt) > (nb + *(startP->wt))))
	{
	  *(edgeP->connectTo->wt) = *(startP->wt) + nb;
	  edgeP->connectTo->orig = startP;
	}
      edgeP = edgeP->next;
    } 
  if (ft_dijkstra(vertices, find_small_vertice(vertices), nb))
    return 1;
  return 0;
}

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
  i = 0;
  while(i < graph->nbpath)
    {
      printf("nombre de fourmie par ce chemin: %d\n", tab[i][1]);
      i++;
    }
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
  graph->maxpath = i;
  set_path(graph->tabpath, graph);
  print_graph(graph);
  return 1;
}
