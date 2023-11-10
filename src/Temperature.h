/**
 * @file Temperature.h
 * @author Kealan Barry( k.barry@student.rug.nl)
  * @brief this file contains the functions for the temperature of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */
#ifndef TEMPERATURE_H 
#define TEMPERATURE_H
float initializeTemperature();
float updateTemperature(float currentTemperature);
int shouldTerminate(float  temperature, int nIterations);
#endif
