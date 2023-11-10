/**
 * @file Path.c
 * @author Daniel Grbac Bravo (d.grbac.bravo@student.rug.nl) 
 * @brief this file contains the functions for the energy of the simulated annealing algorithm
 * @version 1.0
 * @date 2023-11-10
 */
#ifndef PATH_H 
#define PATH_H
#include "coordinate.h"

// Function declarations

coordinate *generateRandomPath(coordinate *cityCoordinates, int nCities);
coordinate *generatePathPermuation(coordinate *path, int nCities);


#endif
