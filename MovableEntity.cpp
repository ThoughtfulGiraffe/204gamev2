#include "MovableEntity.h"

MovableEntity::MovableEntity(int pX, int pY, sf::Texture character)
{
    posX = pX;
    posY = pY;
    name = "Living thing (Probably? I mean why else would it be moving?)";
    maxHealth = currentHealth = 1.0;
    baseDamage = 1.0;
}

MovableEntity::MovableEntity(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage)
{
    posX = pX;
    posY = pY;
    name = n;
    maxHealth = currentHealth = mHealth;
    baseDamage = bDamage;
}

MovableEntity::MovableEntity(MovableEntity e)
{
    posX = e.getPosX();
    posY = e.getPosY();
    name = e.getName();
    maxHealth = e.getMaxHealth();
    currentHealth = e.getCurrentHealth();
    baseDamage = e.getBaseDamage();
}

void MovableEntity::Move(int direction)
{
        switch (direction) {
    case 0:

        break;
    case 1:

        break;
    case 2:

        break;
    case 3:

        break;
    }


}

void MovableEntity::attack(MovableEntity entityToAttack)
{
    entityToAttack.takeDamage(baseDamage);
}

bool MovableEntity::takeDamage(double damageDealt)
{
    currentHealth -= damageDealt;
    if(currentHealth <= 0)
        return false;
    return true;
}

void MovableEntity::heal(double healthToHeal)
{
    currentHealth += healthToHeal;
    if(currentHealth > maxHealth)
        currentHealth = maxHealth;
    return;
}

void MovableEntity::increaseMaxHealth(double healthToAdd)
{
    maxHealth += healthToAdd;
    return;
}

bool MovableEntity::setCurrentHealth(double cHealth)
{
    if(cHealth > maxHealth)
        return false;
    currentHealth = cHealth;
    return true;
}

double MovableEntity::getMaxHealth()
{
    return maxHealth;
}

double MovableEntity::getCurrentHealth()
{
    return currentHealth;
}

double MovableEntity::getBaseDamage()
{
    return baseDamage;
}

int getPosX()
{
    return posX;
}

int getPosY()
{
    return posY;
}

float getXVelocity() {
    return _xvelocity;
}

float getYVelocity() {
    return _yvelocity;
}
