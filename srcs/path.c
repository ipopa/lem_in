#include "lem_in.h"

int create_path(t_map *graph, t_vert *vert)
{
  int nbelem;
  t_listpath *newpath;
  t_path *newnode;
  t_path *newnode2;
  t_listpath *tmp;

  
  newpath = (t_listpath *)malloc(sizeof(t_listpath));
  newnode = (t_path *)malloc(sizeof(t_path));

  newpath->path = NULL;
  newpath->next = NULL;
  newpath->maxants = 0;

  newnode->vertices = NULL;
  newnode->next = NULL;
  
  nbelem = 1;
  while (!vert->start)
    {
      if (newnode->vertices == NULL)
	newnode->vertices = vert;
      else {
	newnode2 = (t_path *)malloc(sizeof(t_path));	
	newnode2->vertices = vert;
	newnode2->next = newnode;
	newnode = newnode2;
      }
      
      if (!vert->end)
	{
	  vert->occ = true;
	}
      nbelem++;
      vert = vert->orig;
    }
  if (newnode->vertices == NULL)
    newnode->vertices = vert;
  else {
    newnode2 = (t_path *)malloc(sizeof(t_path));	
    newnode2->vertices = vert;
    newnode2->next = newnode;
    newnode = newnode2;
  }

  newpath->path = newnode;
  print_path(newpath->path);
  
  /*newpath->nbelem = nbelem;

  tmp = graph->listpath;
  if (graph->listpath == NULL)
    graph->listpath = newpath;
  else
    {
      while (tmp->next != NULL)
	{
	  tmp = tmp->next;
	}
      tmp->next = newpath;
      }*/
  return nbelem;
}
