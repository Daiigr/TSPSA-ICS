#include <stdio.h>
#include <stdlib.h>


float updateTemperature(float currentTemperature){
  currentTemperature = currentTemperature*0.99;
  return currentTemperature;
}

float initializeTemperature(){
  float temperature = 1.00; // Start with an initial temperature of 1
  return temperature;
}

int shouldTerminate(float temperature, int nIterations){
  if (temperature == 0) { // If reached desired Temperature
    return 1;
  }
  if (nIterations == 1000) { // If reached desired number of iterations
    return 1;
  }
  return 0;
}