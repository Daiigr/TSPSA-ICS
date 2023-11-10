/* file:   Path.c */
/* author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.n) */
/* date:   Fri Nov 03 2023 */

#include <stdio.h>
#include <stdlib.h>
#include "coordinate.h"
#include "IOManager.h"
#include "Path.h"
#include "Energy.h"
#include "Temperature.h"
#include <math.h>


coordinate  *generateRandomPath(coordinate *cityCoordinates, int nCities){
    coordinate *path = (coordinate *) malloc( nCities * sizeof(coordinate));
  // Fisher-Yates shuffle
    while (nCities > 0){
        int randomIndex = rand() % nCities;
        path[nCities - 1] = cityCoordinates[randomIndex];
        cityCoordinates[randomIndex] = cityCoordinates[nCities - 1];
        nCities--;
    }
 return path;
}

coordinate *generatePathPermuation(float  temperature, coordinate *path, int nCities){
  coordinate *newPath = (coordinate *) malloc( nCities * sizeof(coordinate));
  //$P = e\frac{e_0 - Etemp}{kT} $ forula for probability of accepting a worse solution
  // if (Etemp < e0) then P = 1
  // if (Etemp > e0) then P = e^(-Etemp/kT)
  // if (Etemp >> e0) then P = 0
  // if (Etemp == e0) then P = 0.5  
  // if (Etemp == 0) then P = 0 

 // code 
  // 1. generate a new path
  float Etemp = calculatePathEnergy(path, nCities);
  float Enew = 0;
  int i = 0;
  while (i < nCities){
    int randomIndex = rand() % nCities;
    newPath[i] = path[randomIndex];
    i++;
  }

  // 2. calculate the energy of the new path
  Enew = calculatePathEnergy(newPath, nCities);
  
  // 3. with some probability, replace the current path with the new path

  // if (Etemp < Enew) then P = 1
  // if (Etemp > Enew) then P = e^(-Etemp/kT)
  // if (Etemp >> Enew) then P = 0
  // if (Etemp == Enew) then P = 0.5
  // if (Etemp == 0) then P = 0

  float P = 0;
  if (Etemp < Enew){
    P = 1;
  } else if (Etemp > Enew){
    P = exp(-Etemp/temperature);
  } else if (Etemp == Enew){
    P = 0.5;
  } else if (Etemp == 0){
    P = 0;
  }

  return newPath;
}