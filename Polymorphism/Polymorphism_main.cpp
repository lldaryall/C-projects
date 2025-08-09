#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Polymorphism.h"
using namespace std;

int main() {
    srand(time(0));
    
    int numPlayers;
    cout << "Enter the number of players: ";
    cin >> numPlayers;
    
    int gooseIndex = rand() % numPlayers;
    cout << "Randomly generated number: " << gooseIndex << endl;
    
    PlayerList players(numPlayers);
    
    for (int i = 0; i < numPlayers; i++) {
        if (i == gooseIndex) {
            players.Insert(new Goose());
        } else {
            players.Insert(new Duck());
        }
    }
    for (int i = 0; i < numPlayers; i++) {
        Player* currentPlayer = players.GetElement(i);
        
        currentPlayer->print();
        cout << endl;
        
        if (i == gooseIndex) {
            return 0;
        }
    }
    return 0;
}