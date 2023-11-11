// saveToFile.c 
#include <stdio.h>
#include "saveToFile.h"
#include "coordinate.h"
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

void clearCSVFile(){
  FILE *fptr;
  fptr = fopen("data.csv", "w"); // write mode 
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
    fprintf(fptr, "{x:%d, y:%d},", path[i].x, path[i].y);
  }
  fprintf(fptr, "\n");
  fclose(fptr);
}