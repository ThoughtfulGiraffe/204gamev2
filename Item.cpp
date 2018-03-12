//Author: Chris Jorritsma
//CIS 204 Game
//Date: 3/12/2018

#include <string>
#include <sstream>
#include "Item.h"

using namespace std;

Item::Item()
{
    name = "item";
    description = "a generic item. Not very useful, is it?";
    isUnique = true;
    quantity = 1;
}

Item::Item(string name, string description, bool isUnique)
{
    this->name = name;
    this->description = description;
    this->isUnique = isUnique;
    quantity = 1;
}

Item::Item(string name, string description, int quantity)
{
    this->name = name;
    this->description = description;
    this->isUnique = false;
    this->quantity = quantity;
}

string Item::getName()
{
    return name;
}

string Item::getDescription()
{
    return description;
}

int Item::getQuantity()
{
    return quantity;
}

bool Item::getIsUnique()
{
    return isUnique;
}

void Item::setQuantity(int newQuant)
{
    quantity = newQuant;
}

string Item::toString()
{
    string quantStr = static_cast<ostringstream*>( &(ostringstream() << quantity) )->str();
    string str = getName() + "\n" + getDescription() + "\nQuantity: " + quantStr;
    return str;
}


