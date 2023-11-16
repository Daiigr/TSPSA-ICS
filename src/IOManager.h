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
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// input functions from Terminal

coordinate *readCityCoordinates(int nCities);
coordinate *generateRandomCityCoordinates(int nCities);

// output functions from file

coordinate *readCityCoordinatesFromFile(int nCities, FILE *fp);

// output functions to file

void saveEpochToFile(int epoch, float energy, float temperature);
void savePathToFile(coordinate *path, int nCities);
void saveFinalPathToFile(coordinate *path, int nCities);
void saveCoordinatesToFile(coordinate *cityCoordinates, int nCities);

// output functions to terminal
void printTerminationConditions(float temperature, int epoch, int Energy, int nCities);
float calculateEpochsPerSecond(clock_t startTime, int epoch);
clock_t calculateTimeRemaining(clock_t startTime, int epoch, int nEpochs);
void updateLoadingBar(int epoch, int nEpochs, clock_t timeRemaining, float epochsPerSecond);
#endif
