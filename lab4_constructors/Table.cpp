#include "Table.h"

Table::Table(){
    vacant = true;
    numSeated = 0;
}

void Table::Free(){
    vacant = true;
    numSeated = 0;
    timeToSpend = 0;
}

/*
    Advance Time left for customer at the table
    If the customers vacate the table, return their number
    so that we can increment the number of total customers served
    if customers have not left the table yet, return zero
*/
int Table::CalcTimeLeft(){

    if(vacant == false && timeToSpend > 0){
        timeToSpend--;
        return 0;
    }
    else if(vacant == false && timeToSpend == 0){
        int numPeople = numSeated;
        Free();
        return numPeople;
    }
    return 0;
}
