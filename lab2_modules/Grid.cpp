#include <iostream>
#include <ctime>
#include <cstdlib>
#include <ostream>
#include <windows.h>
#include <fstream>
#include <math.h>
#include <string>
#include "Grid.h"

using namespace std;

void PrintArray(int arr[], int size){
    printf("|");
    for(int i=0; i<size; i++){
        printf("%i|", arr[i]);
    }
    printf("\n");
}

void SetGridBorders(char grid[25][25]){
    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){

            if(i==0 || i==24)
                grid[i][j]='-';
            else{
                if(j==0 || j==24)
                    grid[i][j]='|';
            }
        }
    }
}

void UpdateGrid(int arrayR[], int arrayC[], int arraySize, char grid[25][25]){
    GridInit(grid);
    SetGridBorders(grid);

    for(int j=0; j< arraySize; j++){
        grid[arrayR[j]][arrayC[j]] = 'o';
    }
}

void GridInit(char grid[25][25]){
    for(int i=0; i<25; i++)
        for(int j=0; j<25; j++)
            grid[i][j]=' ';
    SetGridBorders(grid);
}

void PrintGrid(char grid[25][25], int iters){
    system("CLS");

    //make sure grid edges remain intact
     for(int i=0; i<25; i++){
        for(int j=0; j<25; j++){
            if(i==0 || i==24)
                grid[i][j]='-';//-
            else{
                if(j==0 || j==24)
                    grid[i][j]='|';
            }
        }
    }

    for(int i=0; i<25; i++){
        for(int j=0; j<25; j++)
            cout<<grid[i][j];
        cout<<endl;
    }
    cout<<"Iteration:"<<iters<<endl;
}
