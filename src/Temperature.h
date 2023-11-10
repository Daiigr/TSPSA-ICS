#ifndef TEMPERATURE_H 
#define TEMPERATURE_H
float *initializeTemperature();
float *updateTemperature(float *currentTemperature, int nCities, int nIterations);
int shouldTerminate(float *temperature);
#endif
