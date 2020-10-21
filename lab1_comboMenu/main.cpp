//
//  main.cpp
//  assignment1_suttler
//
//  Created by Devin Suttler on 9/12/20.
//  
//

#include <iostream>
#include <fstream>
#include "menu.h"

using namespace std;

int main() {
    Combo combo_array[9]; ///initiating a new array of type Combo
    Item *item_array; ///creating new dynamic array to be initiated later
    int arraysize; ///will be used for the size of the item_array
    
    ifstream inputFile;
    inputFile.open("items.txt"); ///opening the items.txt file
    
    inputFile >> arraysize;
    item_array = new Item[arraysize]; ///initiating the size of the new array of type Item
    
    //calling the appropriate functions
    InitItems(item_array, arraysize);
    InitCombos(combo_array, 9);
    LoadItems(item_array, arraysize);
    ActionMenu(item_array, arraysize, combo_array, 9);
    
    return 0;
}

