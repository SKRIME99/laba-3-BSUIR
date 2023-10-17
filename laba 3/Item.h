#ifndef ITEM_H
#define ITEM_H
#include <string>
class Item {
public:
    Item(const std::string& name, int maxQuantity, double weight);

    void AddToInventory();
    void RemoveFromInventory();

    int GetID() const;

     virtual std::string GetName();
     virtual double GetWeight();

protected:
    static int nextID;
    int id;
    std::string name;
    int maxQuantity;
    double weight;
    int quantity;
};

#endif