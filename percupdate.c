#include <stdio.h>
#include <stdlib.h>
#include "percolate.h"

/*
 *  Function to update all entries of the map once.
 *
 *  Should return the actual number of changes, zero if nothing changes.
 */

int percupdate(int map[L+2][L+2])
{
	int i,j, change = 0;
	for (i=1; i<L+1; i++)
	{
		for (j=1; j<L+1; j++)
		{
			int old = map[i][j];
			if(old != 0)
			{
				if(map[i][j] < map[i][j+1])	{ map[i][j] = map[i][j+1];}
				if(map[i][j] < map[i][j-1])	{ map[i][j] = map[i][j-1];}
				if(map[i][j] < map[i+1][j])	{ map[i][j] = map[i+1][j];}
				if(map[i][j] < map[i-1][j])	{ map[i][j] = map[i-1][j];}
				if(old != map[i][j])				{	change++;}
			}
		}
	}
  return change;
}

