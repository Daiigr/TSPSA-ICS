#include <stdio.h>
#include <stdlib.h>


//TODO: implement
float updateTemperature(float currentTemperature){

  currentTemperature = currentTemperature*0.99;

  return currentTemperature;
}

//TODO: implement
float initializeTemperature(){
  float temperature = 1.00; // Start with an initial temperature of 1
  return temperature;
}
//TODO: implement
int shouldTerminate(float temperature, int nIterations){
  if (temperature == 0) { // If reached desired Temperature
    return 0;
  }
}