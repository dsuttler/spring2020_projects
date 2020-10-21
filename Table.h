#ifndef TABLE_H
#define TABLE_H

#include <stdlib.h>
#include <time.h>

struct Table{
    Table();

    void Free();
    void SetCustomers(int num){numSeated = num;}
    void SetVacant(bool param){vacant = param;}
    void SetCapacity(int c){capacity = c;}
    void SetEatingTime(int t){timeToSpend = t;}

    int CalcTimeLeft();
    bool IsVacant(){return vacant;}

    bool vacant;
    int capacity;
    int numSeated;
    int timeToSpend;

};

#endif // TABLE_H
