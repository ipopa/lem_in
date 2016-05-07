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
    {
      return 0;
    }

  startP->visited = true;

  if (startP->end)
    {
      return 1;
    }

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
  if (ft_dijkstra(vertices, find_small_vertice(vertices), nb)) {
    return 1;
  }
  return 0;
}

void clean_vertices(t_vert *vertices)
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

void set_path(t_map *graph)
{
  int minNb;
  int ants;
  t_listpath *tmpLP;
  int sum;
  int tmpNb;

  tmpNb = 0;
  ants = graph->ants;
  minNb = graph->listpath->nbelem;
  tmpLP = graph->listpath->next;

  while (tmpLP)
    {
      sum = minNb + ants - 1;
      tmpNb = tmpLP->nbelem;
      printf("nb elem = %d\n", tmpNb);
      if (sum > tmpNb) 
	{
	  tmpLP->maxants = (sum - tmpNb) / 2;
	  ants -= tmpLP->maxants; 
	}
      printf("maxants = %d\n", tmpLP->maxants);
      tmpLP = tmpLP->next;
    }
  graph->listpath->maxants = ants;
  printf("maxants = %d\n", graph->listpath->maxants);
}
