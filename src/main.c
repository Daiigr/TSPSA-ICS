/* file:   main.c */
/* authors: 
Daniel Grbac Bravo (d.grbac.bravo@student.rug.n) 
Kealan Barry (k.barry@student.rug.nl)
*/
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"
#include <math.h>
#include <time.h>
int main(int argc, char *argv[]) {
int nCities = 0;
scanf("%d", &nCities);
coordinate *cityCoordinates = generateRandomCityCoordinates(nCities); // Generate random city coordinates.

printCityCoordinates(cityCoordinates, nCities); // Print city coordinates.  

coordinate *currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.

printPath(currentPath, nCities); // Print path.
coordinate *generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.
float generatedPathEnergy = 0;
float temperature = initializeTemperature(); 
int currentEpochIteration = 0;

printf("Beginning simulated annealing...\n");
printf("Initial temperature: %f\n", temperature);
printf("Initial Epoch: %d\n", currentEpochIteration);
printEpochGeneration(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities) , nCities);

//termination condition: temperature is close to zero
while(!shouldTerminate(temperature, currentEpochIteration)){

  // generate new path permutation
  generatedPath = generatePathPermuation(currentPath, nCities);

  // check if new path is better
  if (isEnergyImprovement(currentPath, generatedPath, nCities)) {
    // if new path is better, accept it
    printf("New path is better, accepting it.\n");
    printf("Improvement: %f\n", differenceInEnergy(currentPath, generatedPath, nCities));
    currentPath = generatedPath;
  } else {
    // if new path is worse, accept it with a probability of $P = e^\frac{e_0 - Etemp}{kT} $
// random seed 
  time_t t;
   /* Intializes random number generator */
   srand((unsigned) time(&t));
    float probability = exp(differenceInEnergy(currentPath, generatedPath, nCities) / temperature);
    float random = ((float) rand()) / ((float) RAND_MAX);
    if (random < probability) {
      currentPath = generatedPath;
    }
  }

  // print Epoch information 
  printEpochGeneration(currentEpochIteration, temperature, calculatePathEnergy(currentPath, nCities) , nCities);

  // apply cooling schedule
  temperature = updateTemperature(temperature);
  currentEpochIteration++;
}
printf("Termination condition reached.\n");
printf ("Final path: \n");
printPath(currentPath, nCities);
printf("Final energy: %f\n", calculatePathEnergy(currentPath, nCities));
printf("Final temperature: %f\n", temperature);
printf("Final epoch: %d\n", currentEpochIteration);

return 0;
}
