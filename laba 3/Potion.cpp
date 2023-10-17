#include "Potion.h"
#include <iostream>

Potion::Potion(const std::string& name, int maxQuantity, double weight, int healingPower)
    : Item(name, maxQuantity, weight), healingPower(healingPower) {}

void Potion::Drink() {
    std::cout << "You drink " << name << " and heal " << healingPower << " points." << std::endl;
}
int Potion::GetHealingPower()
{
    return healingPower;
}