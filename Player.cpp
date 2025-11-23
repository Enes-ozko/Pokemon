#include "Player.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <iostream>
#include <algorithm> 
#include <vector>

using namespace std;

Player::Player(const string& name) : playerName(name) {}

Player::~Player() {
    for (Card* card : benchCards) {
        delete card;
    }
}

string Player::getplayerName() const { return playerName; }
const vector<Card*>& Player::getBenchCards() const { return benchCards; }
const vector<PokemonCard*>& Player::getActionCards() const { return actionCards; }

void Player::addCardToBench(Card* card) {
    benchCards.push_back(card);
}

void Player::activatePokemonCard(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= benchCards.size()) return;
    if (!actionCards.empty()) return;

    PokemonCard* pokemon = dynamic_cast<PokemonCard*>(benchCards[benchIndex]);
    if (pokemon) {
        actionCards.push_back(pokemon);
        cout << playerName << " is activating a Pokemon Card: " << pokemon->getCardName() << endl;
    }
}

void Player::attachEnergyCard(int energyIndex, int targetActionIndex) {
    if (energyIndex < 0 || energyIndex >= benchCards.size() || targetActionIndex < 0 || targetActionIndex >= actionCards.size()) return;

    EnergyCard* energy = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
    PokemonCard* targetPokemon = actionCards[targetActionIndex];

    if (energy) {
        targetPokemon->attachEnergy(energy);
        benchCards.erase(remove(benchCards.begin(), benchCards.end(), energy), benchCards.end());
        cout << playerName << " is attaching Energy Card of type " << energy->getEnergyType() 
                  << " to the Pokemon " << targetPokemon->getCardName() << endl;
    }
}

void Player::displayBench() {
    cout << "Bench cards for Player: " << playerName << endl;
    for (size_t i = 0; i < benchCards.size(); ++i) {
        benchCards[i]->displayInfo(); 
    }
}

void Player::displayAction() {
    std::cout << "Action cards for Player: " << playerName  << endl;
    for (size_t i = 0; i < actionCards.size(); ++i) {
        actionCards[i]->displayInfo(); 
        actionCards[i]->displayEnergy();
    }
}

void Player::attack(int actionIndex, int attackIndex, Player& targetPlayer, int targetIndex) {
    if (actionIndex < 0 || attackIndex < 0 || targetIndex < 0 || 
        actionIndex >= actionCards.size() || targetIndex >= targetPlayer.actionCards.size()) return;

    PokemonCard* attacker = actionCards[actionIndex];
    PokemonCard* defender = targetPlayer.actionCards[targetIndex];

    int damage = attacker->getAttackDamage(attackIndex); 
    string attackName = attacker->getAttackName(attackIndex);
    
    cout << playerName << " attacking " << targetPlayer.getplayerName() << "'s Pokemon " << defender->getCardName() 
              << " with the Pokemon " << attacker->getCardName() 
              << " with its attack: " << attackName << endl;
    
    cout << "Reducing " << damage << " from " << targetPlayer.getplayerName() << "'s Pokemon's HP" << endl;

    defender->takeDamage(damage); 

    if (defender->gethp() > 0) {
        cout << defender->getCardName() << " is still alive" << endl;
    }
}

void Player::useTrainerCard(int benchIndex) {
    if (benchIndex < 0 || benchIndex >= benchCards.size()) return;

    TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[benchIndex]);

    if (trainer) {
        cout << playerName << " is using the Trainer Card to \"" << trainer->gettrainerEffect() << "\"" << endl;
        if (!actionCards.empty()) {
            actionCards[0]->healToMaxHP(); 
        }
        delete benchCards[benchIndex]; 
        benchCards.erase(benchCards.begin() + benchIndex);
    }
}