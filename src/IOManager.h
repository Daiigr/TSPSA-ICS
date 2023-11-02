#ifndef IOMANAGER
#define IOMANAGER

typedef struct coordinate{
  int x; /* The x coordinate of the position. */
  int y; /* The y coordinate of the position. */
} coordinate;

coordinate **readCityCoordinates(int nCities);
coordinate **GenerateRandomCityCoordinates(int nCities);
#endif
