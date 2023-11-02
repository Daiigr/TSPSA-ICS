#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "coordinate.h"

coordinate *readCityCoordinates(int nCities);
coordinate *GenerateRandomCityCoordinates(int nCities);
void printCityCoordinates(coordinate **cityCoordinates, int nCities);
#endif
