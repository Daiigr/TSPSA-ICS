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

#define DEBUG 1
#define NMAX 100


int main(int argc, char *argv[]) {
int nCities = 10; /**< The number of cities. */

coordinate *cityCoordinates = GenerateRandomCityCoordinates(nCities); // Generate random city coordinates.
printCityCoordinates(&cityCoordinates, nCities); // Print the city coordinates.
return 0;
}
