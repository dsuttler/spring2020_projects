#ifndef BALL_H_INCLUDED
#define BALL_H_INCLUDED

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
void    SpawnBalls(int arrayR[], int arrayC[], int numBalls);
void    SetRandDirections(int directions[], int numBalls);
int     GetCoordUpdateR(int dir);
int     GetCoordUpdateC(int dir);
bool    ValidCoord(int row, int column);
int     GetOppositeDir(int dir);
void    Bounce(int &r, int &c, int &dir);
void    MoveBalls(int arrR[], int arrC[], int directions[], int numBalls);
int     GetRandDirection();

#endif // BALL_H_INCLUDED
