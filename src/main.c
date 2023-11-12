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

#define DEBUG 0
int main(int argc, char *argv[]){
  int nCities = 0;
  coordinate *cityCoordinates;
  coordinate *currentPath; 
  coordinate *generatedPath;
  float temperature = 1000.00; // 1000 by default
  float coolingRate = 0.995; // cooling rate of 0.995 by default

  // read from command line arguments 

for (int i = 1; i < argc; i++) {
  // checks if any arguments are provided for input of N
    if (strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "-N") == 0) {
      nCities = atoi(argv[i+1]);
      printf("Number of cities: %d\n", nCities);
    }
  // checks if any arguments are provided for input of Temperature
    if(strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "-T") == 0){
      if (argv[i+1] != NULL) {
        printf("Temperature: %f\n", atof(argv[i+1]));
        temperature = atof(argv[i+1]);   
      }
    }
    // cooling rate 
    if(strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "-C") == 0){
      if (argv[i+1] != NULL) {
        printf("Cooling rate: %f\n", atof(argv[i+1]));
        coolingRate = atof(argv[i+1]);   
      }
    }



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
  }

// get number of cities from user
currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.
generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.
time_t t;
srand((unsigned) time(&t));
float generatedPathEnergy = 0;
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
  temperature = updateTemperature(temperature, coolingRate);
  currentEpochIteration++;
}
saveFinalPathToFile(currentPath, nCities);
printTerminationConditions(temperature, currentEpochIteration, calculatePathEnergy(currentPath, nCities), nCities);
return 0;
}
