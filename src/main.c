/* file:   main.c */
/* authors: 
Daniel Grbac Bravo (d.grbac.bravo@student.rug.n) 
Kealan Barry (k.barry@student.rug.nl)
*/
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "cityManager.h"

#define DEBUG 1
#define NMAX 100

/**
  * @brief A struct that represents the position of a city.
 */
typedef struct coordinate{
  int x; /* The x coordinate of the position. */
  int y; /* The y coordinate of the position. */
} coordinate;

int nCities = 0; /**< The number of cities. */

int main(int argc, char *argv[]) {
int **cityDistances = (int**)malloc(nCities * sizeof(int*)); /**< An array of distances between cities. */
int *currentPath = (int*)malloc(nCities * sizeof(int)); /**< An array of the current path. */
readCityCooridnates(nCities);
return 0;
}