/* file:   IOManager.c */
/* author: Daniel Grbac Bravo (d.grbac.bravo@student.rug.n) */
/* date:   Thu Nov 02 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "coordinate.h"
//color codes for printing
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

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
coordinate *generateRandomCityCoordinates(int nCities){
  coordinate *cityCoordinates = (coordinate*)malloc(nCities * sizeof(coordinate));
  for(int i = 0; i < nCities; i++){
    //r = ((double) rand() ) /  ((double) RAND_MAX) ; doesn't work for generating random floats 🤷🏻‍♂️
    cityCoordinates[i].x = rand() % 100;
    cityCoordinates[i].y = rand() % 100;
  }
  return cityCoordinates;
}

//--------------------------------------------------------------------------------------------
// printing functions
//--------------------------------------------------------------------------------------------

/**
 * Prints a title in red.
 * 
 * @param title The title to print.
 */
void printTitle(char *title){
  printf("%s", RED);
  printf("----------------------------------------\n");
  printf("%s", title);
  printf("\n----------------------------------------\n");
  printf("%s", RESET);
  printf("\n");
}

/**
 * Prints an integer with green color formatting.
 *
 * @param number The integer to be printed.
 */
void printFormatedInt(int number){
  printf("%s", GREEN);
  printf("%d", number);
  printf("%s", RESET);
}

/**
 * Prints the coordinates of all cities in the given array.
 * 
 * @param cityCoordinates An array of coordinate structs representing the cities.
 * @param nCities The number of cities in the array.
 */
void printCityCoordinates(coordinate *cityCoordinates, int nCities){

  printTitle("Node (City) Coordinates:");

  for(int i = 0; i < nCities; i++){
    printf("{x: %s", GREEN);
    printf("%d", cityCoordinates[i].x);
    printf("%s", RESET);
    printf(", y: %s", GREEN);
    printf("%d", cityCoordinates[i].y);
    printf("%s", RESET);
    printf("}\n");
  }
}

void printCityDistanceMatrix(int **distanceMatrix, int nCities){
  printTitle("distance matrix:");
  for(int i = 0; i < nCities; i++){
    printf("\n");
    for(int j = 0; j < nCities; j++){
      printFormatedInt(distanceMatrix[i][j]);
      printf(" ");
    }
    printf("\n");
  }
}

void printPath(int *path, int nCities){
  printTitle("Path:");
  for(int i = 0; i < nCities; i++){
    printf("%s", GREEN);
    printf("%d", path[i]);
    printf("%s", RESET);
    printf(" ");
  }
  printf("\n");
}