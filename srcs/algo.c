#include "lem_in.h"

static int RecIsReachable(char *dest,
                          t_vert *startP)
{
  t_edge *edgeP;

  if (startP->visited)
    return 0;

  if (ft_strequ(startP->name, dest))
    return 1;

  startP->visited = 1;

  for (edgeP = startP->edges;
       edgeP != NULL;
       edgeP = edgeP->next) {
    if (RecIsReachable(dest, edgeP->connectsTo))
      return 1;
  }

  return 0;
}
