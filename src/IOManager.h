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
// input functions from Terminal

coordinate *readCityCoordinates(int nCities);
coordinate *generateRandomCityCoordinates(int nCities);

// output functions to Terminal

void printCityCoordinates(coordinate  *cityCoordinates, int nCities);
void printCityDistanceMatrix(int  **distanceMatrix, int nCities);
void printPath(coordinate *path, int nCities);
void printEpochGeneration(int epoch, float temperature, float energy, int nCities);
void printTerminationConditions(float temperature, int epoch, int Energy, int nCities);

// input functions from file

coordinate *readCityCoordinatesFromFile(int nCities, FILE *fp);

// output functions to file

void saveEpochToFile(int epoch, float energy, float temperature);
void savePathToFile(coordinate *path, int nCities);
void saveFinalPathToFile(coordinate *path, int nCities);
void saveCoordinatesToFile(coordinate *cityCoordinates, int nCities);

void updateLoadingBar(int epoch , int nEpochs);
int calculateRamUsage(int nEpoch, int nCities);
#endif
