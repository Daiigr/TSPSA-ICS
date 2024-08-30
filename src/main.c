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
#include <string.h>

// our custom libraries
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"

//macros
//color codes for printing
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define RESET "\033[0m"

#define DEBUG 0

int countEpochs(float temperature, float coolingRate){
  int count = 0;
  while(temperature > 0.01){
    temperature = updateTemperature(temperature, coolingRate);
    count++;
  }
  return count;
}

int main(int argc, char *argv[]){
  // start timer for loading bar
  clock_t startTime = clock();
  int nCities = 0;
  coordinate *cityCoordinates;
  coordinate *currentPath;
  coordinate *generatedPath;
  float temperature = 1000.00; // 1000 by default
  float coolingRate = 0.995; // cooling rate of 0.995 by default
  // flags
  int saveAllPaths = 0;
  int noUI = 0;
  // read from command line arguments

for (int i = 1; i < argc; i++) {
    // checks -n flag and initializes a specific number of cities (MANDATORY for n > 0)
    if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "-N") == 0) {
      nCities = atoi(argv[i+1]);
      printf("Flagged Change: Number of cities: %d\n", nCities);
    }
  // checks -T flag and initializes a specific temperature
    if(strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0){
      if (argv[i+1] != NULL) {
        printf("Flagged Change: Temperature: %f\n", atof(argv[i+1]));
        temperature = atof(argv[i+1]);
      }
    }
    // checks -C flag and initializes a specific cooling rate
    if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-C") == 0){
      if (argv[i+1] != NULL) {
        printf("Flagged Change: Cooling Rate: %f\n", atof(argv[i+1]));
        coolingRate = atof(argv[i+1]);
      }
    }

    // check for the file flag in the argument list
    if(strcmp(argv[i], "-file") == 0 || strcmp(argv[i], "-FILE") == 0){
      FILE *fp; // file pointer
      fp = fopen(argv[i+1], "r"); // open file for reading
      if (fp == NULL) {
        printf("Error opening file.\n");
        exit(1);
      }
      printf("Reading coordinates from file.\n");
      cityCoordinates = readCityCoordinatesFromFile(nCities, fp);
    }

    if(strcmp(argv[i], "-random") == 0 || strcmp(argv[i], "-RANDOM") == 0){
      printf("Generating random coordinates.\n");
      cityCoordinates = generateRandomCityCoordinates(nCities);
      saveCoordinatesToFile(cityCoordinates, nCities);
    }
    //  check for the save all flag which indicates if they want to save all the paths to a file
    if(strcmp(argv[i], "-saveallpaths") == 0 || strcmp(argv[i], "-SAVEALLPATHS") == 0){
     printf("Flagged Change: Saving all paths to file.\n");
     saveAllPaths = 1;
    }
    // check for the nui flag which indicates if they want a UI interface to see progress
    // this is done because the UI slows down the program  and causes errors in python notebooks
    if(strcmp(argv[i], "-nui") == 0 || strcmp(argv[i], "-NUI") == 0){
      printf("Flagged Change: No UI.\n");
	    noUI = 1;
    }
  }


// get number of cities from user
currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.
generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.

// seed random number generator
time_t t;
srand((unsigned) time(&t));

int currentEpochIteration = 0;
int numberOfEp = countEpochs(temperature, coolingRate);
// calculate estimated ram usage

printf("Beginning simulated annealing...\n");
//termination condition: temperature is close to zero
while(!shouldTerminate(temperature, currentEpochIteration)){
  // generate new path permutation
  generatedPath = generatePathPermuation(currentPath, nCities);
  // check if new path is better
  //loading bar
  if (isEnergyImprovement(currentPath, generatedPath, nCities)) {
    // if new path is better, accept it
    currentPath = generatedPath;
  } else {
    // if new path is worse, accept it with a probability of $P = e^\frac{e_0 - Etemp}{kT} $
    // can be rewritten as $P = e^\frac{-\Delta E}{kT} $
    // which can be used to implment a boltzmann distribution

    if (generateProbability(differenceInEnergy(currentPath, generatedPath, nCities), temperature)) {
      currentPath = generatedPath;
    }
  }
  // print Epoch information
  saveEpochToFile(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities));
  // save path to file
  if(saveAllPaths){
  savePathToFile(currentPath, nCities);
  }

  // apply cooling schedule
  temperature = updateTemperature(temperature, coolingRate);
  currentEpochIteration++;

  // % 100 is to prevent it from updating on every itteration otherwise writing to stdout slows down the program too much
  // recommendation: when running in a script make sure -nui is enabled to maximize EPS
  // TODO: scale the modulo depending on estimated epochs
  if(!noUI && currentEpochIteration % 1000 == 0){
  // update loading bar
  clock_t timeRemaining = calculateTimeRemaining(startTime, currentEpochIteration, countEpochs(temperature, coolingRate));
  float epochsPerSecond = calculateEpochsPerSecond(startTime, currentEpochIteration);
  updateLoadingBar(currentEpochIteration, numberOfEp, timeRemaining, epochsPerSecond);
  }
}
//print total time taken
printf("/nTotal time taken: %s %f %s seconds\n",GREEN, (double)(clock() - startTime) / CLOCKS_PER_SEC, RESET);
saveFinalPathToFile(currentPath, nCities);
printTerminationConditions(temperature, currentEpochIteration, calculatePathEnergy(currentPath, nCities), nCities);
return 0;
}
