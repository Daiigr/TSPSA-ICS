/**
 * @file Energy.c
 * @author Kealan Barry( k.barry@student.rug.nl)
  * @brief this file contains the functions for the energy of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */

// defult libraries 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// our custom libraries
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"

/**
 * Calculates the total energy of a given path through a set of cities. 
 * @param path An array of coordinates representing the path through the cities.
 * @param nCities The number of cities in the path.
 * @return The total energy required to traverse the path.
 */
float calculatePathEnergy(coordinate *path, int nCities){
  float totalDistance = 0;
  // calculate total distance
for (int i = 0; i < nCities - 1; i++)  {
    totalDistance += sqrt(((path[i].x-path[i+1].x)*(path[i].x-path[i+1].x)) + ((path[i].y-path[i+1].y)*(path[i].y-path[i+1].y)));
}   
  return totalDistance;
}
/**
 * Calculates the difference in energy between two paths.
 * @param currentPath The current path.
 * @param newPath The new path.
 * @param nCities The number of cities in the paths.
 * @return The difference in energy between the two paths.
 */
float differenceInEnergy(coordinate *currentPath, coordinate *newPath, int nCities) {
  // calculate difference in energy
  float diff = calculatePathEnergy(newPath, nCities) - calculatePathEnergy(currentPath, nCities);
  return diff;
}

/**
 * Determines if a new path is an improvement over the current path based on energy difference.
 * @param currentPath Pointer to an array of coordinates representing the current path.
 * @param newPath Pointer to an array of coordinates representing the new path.
 * @param nCities The number of cities in the path.
 * @return 1 if the new path is an improvement, 0 otherwise.
 */
int isEnergyImprovement(coordinate *currentPath, coordinate *newPath, int nCities){
  // check if new path is better
  if (differenceInEnergy(currentPath, newPath, nCities)<0) {
    return 1;
  }
  return 0;
}
