#include <stdio.h>
#include <stdlib.h>

#include "percolate.h"

/*
 * Program to test for percolation of a cluster.
 */

int main(int argc, char* argv[])
{
  /* Define the main "map" array */
  int map[L+2][L+2];
  int loop, nchange;
	int i, j;
  float rho;
  int seed;

  /* Set the most important variable, the density rho */
  rho  = 0.69;

  /* Set the randum number seed and initialise the generator */
  seed = 1564;
	if(argc == 2)
	{
		seed = atoi(argv[1]);
	}
  rinit(seed);

  printf("percolate: parameters are rho=%f, L=%d, seed=%d\n", rho, L, seed);

  /* Initialise map with density rho  */
  percfill(map, rho);
	/* Initialise map ready for updating */
  percinit(map);

  /* Keep updating until nothing changes */
  loop = 1;

	do
  {
      nchange = percupdate(map);
      printf("percolate: number of changes on loop %d is %d\n", loop, nchange);
      loop++;
  }
  while (nchange > 0);

	for (i=1; i<L+1; i++)
	{
		for (j=1; j<L+1; j++)
		{
			printf("%3i ", map[i][j]);
		}
		printf("\n");
	}

  /* Test to see if percolation occurred */
	int percolation_number = perctest(map);
  if (percolation_number == 0)
  {
    printf("percolate: cluster DOES NOT percolate\n");
  }
  else
  {
    printf("percolate: cluster DOES percolate\n");
  }

  /* Write map to the file "map.pgm", displaying L*L (ie all) the clusters */
  percwrite("map.pgm", map, 2);

}
