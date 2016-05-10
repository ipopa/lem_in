#include "lem_in.h"

int init_vert(t_vert *vert)
{
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
  return 1;
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

int init_map(t_map *graph)
{
  graph->vertices = NULL;
  graph->ants = 0;
  graph->listpath = NULL;
  graph->maxpath = 0;
  graph->nbpath = 0;
  graph->end = NULL;
  graph->start = NULL;
  return 1;
}
