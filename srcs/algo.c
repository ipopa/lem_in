#include "lem_in.h"

int isRe(t_vert *endP, t_vert *startP)
{
	t_edge *edgeP;

	if (startP->visited)
		return 0;

	if (startP->name, dest))
		return 1;

	startP->visited = true;

	edgeP = startP->edges;

	while (edgeP != NULL)
	{
		if (isRe(dest, edgeP->connectTo)) {
			return 1;
		}
		edgeP = edgeP->next;
	}
	return 0;
}
