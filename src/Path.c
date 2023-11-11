/**
 * @file Path.c
 * @author Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl) 
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
 * Generates a random path of coordinates using the Fisher-Yates shuffle algorithm.
 * 
 * @param cityCoordinates An array of coordinates representing the cities.
 * @param nCities The number of cities.
 * 
 * @return A pointer to an array of coordinates representing the random path.
 */
coordinate  *generateRandomPath(coordinate *cityCoordinates, int nCities){
    coordinate *path = (coordinate *) malloc( nCities * sizeof(coordinate));
  // Fisher-Yates shuffle
    while (nCities > 0){
        int randomIndex = rand() % nCities;
        path[nCities - 1] = cityCoordinates[randomIndex];
        cityCoordinates[randomIndex] = cityCoordinates[nCities - 1];
        nCities--;
    }
 return path;
}


coordinate *generatePathPermuation(coordinate *path, int nCities){
  coordinate *newPath = (coordinate *) malloc( nCities * sizeof(coordinate));
 // note that there must be only one of each city in the path at any time
 // so they need to be shuffled in a way that ensures this

// the way we do this is by swapping two cities in th path at random 

// we do this by generating two random indices and swapping the cities at those indices

// we do this nCities times to ensure that each city is swapped at least once
  for (int i = 0; i<nCities; i++) {
    newPath[i] = path[i];
  }

  for (int i = 0; i<nCities; i++) {
    int randomIndex1 = rand() % nCities;
    int randomIndex2 = rand() % nCities;
    coordinate temp = newPath[randomIndex1];
    newPath[randomIndex1] = newPath[randomIndex2];
    newPath[randomIndex2] = temp;
  }

  return newPath;
}