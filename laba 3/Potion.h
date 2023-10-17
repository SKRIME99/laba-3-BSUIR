#ifndef POTION_H
#define POTION_H

#include "Item.h"

class Potion : public Item {
public:
    Potion(const std::string& name, int maxQuantity, double weight, int healingPower);

    void Drink();

    int GetHealingPower();

private:
    int healingPower;
};

#endif