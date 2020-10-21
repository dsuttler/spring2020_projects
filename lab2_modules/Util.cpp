#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>
#include "Util.h"

using namespace std;

/*
    Random Number generator to return a number between ceiling and floor,
    including floor and ceiling
*/
int RandIntBetween(int ceiling, int floor){
    return floor + rand() % (( ceiling + 1 ) - floor);
}

/*
sets the seed, without it we would get the same random numbers
every time we run the program
*/
void SetRandomGeneratorSeed(){
    srand(time(NULL));
}
