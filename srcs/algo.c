#include "lem_in.h"

int isRe(t_vert *startP, int nb)
{
	t_edge *edgeP;
	int tmpNb;

	
	startP->wt = nb++;

	if (startP->start) {
		startP->wt = 0;
	}
	printf("%s with wt = %d \n", startP->name, startP->wt);
	if (startP->visited)
		return 0;

	startP->visited = true;

	if (startP->end)
	{
		printf("end : %s\n", startP->name);
		return 1;
	}

	edgeP = startP->edges;

	//if (edgeP != NULL)
	//tmpNb = nb + 1;
	while (edgeP != NULL)
	{
		edgeP->connectTo->wt = tmpNb; 
		if ((!edgeP->connectTo->visited || edgeP->connectTo->wt > tmpNb) && isRe(edgeP->connectTo, tmpNb)) {
			return 1;
		}
		edgeP = edgeP->next;
	}
	return 0;
}
