#include "Entity.h"

Entity::Entity()
{
    name = "living thing";
    maxHealth = currentHealth = 1.0;
    baseDamage = 1.0;
}

Entity::Entity(string n, double mHealth, double bDamage)
{
    name = n;
    maxHealth = currentHealth = mHealth;
    baseDamage = bDamage;
}

Entity::Entity(Entity e)
{
    name = e.getName();
    maxHealth = e.getMaxHealth();
    currentHealth = e.getCurrentHealth();
    baseDamage = e.getBaseDamage();
}

void Entity::attack(Entity entityToAttack)
{
    entityToAttack.takeDamage(baseDamage);
}

bool Entity::takeDamage(double damageDealt)
{
    currentHealth -= damageDealt;
    if(currentHealth <= 0)
        return false;
    return true;
}

void Entity::heal(double healthToHeal)
{
    currentHealth += healthToHeal;
    if(currentHealth > maxHealth)
        currentHealth = maxHealth;
    return;
}

void Entity::increaseMaxHealth(double healthToAdd)
{
    maxHealth += healthToAdd;
    return;
}

bool Entity::setCurrentHealth(double cHealth)
{
    if(cHealth > maxHealth)
        return false;
    currentHealth = cHealth;
    return true;
}

string Entity::getName()
{
    return name;
}

double Entity::getMaxHealth()
{
    return maxHealth;
}

double Entity::getCurrentHealth()
{
    return currentHealth;
}

double Entity::getBaseDamage()
{
    return baseDamage;
}
