#ifndef WEAPON_H
#define WEAPON_H

#include "Item.h"

class Weapon : public Item {
public:
    Weapon(const std::string& name, int maxQuantity, double weight, int damage);

    int GetDamage();

    void Attack();

private:
    int damage;
};

#endif