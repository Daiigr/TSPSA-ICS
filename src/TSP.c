/* file:   TSP.c */
/* 
author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.nl) 
 Kelean Barry (k.barry@student.rug.nl
*/
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "coordinate.h"
#include "math.h"

float **computeDistanceMatrix(coordinate *cityCoordinates, int nCities){
  int xDistance = 0;
  int yDistance = 0;
  int **distanceMatrix = (int**)malloc(nCities * sizeof(int*));
  for(int i = 0; i < nCities; i++){
    distanceMatrix[i] = (int*)malloc(nCities * sizeof(int));
    for(int j = 0; j < nCities; j++){
      xDistance = cityCoordinates[i].x - cityCoordinates[j].x;
      yDistance = cityCoordinates[i].y - cityCoordinates[j].y;
      distanceMatrix[i][j] = sqrt((xDistance * xDistance) + (yDistance * yDistance));
    }
  }
  return distanceMatrix;
}