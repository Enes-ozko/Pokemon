#include <string>
#include "Card.h"
using namespace std;


Card::Card(const string&  name) : cardName(name) {}

string Card::getCardName() const {
    return cardName;
}

