/**
 * @file Main.c
 * @authors Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl) Kealan Barry( k.barry@student.rug.nl)
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

//macros

#define DEBUG 0
// read from command line arguments if debug is enabled and if random or read mode is enabled
int main(int argc, char *argv[]){
  if (argc > 1) {
    if (argv[1][0] == '1') {
        printf("Debug mode enabled.\n");
    }
    if (argv[2][0] == '1') {
        printf("Random mode enabled.\n");
    }
  }
// get number of cities from user
int nCities = 0;
scanf("%d", &nCities);
coordinate *cityCoordinates = generateRandomCityCoordinates(nCities); // Generate random city coordinates.
coordinate *currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.
coordinate *generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.
time_t t;
srand((unsigned) time(&t));
float generatedPathEnergy = 0;
float temperature = initializeTemperature(); 
int currentEpochIteration = 0;

#if DEBUG == 1
  printCityCoordinates(cityCoordinates, nCities); // Print city coordinates.  
  printPath(currentPath, nCities); // Print path.
#endif

printf("Beginning simulated annealing...\n");
#if DEBUG == 1
  printEpochGeneration(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities) , nCities);
#endif
//termination condition: temperature is close to zero
while(!shouldTerminate(temperature, currentEpochIteration)){
  // generate new path permutation
  generatedPath = generatePathPermuation(currentPath, nCities);
  // check if new path is better
  if (isEnergyImprovement(currentPath, generatedPath, nCities)) {
    // if new path is better, accept it
    #if DEBUG == 1
      printf("New path is better, accepting it.\n");
      printf("Improvement: %f\n", differenceInEnergy(currentPath, generatedPath, nCities));
    #endif
    currentPath = generatedPath;
  } else {
    // if new path is worse, accept it with a probability of $P = e^\frac{e_0 - Etemp}{kT} $
    // can be rewritten as $P = e^\frac{-\Delta E}{kT} $
    // which can be used to implment a boltzmann distribution

    if (generateProbability(differenceInEnergy(currentPath, generatedPath, nCities), temperature)) {
      #if DEBUG == 1
        printf("Accepted.\n");
      #endif
      currentPath = generatedPath;
    } else {
      #if DEBUG == 1
        printf("Rejected.\n");
      #endif
    }
 
  }

  // print Epoch information 
  #if DEBUG == 1
    printEpochGeneration(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities) , nCities);
  #endif
  // save epoch information to file
  saveEpochToFile(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities));
  // save path to file
  savePathToFile(currentPath, nCities);
  // apply cooling schedule
  temperature = updateTemperature(temperature);
  currentEpochIteration++;
}
printTerminationConditions(temperature, currentEpochIteration, calculatePathEnergy(currentPath, nCities), nCities);
return 0;
}
