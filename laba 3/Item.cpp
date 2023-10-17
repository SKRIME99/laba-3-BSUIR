#include "Item.h"
#include<string>
int Item::nextID = 1;

Item::Item(const std::string& name, int maxQuantity, double weight)
    : id(nextID++), name(name), maxQuantity(maxQuantity), weight(weight), quantity(0) {}

void Item::AddToInventory() {
    if (quantity < maxQuantity) {
        quantity++;
    }
}

void Item::RemoveFromInventory() {
    if (quantity > 0) {
        quantity--;
    }
}

int Item::GetID() const {
    return id;
}

 std::string Item::GetName() {
    return name;


 }
 double Item::GetWeight() {

    return weight;
}