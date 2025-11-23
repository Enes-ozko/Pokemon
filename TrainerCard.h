#ifndef TRAINERCARD_H
#define TRAINERCARD_H
#include "Card.h"
#include <string>
using namespace std;

class TrainerCard : public Card {       
    private:
        string trainerEffect;

    public:
        TrainerCard(const string& name, const string& effect); 
        string gettrainerEffect() const;
        void displayInfo() const override;

};

#endif
