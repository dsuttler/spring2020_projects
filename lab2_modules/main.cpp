/*
Code Edited by Devin Suttler
CS250
Dr Ayman El Mesalami
*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>
#include "Ball.h"
#include "Grid.h"
#include "Util.h"


using namespace std;

int     PromptForBallNumber();
int     PromptForIterationNumber();
void    Menu(int &numBalls, int &iters, bool &exit);
void    Launch(char grid[25][25], int numBalls, int iters);
void    PreperaSim(int arrR[], int arrC[], int directions[],
                   char grid[25][25], int numBalls);


int main(){
    //simulation parameters
    int iters = 20;
    bool exit = false;
    bool randPos = true;
    int numBalls = 2;
    char grid[25][25];
    SetRandomGeneratorSeed();
    while(exit == false){
        Menu(numBalls, iters, exit);
        if(exit == false)
            Launch(grid, numBalls, iters);
    }

    return 0;
}

/*
    sets the values for the parameters whichs are passed by reference
    those parameters are then used by the other functions
    numBalls: number of balls in the grid
    iters:       number of iterations in in the main loop inside the     Launch function
    exit: boolean variable that allows the user to terminate the program, (set to true when user wants to terminate)
*/
void Menu(int &numBalls, int &iters, bool &exit){
   //FILL THIS FUNCTION
   int action;

   //creating the menu display
    do {
        cout << "Launch                           (1)" << endl;
        cout << "Set Ball Number                  (2)" << endl;
        cout << "Number of Iterations             (3)" << endl;
        cout << "Exit                             (0)" << endl;
        cout << "------------------------------" << endl;
        cout << "Number of balls:      :" << numBalls << endl;
        cout << "Number of iterations  :" << iters << endl;
        cout << "Enter Action:";
        cin >> action;
        cout << endl;

        if(action == 1) {
            break; ///exiting this function to allow main to launch the program
                    ///and re-enter the function once completed
        }

        if(action == 2) {
            numBalls = PromptForBallNumber(); ///updates the number of balls
        }

        else if(action == 3) {
            iters = PromptForIterationNumber(); ///updates the number of iterations
        }

       else if(action == 0) {
        exit = true;
       }
       system("CLS"); ///helps keep the screen less cluttered
   }
   while(exit == false);


}

/*
    This function initializes all the necessary arrays and parameters that are required by the simulation
*/

void PreperaSim(int arrR[], int arrC[], int directions[], char grid[25][25], int numBalls){

    SpawnBalls(arrR, arrC, numBalls);
    SetRandDirections(directions, numBalls);
    GridInit(grid);
    SetGridBorders(grid);
}

/*
    This function launches the simulation, it contains all the necessary structures
    and invokes the prepareSim to initialize/reset them. Any call to launch, yields
    a new simulation scenario, with new ball positions and starting directions
*/

void Launch(char grid[25][25], int numBalls, int iters){
    int arrR[numBalls];
    int arrC[numBalls];
    int directions[numBalls];

    for(int i=0; i<numBalls; i++){
        arrR[i] = 0;
        arrC[i] = 0;
    }

    PreperaSim(arrR, arrC, directions, grid, numBalls);

    for(int i=0; i<iters; i++){
        MoveBalls(arrR, arrC, directions, numBalls);
        UpdateGrid(arrR, arrC, numBalls, grid);
        PrintGrid(grid, i);
        PrintArray(arrR, numBalls);
        PrintArray(arrC, numBalls);
    }
}

//used for setting simulation parameter of how many balls will spawn
int PromptForBallNumber(){
    int balls = -1;
    do{
        cout<<"Enter number balls:"<<endl;
        cin>>balls;
        if(balls<1 || balls>15){
            cout<<"Invalid number. Please enter value between 1 and 15"<<endl;
        }
    }
    while(balls<1 || balls>15);
    return balls;
}

//used for setting simulation parameter of how many iterations the simulation will run for
int PromptForIterationNumber(){
    int iters = -1;
    do{
        cout<<"Enter number of iterations:"<<endl;
        cin>>iters;
        if(iters<1 || iters>100){
            cout<<"Invalid number. Please enter value between 1 and 100"<<endl;
        }
    }while(iters<1 || iters>100);
    return iters;
}
