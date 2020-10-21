//
//  menu.h
//  assignment1_suttler
//
//  Created by Devin Suttler on 9/18/20.
//  
//

#ifndef menu_h
#define menu_h
#include <iostream>

using namespace std;

//declaring a struct of type Item
struct Item {
    string name;
    string type;
    double price;
    int calories;
    int sales;
    
};

//declaring a struct of type Item
struct Combo {
    Item items[3];
    double price;
    int calories;
    int sales;
    int size;
};

//function prototypes
void InitItems(Item *items, int size);
void InitCombos(Combo *combos, int size);
void LoadItems(Item *items, int size);
void ActionMenu(Item *items, int itemSize, Combo *combos, int comboSize);
void InsertCombo(Combo *combos, int comboSize, Item *itemsMenu, int itemSize);

#endif /* menu_h */
