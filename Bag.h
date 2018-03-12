//Author: Chris Jorritsma
//CIS 204 Game
//Date: 3/12/2018

#ifndef BAG_H
#define BAG_H
#include <string>
#include "Item.h"

using namespace std;

class Bag
{
    public:
        Bag();
        Bag(int size);
        void addItem(Item itm);
        bool removeItem(string itemName);
        void increaseSize(Item itmToAdd);
        void decreaseSize(int itmToRemove);
        int changeItemQuant(string itemName, int amntToAdd);
        int locateItem(string itemName);
        string toString();
    private:
        Item * itemList;
        int lngth;
        int capacity;
};

#endif // BAG_H
