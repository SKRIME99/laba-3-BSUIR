#include "Resource.h"
#include<string>
#include <iostream>


using namespace std;
Resource::Resource(const std::string& name, int maxQuantity, double weight, int value)
    : Item(name, maxQuantity, weight), value(value) {}

void Resource::Use() {
    std::cout << "You use " << name << " to gain " << value << " points." << std::endl;
}
int Resource::GetValue() {
    return value;
}