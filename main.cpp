#include <iostream>
#include "Hostess.h"

using namespace std;

int GetRandomBetween(int floor, int ceiling){
    int temp = floor + (rand() % static_cast<int>(ceiling - floor + 1));
    return temp;
}

/*
    Whenever a party arrives, this function is called
    to determine the size of the PartySize()*/
int PartySize(){
    return GetRandomBetween(1,8);
}

/*
    Returns the number of customers that have arrived at the current time
    The arrival depends on the time and utilizes a random number generator
*/
int GetNumArrivals(int hour){

    bool arrived = false;
    if((hour < 5 && GetRandomBetween(0,100) < 12) ||
       (hour >=5 && hour < 7 && GetRandomBetween(0,100) < 40) ||
       (hour >=7 && GetRandomBetween(0,100) < 20))
        arrived = true;

    if(arrived == true)
        return PartySize();
    else
        return 0;
}

void SetRandGeneratorSeed(){
    srand (time(NULL));
}

void ClearScreen(){
    system("CLS");
}
/*
    This is the main function of the program, everything is called from here
    and the function operates for 14 hours starting from 7:00 AM
*/
void Operate(Hostess &h){
    int hour     = 0;
    int minute   = 0;
    int hours    = 14;
    int arrivals = -1;
    int table    = -1;

    for(int i = 0; i<hours*60; i++){
        ClearScreen();
        h.AdvanceTime(hour, minute);
        arrivals = GetNumArrivals(hour);
        h.CalculateTimeLeft(h.tables, h.GetNumTables(), h.totalServed, h.currentCustomers); ///added h. because it is now a member function
        h.PlaceArrivalInQueue(arrivals);
        h.Print(hour, minute, arrivals);

        table = h.CheckAvail();
        h.Seat(table, GetRandomBetween(40,70));
    }
}

int main(){
    SetRandGeneratorSeed();
    Hostess h;
  //  h.Init(); ///removed because Hostess h called the default constructor
    Operate(h);
    return 0;
}


