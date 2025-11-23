#include "TrainerCard.h"
#include <string>
#include "Card.h"
#include <iostream>
using namespace std;


TrainerCard::TrainerCard(const string& name, const string& effect)
    : Card(name), 
      trainerEffect(effect) 
{
}

string TrainerCard::gettrainerEffect() const {
    return trainerEffect;
}
void TrainerCard::displayInfo() const{
    cout << "TrainerCard - Name: " << getCardName() 
         <<", Effect: " << trainerEffect << endl;
}