#ifndef TSP_H
#define TSP_H
#include "coordinate.h"

float **computeDistanceMatrix(coordinate *cityCoordinates, int nCities);
int **computeSquaredDistanceMatrix(coordinate *cityCoordinates, int nCities);


#endif
