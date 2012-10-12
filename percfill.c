#include <stdio.h>
#include <stdlib.h>

#include "percolate.h"

/*
 *  Function to fill the percolation map with density rho.
 *
 *  All boundary points should be set to zero.
 *
 *  The interior L*L entries should each be set to zero with
 *  probability rho, otherwise should be set to one.
 */

void percfill(int percmap[L+2][L+2], float rho)
{
  int i, j;
	float density = 0;

	for (i=0; i<L+2;i++) /* Initialises 'halo' around the actual data to 0*/
	{
		percmap[i][0] = 0;
		percmap[i][L+1] = 0;
		percmap[0][i] = 0;
		percmap[L+1][i] = 0;
	}

  for (i=1; i<L+1; i++)
	{
  	for (j=1; j<L+1; j++)
		{
			if(random_uniform() < rho) /* randomly chooses point to have value 1 or 0, depending on density*/
			{
	  		percmap[i][j] = 1;
				density += 1;
			}
			else
			{
				percmap[i][j] = 0;
			}
		}
  }

	/* I would add in an extra loop to randomly remove/add points until actual density is attained */
	printf("\tExpected Density: %f\n\tActual Density: %f\n", rho, density/(L*L));
}
  
