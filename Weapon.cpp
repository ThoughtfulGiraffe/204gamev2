#include "Weapon.h"

Weapon::Weapon()
{
    name = "None";
    description = "You have no weapon!";
    damageDealt = 0.0;
}

Weapon::weapon(string n, string d, double damage)
{
    name = n;
    description = d;
    damageDealt = damage;
}

Weapon::Weapon(Weapon w)
{
    name = w.getName();
    description = w.getDescription();
    damageDealt = w.getDamageDealt();
}

string Weapon::getName()
{
    return name;
}

string Weapon::getDescription()
{
    return description;
}

double Weapon::getDamageDealt()
{
    return damageDealt;
}
