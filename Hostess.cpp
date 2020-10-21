#include "Hostess.h"
#include <cstdio> //printf wouldn't run without this

using namespace std;
/*
    takes the number of customers that have just arrived
    and places them in the queue
*/
void Hostess::PlaceArrivalInQueue(int arrivals){
    if(queue_size<15 && arrivals!=0){
        queue[queue_size] = arrivals;
        queue_size++;
    }
}

/*
    This function is called when a party from the head of the queue is being seated.
    This means that it must be removed from the head of the queue, and all other parties
    must move one position to the left
*/
void Hostess::ShiftLeft(){

    /* FILL IN THIS FUNCTION */
    ///The for loop will copy all the items in the queue to the value on it's right
    ///it will then replace the last number of customers in the queue (which will be a
    ///duplicate of the value to the left at this point) to 0.
    for(int i = 0; i < queue_size - 1; i++) {
        queue[i] = queue[i + 1];
    }
    queue_size--;
    queue[queue_size] = 0;
}

/*
    This function performs the seating process of seating customers from the head of the queue
    at table "int table" which will be occupied by that party for "int time" minutes
    If "int table" is -1, it indicates that no table is available and the function must then return -1
    If there is a table available, the queue and the table attributes must be updated accordingly and the
    function must return 0. Look for any other functions from the table struct or hostess struct that can
    be utilized here
*/

int Hostess::Seat(int table, int time){
    /*
        FILL THIS FUNCTION
        COMMENT OUT THE RETURN STATEMENTS
        THEY HAVE BEEN INCLUDED SO THE CODE WILL COMPILE
        BUT DO NOT SERVE A SPECIFIC PURPOSE THE WAY THEY ARE WRITTEN
    */
    if(table == -1) { ///if the table value passed in is -1 then return -1
        return table;
    }
    ///If the hostess is able to seat a group
    else {
        tables[table].vacant = false; ///change the vacant attribute to false to show that the table is being used
        tables[table].numSeated = queue[0]; ///setting the number in the table array to the number in the group
        tables[table].SetEatingTime(time); ///giving the newly sat customers an amount of time they will take to eat
        ShiftLeft(); ///removing the group from the waiting queue
        currentCustomers += tables[table].numSeated; ///adding the currently being seated customers to the currentCustomers variable

        return 0;

    }



}

/*
    Checks if any tables are free, and whether all customers can fit in it
    If such a table exists, return its ID(index), otherwise return -1
*/
int Hostess::CheckAvail(){
    if(queue_size == 0)
        return -1;
    int numPeople = queue[0];
    for(int i=0; i<30; i++){
        if(tables[i].IsVacant() == true && tables[i].capacity >= numPeople)
            return i;
    }
    return -1;
}

/*
    INITIALIZES THE HOSTESS OBJECT ACCORDINGLY
*/
Hostess::Hostess() { ///changed the name from Init() to Hostess() to be the default constructor
    numTables           = 30;
    queue_size          = 0;
    totalServed         = 0;
    currentCustomers    = 0;

    for(int i=0; i<30; i++){
        if(i<20)
            tables[i].SetCapacity(4);
        else
            tables[i].SetCapacity(8);
        tables[i].SetVacant(true);
    }

    for(int i=0; i<15; i++)
        queue[i] = 0;
}

void Hostess::Print(int hour, int minute, int arrivals){

    printf("Table Queue\n");
    for(int i=0; i<15; i++){
        printf("%i|", queue[i]);
    }
    printf("\n");
    printf("\n============================================================\n");
    printf("Table INFO\n");
    for(int i=0; i<30; i++){
        if(i<20)
            printf("H|");
        else
            printf("F|");
    }
    printf("\n============================================================\n");
    for(int i=0; i<30; i++){
        printf("%i|", tables[i].numSeated);

    }

    printf("\n\n");
    printf("  Time:%i:%i\n", hour+7, minute);
    printf("# Current      customers:%i\n", currentCustomers);
    printf("# Total customers served:%i\n", totalServed);
}

/*
    Advances the current time by one minute
*/
void Hostess::AdvanceTime(int &hour, int &minute){ ///moved here to be a member function of Hostess
    //FILL THIS FUNCTION
    minute++;

    if (minute == 60) {
        minute = 0;
        hour++;
    }
}

/*
    Wrapper function that calls the method CalcTimeLeft for each table,
    which decrements the variable that corresponds to the time for which
    the customers will remain at the table. If that time goes to 0, the function
    automatically frees the table and updates the variables keeping tracking of the total number
    of customers that have departed and the number that is currently at the restaurant
*/
///moved here to become a member function of Hostess
void Hostess::CalculateTimeLeft(Table tables[], int numTables, int &totalCustomers, int &currentCustomers){
    for(int i=0; i<numTables; i++){
        int customersLeaving = tables[i].CalcTimeLeft();
        totalCustomers   += customersLeaving;
        currentCustomers -= customersLeaving;
    }
}

