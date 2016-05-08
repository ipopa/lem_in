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
  int tmpnbpath;
  int res;

  tmpNb = 0;
  ants = graph->ants;
  minNb = graph->listpath->nbelem;
  tmpLP = graph->listpath->next;

  printf("%d\n", graph->nbpath);
  tmpnbpath = graph->nbpath;
  while (tmpLP)
    {
      sum = minNb + ants - 1;
      tmpNb = tmpLP->nbelem;
      //printf("nb elem = %d\n", tmpNb);
      if (sum > tmpNb) 
	{
	  tmpLP->maxants = (sum - tmpNb) / tmpnbpath--;
	  ants -= tmpLP->maxants; 
	}
      else {
	break ;     
      }
      //  printf("maxants = %d\n", tmpLP->maxants);
      tmpLP = tmpLP->next;
    }
  graph->listpath->maxants = ants;
  //  printf("first maxants = %d\n", graph->listpath->maxants);
}

void test_nbelem(int **tab, int total, t_map *graph)
{
  int i;
  float tmp;
  int tmpFirst;

  i = 1;

  tmpFirst = tab[0][1];
  tab[0][1] = graph->ants - tab[0][0];
  while (i <= total && total > 0)
    {
      tab[0][1] += tab[i][0];
      i++;
    }
  tmp = (float)tab[0][1] / (total + 1);
  if ((int)tmp < (int)(tmp + 0.5))
    tmp++;
  tab[0][1] = (int)tmp;
  printf("tmpFirst = %d\n", tmpFirst);
  printf("tab1 = %d\n", tab[0][1]);
}
