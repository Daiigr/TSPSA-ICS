/* file:   TSP.c */
/* 
author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.nl) 
 Kelean Barry (k.barry@student.rug.nl
*/
/* date:   Thu Nov 02 2023 */
//standard libs
#include <stdio.h>
#include <stdlib.h>
//personal libs
#include "coordinate.h"


int **computeSquaredDistanceMatrix(coordinate *cityCoordinates, int nCities){
  int xDistance = 0;
  int yDistance = 0;
  int **squaredDistanceMatrix = (int**)malloc(nCities * sizeof(int*));
  for(int i = 0; i < nCities; i++){
    squaredDistanceMatrix[i] = (int*)malloc(nCities * sizeof(int));
    for(int j = 0; j < nCities; j++){
      xDistance = cityCoordinates[i].x - cityCoordinates[j].x;
      yDistance = cityCoordinates[i].y - cityCoordinates[j].y;
      squaredDistanceMatrix[i][j] = (xDistance * xDistance) + (yDistance * yDistance );
    }
  }
  return squaredDistanceMatrix;
}
