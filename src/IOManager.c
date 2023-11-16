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
#include <sys/ioctl.h> // for ioctl() function
#include <unistd.h> // for STDOUT_FILENO constant

// our custom libraries
#include "IOManager.h"
#include "coordinate.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"

//color codes for printing
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
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

void printTerminationConditions(float temperature, int epoch, int Energy, int nCities){
  printf("Termination conditions Reached.\n");
  printf("{E_a: %s", GREEN);
  printf("%d", Energy);
  printf("%s", RESET);
  printf(", T_a: %s", GREEN);
  printf("%f", temperature);
  printf("%s}", RESET);
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
    fscanf(fptr, "%d,%d", &cityCoordinates[i].x, &cityCoordinates[i].y);
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
  fptr = fopen("path.csv", "a");
  // write the epoch, energy and temperature to the file 
  for(int i = 0; i < nCities; i++){
    fprintf(fptr, "%d,%d\n", path[i].x, path[i].y);
  }
  fprintf(fptr, "\n");
  fclose(fptr);
}

void saveFinalPathToFile(coordinate *path, int nCities){
FILE *fptr;
  fptr = fopen("finalPath.csv", "w");
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

clock_t calculateTimeRemaining(clock_t startTime, int epoch, int nEpochs) {
  clock_t currentTime = clock();
  double timeElapsed = (double)(currentTime - startTime) / CLOCKS_PER_SEC;
  double timePerEpoch = timeElapsed / epoch;
  double totalRemainingTime = timePerEpoch * (nEpochs - epoch);
  return (clock_t)(totalRemainingTime * CLOCKS_PER_SEC);
}

float calculateEpochsPerSecond(clock_t startTime, int epoch){
  clock_t currentTime = clock();
  clock_t timeElapsed = currentTime - startTime;
  float epochsPerSecond = (float)epoch / ((float)timeElapsed / CLOCKS_PER_SEC);
  return epochsPerSecond;
}

/**
 * Updates the loading bar in the terminal.
 * 
 * @param epoch The current epoch.
 * @param nEpochs The total number of epochs.
 * @param timeRemaining The estimated time remaining in seconds.
 * @param epochsPerSecond The number of epochs per second.
 */
void updateLoadingBar(int epoch, int nEpochs, clock_t timeRemaining, float epochsPerSecond){
  // get the terminal width
  struct winsize w;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
  int width = w.ws_col;
  // calculate the percentage of epochs completed
  float percentage = (float)epoch / (float)nEpochs;
  int barWidth = width - 100;
  int progress = (int)(percentage * barWidth);

  // print the loading bar
  printf("\r[");
  for(int i = 0; i < progress; i++){
    printf("%s", GREEN);
    printf("#");
    printf("%s", RESET);
  }
  for(int i = progress; i < barWidth; i++){
    printf("_");
  }
  
  printf("] %s", GREEN);
  printf(" %d%% | ep[%i/%i]", (int)(percentage * 100), epoch, nEpochs);
  printf("%s", RESET);  
  printf(" | %s", YELLOW);
  // Calculate the proper format for ETA (assuming timeRemaining is now stored in seconds)
  int hours = timeRemaining / (CLOCKS_PER_SEC * 3600);
  int minutes = (timeRemaining / CLOCKS_PER_SEC / 60) % 60;
  int seconds = (timeRemaining / CLOCKS_PER_SEC) % 60;
  // Printing ETA with formatting for zero padding
  printf("ETA: %02d:%02d:%02d", hours, minutes, seconds);
  printf("%s", RESET);  
  printf(" | %s", RED);
  printf("eps: %f/s", epochsPerSecond);
  printf("%s", RESET);
  fflush(stdout);
  // print a new line when the loading bar is complete
  if(epoch == nEpochs){
    printf("\n");
  }
}


