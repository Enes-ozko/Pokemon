#include "PokemonCard.h"
#include "EnergyCard.h"
#include <iostream>
#include <tuple>
#include <algorithm> 

using namespace std;

PokemonCard::~PokemonCard() {
    for (EnergyCard* energy : attachedEnergies) {
        delete energy;
    }
}

PokemonCard::PokemonCard(const string& name, const string& type, const string& family, int evolution, int maxHp, int energyCost1, string nomAttack1, int damage1, int energyCost2, string nomAttack2, int damage2)
    : Card(name), 
      pokemonType(type), 
      familyName(family), 
      evolutionLevel(evolution), 
      maxHP(maxHp), 
      hp(maxHp) 
{
    attacks.push_back(make_tuple(energyCost1, 0, nomAttack1, damage1));
    attacks.push_back(make_tuple(energyCost2, 0, nomAttack2, damage2));
}

void PokemonCard::displayInfo() const {
    cout << "Pokemon Card - Name: " << getCardName() 
         << ", Type: " << pokemonType 
         << ", Evolution Level: " << evolutionLevel 
         << " of the family \"" << familyName << "\", HP: ";
    if (hp == maxHP) {
        cout << maxHP << endl;
    } else {
        cout << hp << endl;
    }

    cout << "Attacks:" << endl;
    for (size_t i = 0; i < attacks.size(); ++i) {
        cout << "Attack #" << i << ":" << endl;
        cout << "Attack cost: " << get<0>(attacks[i]) << endl;
        cout << "Attack current energy storage : " << attachedEnergies.size() << endl;
        cout << "Attack description: " << get<2>(attacks[i]) << endl;
        cout << "Attack damage: " << get<3>(attacks[i]) << endl;
    }
}

void PokemonCard::displayEnergy() const {
    if (attachedEnergies.empty()) {
        cout << "None." << endl;
        return;
    }
    for (const auto& energy : attachedEnergies) {
        cout << energy->getEnergyType() << " ";
    }
    cout << endl; 
}


void PokemonCard::attachEnergy(EnergyCard* energy) {
    attachedEnergies.push_back(energy);
}

void PokemonCard::takeDamage(int damage) {
    hp -= damage;
}

int PokemonCard::getAttackDamage(int attackIndex) const {
    if (attackIndex < 0 || attackIndex >= attacks.size()) {
        return 0;
    }
    return get<3>(attacks[attackIndex]);
}

string PokemonCard::getAttackName(int attackIndex) const {
    if (attackIndex < 0 || attackIndex >= attacks.size()) {
        return "Unknown Attack";
    }
    return get<2>(attacks[attackIndex]);
}

void PokemonCard::healToMaxHP() {
    hp = maxHP;
}

string PokemonCard::getFamilyName() const { return familyName; } 
string PokemonCard::getpokemonType() const { return pokemonType; }   
int PokemonCard::getmaxHP() const { return maxHP; }
int PokemonCard::gethp() const { return hp; }