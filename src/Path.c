/* file:   Path.c */
/* author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.n) */
/* date:   Fri Nov 03 2023 */
/**
 * Description: Provide a brief description of the purpose of this program.
 */

#include <stdio.h>
#include <stdlib.h>
#define DEBUG 1

/**
 * Generates a random path of nCities length.
 * 
 * @param DistanceMatrix The distance matrix of the cities.
 * @param nCities The number of cities.
 * 
 * @return A pointer to the generated path.
 */
int *generateRandomPath(int **DistanceMatrix, int nCities){
  int *path = (int*)malloc(nCities * sizeof(int));
  for(int i = 0; i < nCities; i++){
    path[i] = i;
  }
  for(int i = 0; i < nCities; i++){
    int j = rand() % nCities;
    int temp = path[i];
    path[i] = path[j];
    path[j] = temp;
  }
  return path;

}