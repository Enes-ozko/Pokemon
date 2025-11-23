#ifndef POKEMONCARD_H
#define POKEMONCARD_H

#include "Card.h"
#include "EnergyCard.h" 
#include <tuple>
#include <vector>
#include <string>

using namespace std;

class PokemonCard : public Card{
    private:
        string pokemonType;
        string familyName;
        int evolutionLevel;
        int maxHP;
        int hp;
        vector<tuple<int,int,string, int>> attacks; 
        vector<EnergyCard*> attachedEnergies; 
    
    public:
        PokemonCard(const string& , const string& , const string& , int , int, int , string,int,int,string,int );
        ~PokemonCard() override;
    
        void attachEnergy(EnergyCard* energy);
        void takeDamage(int damage);
        void healToMaxHP(); 

        int getAttackDamage(int attackIndex) const;
        string getAttackName(int attackIndex) const;

        void displayEnergy() const; 
        void displayInfo() const override; 

        string getFamilyName() const;
        string getpokemonType() const;
        int getmaxHP() const;
        int gethp() const;
};

#endif