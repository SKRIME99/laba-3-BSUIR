#include "Weapon.h"
#include <iostream>

Weapon::Weapon(const std::string& name, int maxQuantity, double weight, int damage)
    : Item(name, maxQuantity, weight), damage(damage) {}

void Weapon::Attack() {
    std::cout << "You use " << name << " to deal " << damage << " damage." << std::endl;
}
int Weapon::GetDamage() {
    return damage;
}