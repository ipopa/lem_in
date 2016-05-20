#include "lem_in.h"

t_vert		*init_vert(void)
{
  t_vert *vert;
  
  vert = (t_vert *)malloc(sizeof(t_vert));
  vert->start = false;
  vert->end = false;
  vert->occ = false;
  vert->wt = (int *)malloc(sizeof(int));
  *(vert->wt) = INT_MAX;
  vert->edges = NULL;
  vert->orig = NULL;
  vert->next = NULL;
  vert->x = 0;
  vert->y = 0;
  vert->visited = false;
  return vert;
}

t_edge *init_edge(t_vert *new)
{
  t_edge *newedge;

  if ((newedge = (t_edge *)malloc(sizeof(t_edge))) == NULL)
    return NULL;
  newedge->connectTo = new;
  newedge->next = NULL;
  return newedge;
}

t_map *init_map(void)
{
  t_map *graph;

  graph = (t_map *)malloc(sizeof(t_map));
  graph->vertices = NULL;
  graph->ants = 0;
  graph->listpath = NULL;
  graph->maxpath = 0;
  graph->nbpath = 0;
  graph->end = NULL;
  graph->start = NULL;
  graph->mapcount = 0;
  return graph;
}
