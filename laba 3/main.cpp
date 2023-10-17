#include <iostream>
#include <vector>
#include "Item.h"
#include "Weapon.h"
#include "Resource.h"
#include "Potion.h"

class Inventory {
public:
    void AddItem(Item* item) {
        inventory.push_back(item);
    }

    void RemoveItem(int index) {
        int i = 0;
        for (auto e : inventory) {
            if (e->GetID() == index)
            {
                delete e; // Освобождаем память
                inventory.erase(inventory.begin() + i);
                break;
            }
            i++;
        }
       
    }
    void UseItem(int ID) {
        for (size_t i = 0; i < inventory.size(); ++i) {
            if (inventory[i]->GetID() == ID) {
                if (Weapon* weapon = dynamic_cast<Weapon*>(inventory[i])) {// кастирование приводит к наследованному классу вэпон
                     weapon->Attack() ;
                }
                else if (Resource* resource = dynamic_cast<Resource*>(inventory[i])) {
                    resource->Use();

                }
                else if (Potion* potion = dynamic_cast<Potion*>(inventory[i])) {
                    potion->Drink();
                }
                break;

            }
        }
    }
    void DisplayContents() {
        std::cout << "Inventory Contents:" << std::endl;
        for (size_t i = 0; i < inventory.size(); ++i) {
            std::cout << "------------------------" << std::endl;
            std::cout << "Id: " << inventory[i]->GetID()   << std::endl;
            std::cout << "Name: " << inventory[i]->GetName() << std::endl;
            std::cout << "Weight: " << inventory[i]->GetWeight() << std::endl;

            // Вывод дополнительных информационных данных в зависимости от типа предмета
            if (Weapon* weapon = dynamic_cast<Weapon*>(inventory[i])) {
                std::cout << "Type: Weapon" << std::endl;
                std::cout << "Damage: " << weapon->GetDamage() << std::endl;
            }
            else if (Resource* resource = dynamic_cast<Resource*>(inventory[i])) {
                std::cout << "Type: Resource" << std::endl;
                std::cout << "Value: " << resource->GetValue() << std::endl;
            }
            else if (Potion* potion = dynamic_cast<Potion*>(inventory[i])) {
                std::cout << "Type: Potion" << std::endl;
                std::cout << "Healing Power: " << potion->GetHealingPower() << std::endl;
            }
            std::cout << "------------------------" << std::endl;
        }
    }

private:
    std::vector<Item*> inventory;
};

int main() {
    Inventory inventoryMenu;
    int choice;

    while (true) {
        std::cout << "Inventory Menu:" << std::endl;
        std::cout << "1. Add Weapon" << std::endl;
        std::cout << "2. Add Resource" << std::endl;
        std::cout << "3. Add Potion" << std::endl;
        std::cout << "4. Remove Item" << std::endl;
        std::cout << "5. Use Item" << std::endl;
        std::cout << "6. Display Inventory" << std::endl;
        std::cout << "7. Exit" << std::endl;
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cout << "\n" ;

        system("cls");

        switch (choice) {
        case 1: {
            // Добавить Weapon
            std::string name;
            int maxQuantity, damage;
            double weight;
            std::cout << "Enter the name of the weapon: ";
            std::cin >> name;
            std::cout << "Enter the max quantity: ";
            std::cin >> maxQuantity;
            std::cout << "Enter the weight: ";
            std::cin >> weight;
            std::cout << "Enter the damage: ";
            std::cin >> damage;
            inventoryMenu.AddItem(new Weapon(name, maxQuantity, weight, damage));
            break;
        }
        case 2: {
            // Добавить Resource
            std::string name;
            int maxQuantity, value;
            double weight;
            std::cout << "Enter the name of the resource: ";
            std::cin >> name;
            std::cout << "Enter the max quantity: ";
            std::cin >> maxQuantity;
            std::cout << "Enter the weight: ";
            std::cin >> weight;
            std::cout << "Enter the value: ";
            std::cin >> value;
            inventoryMenu.AddItem(new Resource(name, maxQuantity, weight, value));
            break;
        }
        case 3: {
            // Добавить Potion
            std::string name;
            int maxQuantity, healingPower;
            double weight;
            std::cout << "Enter the name of the potion: ";
            std::cin >> name;
            std::cout << "Enter the max quantity: ";
            std::cin >> maxQuantity;
            std::cout << "Enter the weight: ";
            std::cin >> weight;
            std::cout << "Enter the healing power: ";
            std::cin >> healingPower;
            inventoryMenu.AddItem(new Potion(name, maxQuantity, weight, healingPower));
            break;
        }
        case 4: {
            // Удалить предмет
            int index;
            std::cout << "Enter the ID of the item to remove: ";
            if (!(std::cin >> index) || index <= 0 ) {
                std::cout << "Invalid input. Please enter a valid index." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            else {
                inventoryMenu.RemoveItem(index);
            }
            break;
        }
        case 5: {
            std::cout << "Enter ID of Item , U wont to use: ";
            int buffer;
            std::cin >> buffer ;
            inventoryMenu.UseItem(buffer);

            



        }
        case 6: {
            std::cout << "\n";
            inventoryMenu.DisplayContents();
            std::cout << "\n";
            break;
        }
        case 7: {
            // Выход из программы
            return 0;
        }
        
        default:
            std::cout << "Invalid choice. Please enter a valid option." << std::endl;
        }
    }

    return 0;
}