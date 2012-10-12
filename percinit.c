#include <stdio.h>
#include <stdlib.h>

#include "percolate.h"

/*
 *  Function to initialise the map prior to looking for clusters.
 *
 *  All interior L*L points that are non-zero should be replaced with a
 *  unique positive integer.
 */

void percinit(int percmap[L+2][L+2])
{
	int i, j;
	int unique_integer = 1;
	for (i=1; i<L+1; i++)
	{
		for (j=1; j<L+1; j++)
		{
			percmap[i][j] *= unique_integer;
			unique_integer++;
			printf("%3i ", percmap[i][j]);
		}
		printf("\n");
	}
}

