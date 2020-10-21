#ifndef HOSTESS_H
#define HOSTESS_H
#include "Table.h"
#include <iostream>

struct Hostess{
    Hostess(); ///removed init() and replaced with the default constructor

    void PlaceArrivalInQueue(int arrivals);
    void ShiftLeft();
    void Print(int hour, int minute, int arrivals);
    void AdvanceTime(int &hour, int &minute); ///moved here to be a member function
    void CalculateTimeLeft(Table tables[], int numTables, int &totalCustomers, int &currentCustomers); ///moved here to become a member function

    int GetNumTables(){return numTables;}
    int Seat(int table, int time);
    int CheckAvail();

    int totalServed;
    int currentCustomers;
    int queue_size;
    int numTables;

    Table tables[30];
    int queue[15];
};
#endif // HOSTESS_H
