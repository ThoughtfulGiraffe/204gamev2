#ifndef WEAPON_H
#define WEAPON_H


class Weapon
{
    public:
        Weapon();
        Weapon(string n, string d, double damage);
        Weapon(Weapon w);
        string getName();
        string getDescription();
        double getDamageDealt();
    private:
        string name, description;
        double damageDealt;
};

#endif // WEAPON_H
