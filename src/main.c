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
coordinate *path = generateRandomPath(cityCoordinates, nCities); // Generate random path.
float *temperature = initializeTemperature(); 
int currentIteration = 0;
while(isTemperatureAboveZero(temperature)){
  path = generatePathPermuation(temperature, path, nCities);
  temperature = updateTemperature(temperature, nCities, currentIteration);
  currentIteration++;
}

return 0;
}
