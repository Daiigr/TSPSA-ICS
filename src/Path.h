#ifndef PATH_H 
#define PATH_H
#include "coordinate.h"
coordinate *generateRandomPath(coordinate *cityCoordinates, int nCities);
coordinate *generatePathPermuation(float *temperature, coordinate *path, int nCities);
#endif
