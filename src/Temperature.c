/**
 * @file Temperature.c
 * @author Kealan Barry( k.barry@student.rug.nl)
 * @brief this file contains the functions for the temperature of the simulated annealing algorithm 
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


float updateTemperature(float currentTemperature, float coolingRate){
  currentTemperature = currentTemperature*0.995;
  return currentTemperature;
}

float initializeTemperature(){
  float temperature = 1000.00; // Start with an initial temperature of 1
  return temperature;
}

int shouldTerminate(float temperature, int nIterations){
  if (temperature < 0.01) { // If reached desired Temperature
    return 1;
  }
  return 0;
}