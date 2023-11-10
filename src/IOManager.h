#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "coordinate.h"

coordinate *readCityCoordinates(int nCities);
coordinate *generateRandomCityCoordinates(int nCities);
void printCityCoordinates(coordinate  *cityCoordinates, int nCities);
void printCityDistanceMatrix(int  **distanceMatrix, int nCities);
void printPath(coordinate *path, int nCities);
void printEpochGeneration(int epoch, float temperature, float energy, int nCities);
#endif