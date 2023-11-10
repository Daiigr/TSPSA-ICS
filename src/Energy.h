/**
 * @file Energy.c
 * @author Kealan Barry( k.barry@student.rug.nl)
  * @brief this file contains the functions for the energy of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */

#ifndef ENERGY_H 
#define ENERGY_H
#include "coordinate.h"
float calculatePathEnergy(coordinate *path, int nCities);
float differenceInEnergy(coordinate *currentPath, coordinate *newPath, int nCities);
int isEnergyImprovement(coordinate *currentPath, coordinate *newPath, int nCities);
#endif
