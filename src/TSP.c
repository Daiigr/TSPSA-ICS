/* file:   TSP.c */
/* 
author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.nl) 
 Kelean Barry (k.barry@student.rug.nl
*/
/* date:   Thu Nov 02 2023 */
//standard libs
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//personal libs
#include "coordinate.h"

float **computeDistanceMatrix(coordinate *cityCoordinates, int nCities){
  int xDistance = 0;
  int yDistance = 0;
  float **distanceMatrix = (float**)malloc(nCities * sizeof(float*));
  for(int i = 0; i < nCities; i++){
    distanceMatrix[i] = (float*)malloc(nCities * sizeof(float));
    for(int j = 0; j < nCities; j++){
      xDistance = cityCoordinates[i].x - cityCoordinates[j].x;
      yDistance = cityCoordinates[i].y - cityCoordinates[j].y;
      distanceMatrix[i][j] = sqrt((xDistance * xDistance) + (yDistance * yDistance));
    }
  }
  return distanceMatrix;
}
