
#include <iostream>
using namespace std;

class Player {
public:
    Player();
    virtual void print() const;
    virtual ~Player();
};
class Duck : public Player {
public:
    Duck();
    void print() const override;
    ~Duck();
};
class Goose : public Player {
public:
    Goose();
    void print() const override;
    ~Goose();
};
class PlayerList {
public:
    PlayerList(int arraySize);
    bool Insert(Player* item);
    Player* GetElement(unsigned int n);
    void Print();
    int GetSize();
    
    PlayerList(const PlayerList& s);
    PlayerList& operator=(const PlayerList& s);
    ~PlayerList();
private:
    Player** array;
    int current;
    int size;
};