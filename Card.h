#ifndef CARD_H
#define CARD_H
#include <string>
using namespace std;


class Card {
    private:
        string cardName;

    public:
        Card(const string& name);
        virtual ~Card() = default; 
        virtual void displayInfo() const = 0; 
        string getCardName() const;

};

#endif