// saveToFile.h
#ifndef SAVETOFILE_H 
#define SAVETOFILE_H 
#include "coordinate.h"
void saveEpochToFile(int epoch, float energy, float temperature);
void savePathToFile(coordinate *path, int nCities);
void clearCSVFile();
#endif // SAVE_TO_FILE_H 