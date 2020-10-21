//Editor: Devin Suttler
//CS250
//Professor:
//09 September 2020

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>

using namespace std;

//function prototype declarations
void RandInt(int numberOfCards, int& indexOfCard);
void PrintCard(int cardDrawn);
void PrintArray(int arr[], int size);
void PrintProbabilities(int numOfCards, int numCardsDrawn, int xFell[], int size);
void InitToZero(int *arr, int sizeOfArray);
void InitToIndex(int *arr, int sizeOfArray);
void RemoveCardFromDeck(int *xFell, int *deck, int cardDrawn,
int& amountOfCards, int indexOfCard);


//main body
int main() {
    //seed for random number generator
    srand (time(NULL));
    int numCards = 13; ///number of different card types
    int cards[13]; ///declaring the cards array
    int timesFell[13]; ///how many times each card was drawn

    //initialize arrays
    InitToZero(timesFell, 13); ///initializing the timesFell array to 0
    InitToIndex(cards, 13); ///initializing the cards array to each individual index

    int action = -1;
    int card  =  -1;
    int index = -1;
    int cardsDrawn = 0;
    while(action!=0){
        //draws cards until no more cards remain
        cout<<"**********************"<<endl;
        
        //Displaying the cards array
        cout<<"This is the cards array right now"<<endl;
        PrintArray(cards, 13);

        //Displaying the timesFell array
        cout<<"This is the timesFell array right now"<<endl;
        PrintArray(timesFell, 13);
        cout<<"**********************"<<endl;


        //print probabilities
        PrintProbabilities(13, cardsDrawn, timesFell, 13);

        cout<<"**********************"<<endl<<endl<<endl;

        //displaying the user's options
        cout<<"Draw Card - 1"<<endl;
        cout<<"Exit      - 0"<<endl;
        cin>>action;

        if(action == 1){
            //randomly pick index and increment counter
            RandInt(numCards, index);
            card = cards[index];
            timesFell[card]++;

            system("CLS"); //this simply erases the screen, if it doesn't make sense, comment out and run to see the difference
            
            PrintCard(card); ///displaying the card that was drawn
            RemoveCardFromDeck(timesFell, cards, card, numCards, index); ///removing the drawn card from the deck

             cardsDrawn++; ///increase the number of cards drawn for probability
        }

        //making sure the user types the correct character
        if(action!=1 && action!=0)
            cout<<"Only valid keys are 0 and 1, Please re-enter"<<endl;

    }

    return 0;
} ///end main body

//**********************************************************************************************************************************************************
//function declarations

//removes a card from the deck if it has been drawn 4x
//using pointers to directly modify the arrays and a reference variable to directly modify
    //the number of cards in the deck
void RemoveCardFromDeck(int *xFell, int *deck, int cardDrawn,
                        int& amountOfCards, int indexOfCard) {
    if(xFell[cardDrawn]==4){
        amountOfCards--; ///if you've pulled all the cards of 1 type decrease the different types by 1
        
        //sorting the cards in the deck once one has been drawn
        int temp = deck[indexOfCard];
        deck[indexOfCard] = deck[amountOfCards];
        deck[amountOfCards] = temp;
    }
}

//creates a random integer between 0 and 12
void RandInt(int numberOfCards, int& indexOfCard) {
    //adding minimum and maximum variables per the instructions
    int minimumVal = 0;
    int maximumVal = numberOfCards;
    
    indexOfCard = minimumVal + rand() % maximumVal;
}

//Displays the card that was drawn NOT the index
void PrintCard(int cardDrawn) {
    cout<<"CARD:";
    if(cardDrawn==10)
       cout<<setw(4)<<"J";
    else if(cardDrawn == 11)
        cout<<setw(4)<<"Q";
    else if(cardDrawn == 12)
        cout<<setw(4)<<"K";
    else
        cout<<setw(4)<<cardDrawn+1;
    cout<<endl;
}

//displays the array passed to it with specific formatting
void PrintArray(int arr[], int size) {
    for(int i=0; i<13; i++) ///displaying the cards array
        cout<<setw(2)<<arr[i]<<"|";
    cout<<endl<<endl;
}

//displays the list of possible cards to draw and those drawn
//then displays the possibility to draw each type of card
void PrintProbabilities(int numOfCards, int numCardsDrawn, int xFell[], int size) {
    cout<<"**********************"<<endl;
    cout<<"Card"<<setw(10)<<"Prob."<<endl;
    for(int j=0; j<numOfCards; j++){
        if(j==10)
            cout<<setw(4)<<"J";
        else if(j == 11)
            cout<<setw(4)<<"Q";
        else if(j == 12)
            cout<<setw(4)<<"K";
        else
         cout<<setw(4)<<j+1;
         cout<<setw(10)<<setprecision(2)<<(4-xFell[j])/(double)(52 - numCardsDrawn)
                <<"  =  "<<4-xFell[j]<<"/"<<(52 - numCardsDrawn)<<endl; ///probability calculation
    }
}

//initializes the passed array to all 0s
void InitToZero(int *arr, int sizeOfArray) {
    for(int i=0; i<sizeOfArray; i++){
        arr[i] = 0; ///each element in the timesFell array is initially initialized to 0
    }
}

//initializes the passed array to the value of its index
void InitToIndex(int *arr, int sizeOfArray) {
    for(int i=0; i<sizeOfArray; i++){
        arr[i] = i;
    }
}
