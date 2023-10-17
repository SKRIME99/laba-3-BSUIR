#ifndef RESOURCE_H
#define RESOURCE_H
#include<string>
#include "Item.h"

class Resource : public Item {
public:
    Resource(const std::string& name, int maxQuantity, double weight, int value);
    int GetValue();
    void Use();

private:
    int value;
};

#endif