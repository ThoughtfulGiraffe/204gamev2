//Author: Chris Jorritsma
//CIS 204 Game
//Date: 3/12/2018

#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class Item
{
    public:
        Item();
        Item(string name, string description, bool isUnique);
        Item(string name, string description, int quantity);
        string getName();
        string getDescription();
        int getQuantity();
        bool getIsUnique();
        void setQuantity(int newQuant);
        string toString();
    private:
        string name;
        string description;
        int quantity;
        bool isUnique;
};

#endif // ITEM_H
