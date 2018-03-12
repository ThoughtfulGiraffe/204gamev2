//Author: Chris Jorritsma
//CIS 204 Game
//Date: 3/12/2018

#include <string>
#include "Bag.h"
#include "Item.h"

using namespace std;

Bag::Bag()
{
    itemList = new Item[5];
    lngth = 0;
    capacity = 5;
}

Bag::Bag(int size)
{
    itemList = new Item[size];
    lngth = 0;
    capacity = size;
}

void Bag::addItem(Item itmToAdd)
{
    if(lngth < capacity)
        itemList[lngth] = itmToAdd;
    else
        increaseSize(itmToAdd);
    lngth++;
}

bool Bag::removeItem(string itemName)
{
    int itm = locateItem(itemName);
    if(itm == -1)
        return false;
    decreaseSize(itm);
    lngth--;
    return true;
}

void Bag::increaseSize(Item itmToAdd)
{
    Item * newList = new Item[capacity + 1];
    for(int i = 0; i < capacity; i++)
        newList[i] = itemList[i];
    newList[capacity] = itmToAdd;
    delete [] itemList;
    itemList = newList;
    capacity++;
}

void Bag::decreaseSize(int itmToRemove)
{
    Item * newList = new Item[capacity - 1];
    int j = 0;
    for(int i = 0; i < capacity; i++)
    {
        if(i != itmToRemove)
        {
            newList[j] = itemList[i];
            j++;
        }
    }
    delete [] itemList;
    itemList = newList;
    capacity--;
}

int Bag::changeItemQuant(string itemName, int amntToAdd)
{
    int itm = locateItem(itemName);
    if(itm == -1)
        return -1;
    else if(itemList[itm].getIsUnique())
        return -2;
    else if(itemList[itm].getQuantity() + amntToAdd < 0)
        return -3;
    else
    {
        itemList[itm].setQuantity(itemList[itm].getQuantity() + amntToAdd);
        if(itemList[itm].getQuantity() == 0)
        {
            removeItem(itemList[itm].getName());
            return 1;
        }
    }
    return 0;
}

int Bag::locateItem(string itemName)
{
    for(int i = 0; i < lngth; i++)
    {
        if(itemList[i].getName() == itemName)
            return i;
    }
    return -1;
}

string Bag::toString()
{
    string str = "";
    for(int i = 0; i < lngth; i++)
    {
        str += itemList[i].toString();
        str += "\n";
    }
    return str;
}
