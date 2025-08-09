#include "Polymorphism.h"

Player::Player() {
}

Player::~Player() {
}

void Player::print() const {
    cout << "Player";
}

Duck::Duck() : Player() {
}

void Duck::print() const {
    cout << "Duck";
}

Duck::~Duck() {
}

Goose::Goose() : Player() {
}

void Goose::print() const {
    cout << "Goose";
}

Goose::~Goose() {
}

PlayerList::PlayerList(int arraySize) {
    current = 0;
    size = arraySize;
    array = new Player*[size];
}

PlayerList::~PlayerList() {
    for (int i = 0; i < current; i++) {
        delete array[i];
    }
    delete[] array;
}

PlayerList::PlayerList(const PlayerList& s) {
    size = s.size;
    current = s.current;
    array = new Player*[size];
    
    for (int i = 0; i < current; i++) {
        array[i] = s.array[i];
    }
}

PlayerList& PlayerList::operator=(const PlayerList& s) {
    if (this != &s) {
        for (int i = 0; i < current; i++) {
            delete array[i];
        }
        delete[] array;
        
        size = s.size;
        current = s.current;
        array = new Player*[size];
        
        for (int i = 0; i < current; i++) {
            array[i] = s.array[i];
        }
    }
    return *this;
}

bool PlayerList::Insert(Player* item) {
    if (current < size) {
        array[current] = item;
        current++;
        return true;
    } else {
        return false;
    }
}

Player* PlayerList::GetElement(unsigned int n) {
    return array[n];
}

void PlayerList::Print() {
    if (current == 0) {
        cout << "Empty List";
        return;
    }
    for (int i = 0; i < current - 1; i++) {
        array[i]->print();
        cout << " ";
    }
    array[current - 1]->print();
}

int PlayerList::GetSize() {
    return current;
} 