/**
 * @file IOManager.c
 * @author Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl)
  * @brief this file contains the functions for the input and output of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */

// defult libraries 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// our custom libraries
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"

//color codes for printing
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define RESET "\033[0m"

// input functions



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
#include <time.h>

coordinate *generateRandomCityCoordinates(int nCities){
  coordinate *cityCoordinates = (coordinate*)malloc(nCities * sizeof(coordinate));
  srand(time(NULL)); // seed the random number generator with the current time
  for(int i = 0; i < nCities; i++){
    cityCoordinates[i].x = rand() % 100;
    cityCoordinates[i].y = rand() % 100;
  }
  return cityCoordinates;
}

// output functions

/**
 * Prints a title in red.
 * 
 * @param title The title to print.
 */
void printTitle(char *title){
  printf("[%s", RED);
  printf("%s", title);
  printf("%s]", RESET);
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


/**
 * Prints the given path of cities with their coordinates.
 * 
 * @param path An array of coordinates representing the path.
 * @param nCities The number of cities in the path.
 */
void printPath(coordinate *path, int nCities){
  if (nCities > 100) {
    printf("Path is too long to print.\n");
    return;
  }
  printTitle("Path Coordinates");
  printf ("[");
  for(int i = 0; i < nCities; i++){
    printf("{x: %s",GREEN);
    printf("%d", path[i].x);
    printf("%s", RESET);
    printf(", y: %s", GREEN);
    printf("%d", path[i].y);
    printf("%s} -> \n", RESET);
  }
  printf("]\n");
}

/**
 * Prints the epoch, temperature, energy and number of cities.
 * 
 * @param epoch The current epoch.
 * @param temperature The current temperature.
 * @param energy The current energy.
 * @param nCities The number of cities.
 */
void printEpochGeneration(int epoch, float temperature, float energy, int nCities){
  printf("Epoch: %s", RED);
  printf("%d -> ", epoch);
  printf("%s", RESET);
  printf("{E_a: %s", GREEN);
  printf("%f", energy);
  printf("%s", RESET);
  printf(", T_a: %s", GREEN);
  printf("%f", temperature);
  printf("%s}", RESET);
  printf("\n");
}

void printTerminationConditions(float temperature, int epoch, int Energy, int nCities){
  printf("Termination conditions Reached.\n");
  printTitle("Termination Statistics");
  printf("Final Energy: %s", RED);
  printf("%d", Energy);
  printf("%s", RESET);
  printf("\n");
  printf("Final Temperature: %s", RED);
  printf("%f", temperature);
  printf("%s", RESET);
  printf("\n");
  printf("Final Epoch: %s", RED);
  printf("%d", epoch);
  printf("%s", RESET);
  printf("\n");
}
//file input functions

/**
 * Reads city coordinates from a file.
 * 
 * @param nCities The number of cities to read coordinates for.
 * @return A pointer to an array of coordinates.
 */
coordinate *readCityCoordinatesFromFile(int nCities, FILE *fptr){
  coordinate *cityCoordinates = (coordinate*)malloc(nCities * sizeof(coordinate));
  for(int i = 0; i < nCities; i++){
    fscanf(fptr, "%d %d", &cityCoordinates[i].x, &cityCoordinates[i].y);
  }
  fclose(fptr);
  return cityCoordinates;
}

// file output functions
/**
 * Appends the epoch, energy and temperature to a CSV file.
 * 
 * @param epoch The current epoch.
 * @param energy The current energy.
 * @param temperature The current temperature.
 */
void saveEpochToFile(int epoch, float energy, float temperature) {
  FILE *fptr;

  fptr = fopen("data.csv", "a"); // append mode 
  // write the epoch, energy and temperature to the file 
  fprintf(fptr, "%d, %f, %f\n", epoch, energy, temperature);

  fclose(fptr);
}

/**
 * appends the given path to a file named "path.csv" in append mode.
 * Each line in the file contains the x and y coordinates of a city in the path.
 * 
 * @param path An array of coordinates representing the path to be saved.
 * @param nCities The number of cities in the path.
 */
void savePathToFile(coordinate *path, int nCities){
  FILE *fptr;
  fptr = fopen("path.csv", "a"); // append mode 
  // write the epoch, energy and temperature to the file 
  for(int i = 0; i < nCities; i++){
    fprintf(fptr, "%d,%d\n", path[i].x, path[i].y);
  }
  fprintf(fptr, "\n");
  fclose(fptr);
}

void saveFinalPathToFile(coordinate *path, int nCities){
  FILE *fptr;
  fptr = fopen("final.csv", "w"); // write mode 
  // write the epoch, energy and temperature to the file 
  for(int i = 0; i < nCities; i++){
    fprintf(fptr, "%d,%d\n", path[i].x, path[i].y);
  }
  fprintf(fptr, "\n");
  fclose(fptr);
}

void saveCoordinatesToFile(coordinate *cityCoordinates, int nCities){
  printf("Saving coordinates to file.\n");
  FILE *fptr;
  fptr = fopen("coordinates.csv", "w"); // write mode 
  // write the epoch, energy and temperature to the file 
  for(int i = 0; i < nCities; i++){
    fprintf(fptr, "%d,%d\n", cityCoordinates[i].x, cityCoordinates[i].y);
  }
  fprintf(fptr, "\n");
  fclose(fptr);
}