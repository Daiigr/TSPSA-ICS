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
 * Swaps two cities on a given path randomly.
 * 
 * @param path The path to swap cities on.
 * @param nCities The number of cities in the path.
 * @return A new path with two cities swapped.
 */
coordinate *swapTwoCitiesOnPath(coordinate *path, int nCities){
  coordinate *newPath = (coordinate *) malloc( nCities * sizeof(coordinate));
  for (int i = 0; i<nCities; i++) {
    newPath[i] = path[i];
  }
  int randomIndex1 = rand() % nCities;
  int randomIndex2 = rand() % nCities;
  coordinate temp = newPath[randomIndex1];
  newPath[randomIndex1] = newPath[randomIndex2];
  newPath[randomIndex2] = temp;
  return newPath;
}

/**
 * Inverts the order of an arbitrary section of the given path array.
 * 
 * @param path The array of coordinates representing the path.
 * @param nCities The number of cities in the path.
 * @return A new array of coordinates with the section inverted.
 */
coordinate *InvertRandomSectionOnPath(coordinate *path, int nCities){
  coordinate *newPath = (coordinate *) malloc( nCities * sizeof(coordinate));
  for (int i = 0; i<nCities; i++) {
    newPath[i] = path[i];
  }
  int randomIndex1 = rand() % nCities;
  int randomIndex2 = rand() % nCities;
  if (randomIndex1 > randomIndex2) {
    int temp = randomIndex1;
    randomIndex1 = randomIndex2;
    randomIndex2 = temp;
  }
  for (int i = randomIndex1; i < randomIndex2; i++) {
    coordinate temp = newPath[i];
    newPath[i] = newPath[randomIndex2];
    newPath[randomIndex2] = temp;
    randomIndex2--;
  }
  return newPath;
}

/**
 * Performs a circular shift on a given path by moving everything up (or down) the array by one place, 
 * and moving the last (or first) to the first (or last) position.
 * 
 * @param path The path to perform the circular shift on.
 * @param nCities The number of cities in the path.
 * @return A new path with the circular shift performed.
 */
coordinate *doCircularShiftOnPath(coordinate *path, int nCities){
  coordinate *shiftedPath = (coordinate *) malloc( nCities * sizeof(coordinate));
  for (int i = 0; i<nCities; i++) {
    shiftedPath[i] = path[i];
  }

  coordinate temp = shiftedPath[0];
  for (int i = 0; i < nCities - 1; i++) {
    shiftedPath[i] = shiftedPath[i+1];
  }
  shiftedPath[nCities - 1] = temp;
  return shiftedPath;

}

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
  // randomly pick one of the 3 different types of path permutations

  int randomIndex = rand() % 3;
  if (randomIndex == 0) {
    newPath = swapTwoCitiesOnPath(path, nCities);
  }
  else if (randomIndex == 1) {
    newPath = InvertRandomSectionOnPath(path, nCities);
  }
  else {
    newPath = doCircularShiftOnPath(path, nCities);
  }
  return newPath;
}