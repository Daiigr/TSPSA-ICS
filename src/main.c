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
#include "TSP.h"
#include "Path.h"

#define DEBUG 1

int main(int argc, char *argv[]) {
int nCities =0;
scanf("%d", &nCities);

//coordinate *cityCoordinates = readCityCoordinates(nCities); // Generate random city coordinates.
coordinate *cityCoordinates = generateRandomCityCoordinates(nCities); // Generate random city coordinates.

printCityCoordinates(cityCoordinates, nCities); // Print the city coordinates.

int **DistanceMatrix = computeDistanceMatrix(cityCoordinates, nCities); // Compute the distance matrix.
printCityDistanceMatrix(DistanceMatrix, nCities); // Print the distance matrix.
int *randomPath = generateRandomPath(DistanceMatrix, nCities); // Generate a random path.
printPath(randomPath, nCities); // Print the random path.
return 0;
}
