/* file:   IOManager.c */
/* author: Daniel Grbac Bravo (d.grbac.bravo@student.rug.n) */
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>

typedef struct coordinate{
  int x; /* The x coordinate of the position. */
  int y; /* The y coordinate of the position. */
} coordinate;

/**
 * Reads the coordinates of nCities cities from standard input and returns an array of coordinate pointers.
 * 
 * @param nCities The number of cities to read coordinates for.
 * @return A pointer to an array of coordinate pointers.
 */
coordinate *readCityCoordinates(int nCities){
  coordinate *cityCoordinates = (coordinate*)malloc(nCities * sizeof(coordinate));
  for(int i = 0; i < nCities; i++){
    scanf("%d %d", &cityCoordinates[i].x, &cityCoordinates[i].y);
  }
  return cityCoordinates;
}

/**
 * Generates an array of random city coordinates.
 * 
 * @param nCities The number of cities to generate coordinates for.
 * @return A pointer to an array of coordinates.
 */
coordinate *GenerateRandomCityCoordinates(int nCities){
  coordinate *cityCoordinates = (coordinate*)malloc(nCities * sizeof(coordinate));
  for(int i = 0; i < nCities; i++){
    cityCoordinates[i].x = rand() % 100;
    cityCoordinates[i].y = rand() % 100;
  }
  return cityCoordinates;
}

/**
 * Prints the coordinates of all cities in the given array.
 * 
 * @param cityCoordinates An array of coordinate structs representing the cities.
 * @param nCities The number of cities in the array.
 */
void printCityCoordinates(coordinate *cityCoordinates, int nCities){
  printf("Printing city coordinates:\n");
  for(int i = 0; i < nCities; i++){
    printf(" {x:%d y:%d}\n", cityCoordinates[i].x, cityCoordinates[i].y);
  }
}