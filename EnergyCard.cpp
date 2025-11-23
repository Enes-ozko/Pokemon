#include "EnergyCard.h"
#include <iostream>
using namespace std;


EnergyCard::EnergyCard(const string& energyType)
    : Card("Energy"), energyType(energyType) 
{
}

string EnergyCard::getEnergyType() const {
    return energyType;
}
void EnergyCard::displayInfo() const  {
}
