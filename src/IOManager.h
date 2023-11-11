/**
 * @file IOManager.c
 * @author Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl)
  * @brief this file contains the functions for the input and output of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */

#ifndef IOMANAGER_H
#define IOMANAGER_H
#include "coordinate.h"

coordinate *readCityCoordinates(int nCities);
coordinate *generateRandomCityCoordinates(int nCities);

void printCityCoordinates(coordinate  *cityCoordinates, int nCities);
void printCityDistanceMatrix(int  **distanceMatrix, int nCities);
void printPath(coordinate *path, int nCities);
void printEpochGeneration(int epoch, float temperature, float energy, int nCities);
void printTerminationConditions(float temperature, int epoch, int Energy, int nCities);
void saveEpochToFile(int epoch, float energy, float temperature);
void savePathToFile(coordinate *path, int nCities);
#endif
