#ifndef ENTITY_H
#define ENTITY_H


class Entity
{
    public:
        Entity();
        Entity(string n, double mHealth, double bDamage);
        Entity(Entity e);
        virtual void attack(Entity entityToAttack);
        bool takeDamage(double damageDealt);
        void heal(double healthToHeal);
        void increaseMaxHealth(double healthToAdd);
        void setCurrentHealth(double cHealth);
        string getName();
        double getMaxHealth();
        double getCurrentHealth();
        double getBaseDamage();
    private:
        string name;
        double maxHealth, currentHealth, baseDamage;
};

#endif // ENTITY_H
