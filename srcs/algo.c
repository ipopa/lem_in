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
      if (!tmp->visited && *(tmp->wt) < nb)
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

  printf("name = [%s] with wt = [%d]\n", startP->name, *(startP->wt));

  startP->visited = true;

  if (startP->end)
    {
      printf("end : %s\n", startP->name);
      return 1;
    }

  edgeP = startP->edges;

  while (edgeP != NULL)
    {
      if (!edgeP->connectTo->visited && (*(edgeP->connectTo->wt) > (nb + *(startP->wt))))
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
