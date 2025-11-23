#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

class Player {
    private:
        string playerName;
        vector<Card*> benchCards;
        vector<PokemonCard*> actionCards;

    public:
        Player(const string& name);
        ~Player();

        string getplayerName() const;
        const vector<Card*>& getBenchCards() const;
        const vector<PokemonCard*>& getActionCards() const;
    
        void addCardToBench(Card* card); 
        void activatePokemonCard(int );
        void attachEnergyCard(int , int );
        void displayBench();
        void displayAction();
        void attack(int , int , Player& , int );
        void useTrainerCard(int );
};

#endif