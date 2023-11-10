


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "coordinate.h"


//TODO: implement
float calculatePathEnergy(coordinate *path, int nCities){
  float totalDistance = 0;
  for (int i = 0; i<nCities; i++) {
    totalDistance += sqrt(((path[i].x-path[i+1].x)*(path[i].x-path[i+1].x)) + ((path[i].y-path[i+1].y)*(path[i].y-path[i+1].y)));
  }  
  return totalDistance;
}
//TODO: implement
int isEnergyImprovement(coordinate *currentPath, coordinate *newPath, int nCities){
  if (calculatePathEnergy(newPath, nCities) < calculatePathEnergy(currentPath, nCities)) {
    return 1;
  }
  return 0;
}