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

#define DEBUG 1

int main(int argc, char *argv[]) {
int nCities =0;
scanf("%d", &nCities);

coordinate *cityCoordinates = generateRandomCityCoordinates(nCities); // Generate random city coordinates.
coordinate *currentPath = generateRandomPath(cityCoordinates, nCities); // Generate random path.
coordinate *generatedPath = (coordinate *) malloc( nCities * sizeof(coordinate)); // Allocate memory for generated path.
float *temperature = initializeTemperature(); 
int currentEpochIteration = 0;
//termination condition: temperature is close to zero
while(!shouldTerminate(temperature)){
  // replace current path with new path if new path is better
  generatedPath = generatePathPermuation(temperature, currentPath, nCities);
  if (isEnergyImprovement(currentPath, generatedPath, nCities)){
    currentPath = generatedPath;
  }
  // apply cooling schedule
  temperature = updateTemperature(temperature, nCities, currentEpochIteration);
  currentEpochIteration++;
}

return 0;
}
