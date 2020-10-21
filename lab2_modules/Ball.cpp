#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>
#include "Ball.h"
#include "Util.h"

using namespace std;

///Function created by Devin Suttler
//randomly selects a starting position on the grid for each ball
void SpawnBalls(int arrayR[], int arrayC[], int numBalls){
   //FILL THIS FUNCTION
   //for each ball give a random row and column
    for(int i=0; i<numBalls; i++){
        arrayR[i] = RandIntBetween(24, 0);
        arrayC[i] = RandIntBetween(24, 0);
    }
}

/*
    This function populates the directions array with a random
    integer, corresponding to any of the 8 directions

    0. right
    1. left
    2. up
    3. down
    4. upperRight
    5. upperLeft
    6. lowerRight
    7. lowerLeft
*/
//randomly initializes the directions array
void SetRandDirections(int directions[], int numBalls){
    //This is equivalent to the loop below and  a better standard
    //for_each(directions, direction+numBalls, GetRandDirection);

    for(int i=0; i<numBalls; i++){
        directions[i] = GetRandDirection();
    }
}

/*
    returns 0 +1 or -1 based on direction
    the cases are for the updating of the current row
    returns  0 if no update is necessary
    returns  1 if the current row needs to be incremented
    returns -1 if the current row needs to be decremented

    newRow = currentRow + GetCoordUpdate(currentDirection)
*/
int GetCoordUpdateR(int dir){
    //FILL THIS FUNCTION
    /*using the code from GetCoordUpdateC however changing
      the directions for the conditional statements due to referencing
      rows instead of columns */
    if(dir == 2 || dir == 4 || dir == 5)
        return -1;
    else if(dir == 3 || dir == 6 || dir == 7)
        return 1;
    else if(dir == 1 || dir == 0)
        return 0;
}
///Function created by Devin Suttler
//similar to GetCoordUpdateR but for columns
int GetCoordUpdateC(int dir){
    if(dir == 1 || dir == 7 || dir == 5)
        return -1;
    else if(dir == 0 || dir == 6 || dir == 4)
        return 1;
    else if(dir == 2 || dir == 3)
        return 0;
}

/*
    returns whether the coordinates given as paremeters
    is a valid position for a ball to be
    note that the borders of the grid, also have coordinates
*/
bool ValidCoord(int row, int column){
    if(row<1 || column<1 || row>23 || column>23)
        return false;
    else
        return true;
}

//given a direction, it returns the opposite one
//for up it returns down, left returns right, etc.
int GetOppositeDir(int dir){
    if(dir == 2)
        return 3;
    else if(dir == 3)
        return 2;
    else if(dir == 0)
        return 1;
    else if(dir == 1)
        return 0;
    else if(dir == 5)
        return 6;
    else if(dir == 6)
        return 5;
    else if(dir == 4)
        return 7;
    else if(dir == 7)
        return 4;
}

/*
    This function updates the direction, row, and column values
    when bouncing against either of the four walls

    Hint: Once you determine the new direction that will result
          by bouncing, you can call the GetCoordUpdateR and GetCoordUpdateC
          functions, instead of manually finding the new values of r and c

    Hint: for the case of bouncing against any of the four corners
          there is already a function you can use to give you the new direction
*/

///Function created by Devin Suttler
void Bounce(int &r, int &c, int &dir){

    //FILL THIS FUNCTION
    /*Since bounce is only called in the program when the balls
      hit a wall/go out of bounds, this function will simply change the direction
      the ball was traveling to the opposite way and update the
      coordinates accordingly */
    dir = GetOppositeDir(dir);
    GetCoordUpdateR(dir);
    GetCoordUpdateC(dir);

}

/*
    This function moves the balls based on their current coordinates and direction
    It first computes the new coordinates. If the coordinates are not valid, it means
    they have reached a wall and thus they must bounce
*/
void MoveBalls(int arrR[], int arrC[], int directions[], int numBalls){
    //updates the coordinates
     //if any coordinate is out of bounds, then the ball must bounce
    //against the wall, and we must update accordingly
    for(int i=0; i<numBalls; i++){
        int newR = arrR[i]+GetCoordUpdateR(directions[i]);
        int newC = arrC[i]+GetCoordUpdateC(directions[i]);

        if(ValidCoord(newR, newC) == false){
            Bounce(arrR[i], arrC[i], directions[i]);
        }
        else{
            arrR[i] += GetCoordUpdateR(directions[i]);
            arrC[i] += GetCoordUpdateC(directions[i]);
        }
    }
}

int GetRandDirection(){
   return RandIntBetween(7,0);
}
