#include <stdio.h>
#include <stdlib.h>

#include "percolate.h"

/*
 *  Function to test for percolation.
 *
 *  Should return 1 if a cluster percolates, 0 otherwise.
 */

int perctest(int percmap[L+2][L+2])
{
	int i,j;
	for(i=1;i<L+1;i++)
	{
		for(j=1;j<L+1;j++)
		{
			if(percmap[1][i] == percmap[L][j] && percmap[1][i] != 0)
			{
				return 1;
			}
		}
	}
  return 0;
}
