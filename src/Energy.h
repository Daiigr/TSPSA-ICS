#ifndef ENERGY_H 
#define ENERGY_H
#include "coordinate.h"
float calculatePathEnergy(coordinate *path, int nCities);
float differenceInEnergy(coordinate *currentPath, coordinate *newPath, int nCities);
int isEnergyImprovement(coordinate *currentPath, coordinate *newPath, int nCities);
#endif
