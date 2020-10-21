#ifndef GRID_H_INCLUDED
#define GRID_H_INCLUDED

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>

using namespace std;

//function prototypes
void    PrintArray(int arr[], int size);
void    SetGridBorders(char grid[25][25]);
void    UpdateGrid(int arrayR[], int arrayC[], int arraySize, char grid[25][25]);
void    GridInit(char grid[25][25]);
void    PrintGrid(char grid[25][25], int iters);

#endif // GRID_H_INCLUDED
