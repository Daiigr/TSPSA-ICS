/* file:   Path.c */
/* author: Daniel Grbac Bravo (d.grbac.bravok@student.rug.n) */
/* date:   Fri Nov 03 2023 */
/**
 * Description: Provide a brief description of the purpose of this program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "coordinate.h"
#include "IOManager.h"
#include "Path.h"

 // TODO: implement
coordinate *generateRandomPath(coordinate *cityCoordinates, int nCities){
 coordinate *path = (coordinate *) malloc( nCities * sizeof(coordinate));
 return path;
}

// TODO: implement
coordinate *generatePathPermuation(float *temperature, coordinate *path, int nCities){
  coordinate *newPath = (coordinate *) malloc( nCities * sizeof(coordinate));
  return newPath;
}