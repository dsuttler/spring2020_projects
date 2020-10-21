//
//  menu.cpp
//  assignment1_suttler
//
//  Created by Devin Suttler on 9/18/20.
//  
//

#include "menu.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//Initializes an array of type Item to the default values given
void InitItems(Item *items, int size) {
    for(int i = 0; i < size; i++) {
        items[i].name = "unnamed";
        items[i].type = "unnamed";
        items[i].price = 0.0;
        items[i].calories = 0;
        items[i].sales = 0;
    }
}

//Initializes an array of type Combo to the default values given
void InitCombos(Combo *combos, int size) {
    for(int i = 0; i < size; i++) {
        InitItems(combos[i].items, 3);
        combos[i].price = 0;
        combos[i].calories = 0;
        combos[i].sales = 0;
        combos[i].size = 0;
    }
}

//Pulls the data from the items.txt file and loads it into the items array
void LoadItems(Item *items, int size) {
    int garbage; ///using a garbage variable to capture the leading 11
    
    ifstream inputFile;
    inputFile.open("items.txt"); ///opening the items.txt file
    inputFile >> garbage;
    
    //looping through the lines of the file and storing the data
    for(int i = 0; i < size; i++) {
        inputFile >> items[i].name;
        inputFile >> items[i].type;
        inputFile >> items[i].price;
        inputFile >> items[i].calories;
        inputFile >> items[i].sales;
    }
}

//Allows the user to see the menu and the combos created, also allows the user to create a combo
void ActionMenu(Item *items, int itemSize, Combo *combos, int comboSize) {
    int answer;
    
    do {
        //The user has 3 choices to select from
        cout << "Print Menu   (1)" << endl;
        cout << "Create Combo (2)" << endl;
        cout << "Exit         (0)" << endl;
        cout << "Insert Action: ";
        cin >> answer;
        cout << endl;
        
        //choice 1 prints the menu to the console
        if(answer == 1) {
            cout << setprecision(3) << left; ///formatting the data
    
            //Heading of the menu output
            cout << setw(5) << "ID";
            cout << setw(25) << "NAME";
            cout << setw(10) << "TYPE";
            cout << setw(10) << "CALORIES";
            cout << setw(10) << "SALES";
            cout << setw(10) << "PRICE" << endl;
            
            //looping through the items array and formatting the output of the data
            for(int i = 0; i < itemSize; i++) {
                cout << setw(5) << i;
                cout << setw(25) << items[i].name;
                cout << setw(10) << items[i].type;
                cout << setw(10) << items[i].calories;
                cout << setw(10) << items[i].sales;
                cout << setw(10) << items[i].price << endl;
            }
            cout << endl;
            
            //checking if there is a combo created
            if(combos[0].price == 0) {
                cout << "NO COMBOS AVAILABLE" << endl << endl << endl;
            }
            else {
                cout << setw(25) << right << "\nCOMBOS" << endl;
            }
            
            //outputting the created combo
            for(int b = 0; b < comboSize; b++) {
                if(combos[b].price != 0) {
                    cout << left;
                    cout << setw(5) << "ID";
                    cout << "Names" <<endl;
                    
                    cout << setw(5) << b;
                    cout << combos[b].items[0].name << " + " << combos[b].items[1].name << " + "
                    << combos[b].items[2].name << endl;
                    cout << "Total Calories: " << combos[b].calories << endl;
                    cout << "Total Price: $" << combos[b].price << endl << endl;
                }
            }
        } ///end choice #1
        
        //if the user selects 2 we call the InsertCombo function to create a new combo
        else if(answer == 2) {
            InsertCombo(combos, comboSize, items, itemSize);
        }
        
        //if the user selects 0 we exit the program
        else if (answer == 0) {
            cout << "Have a great day! :)" << endl;
        }
        
        //if the user chooses a number outside of the 3 choices
        else {
            cout << "Please choose one of the actions below" << endl;
        }
    }
    while(answer != 0); ///exits the loop if the choice is 0
} ///end choice #2

//allows the user to create a combo and updates the combo list accordingly
void InsertCombo(Combo *combos, int comboSize, Item *itemsMenu, int itemSize) {
    //creating local variables to store the user's selection
    int firstID;
    int secondID;
    int thirdID;
    
    //prompting for the 3 items to make a combo
    cout << "Enter the 1st item ID: ";
    cin >> firstID;
    cout << "Enter the 2nd item ID: ";
    cin >> secondID;
    cout << "Enter the 3rd item ID: ";
    cin >> thirdID;
    
    //inserting the selected items into the combo array's 1st empty slot
    for(int i = 0; i < comboSize; i++) {
        if(combos[i].price == 0) {
            combos[i].items[0] = itemsMenu[firstID];
            combos[i].items[1] = itemsMenu[secondID];
            combos[i].items[2] = itemsMenu[thirdID];
            
            //adding the total calories
            combos[i].calories = combos[i].items[0].calories + combos[i].items[1].calories
            + combos[i].items[2].calories;
            
            //totaling the price with the 25% discount
            combos[i].price = combos[i].items[0].price + combos[i].items[1].price
            + combos[i].items[2].price;
            combos[i].price = combos[i].price - (combos[i].price * .25);
            
            //telling the user that the combo was created
            cout << "\nCombo Created" << endl << endl;
            break; ///exiting the loop once a combo is created
        }
    }
    
    
    
}


