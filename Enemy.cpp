#include "Enemy.h"

Enemy::Enemy(int pX, int pY, sf::Texture character)
{
    posX = pX;
    posY = pY;
    name = "An enemy!!! Grr!!! Argh!!!";
    maxHealth = currentHealth = 1.0;
    baseDamage = 1.0;
}

Enemy::Enemy(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage)
{
    posX = pX;
    posY = pY;
    name = n;
    maxHealth = currentHealth = mHealth;
    baseDamage = bDamage;
}

Enemy::Enemy(Enemy e)
{
    posX = e.getPosX();
    posY = e.getPosY();
    name = e.getName();
    maxHealth = e.getMaxHealth();
    currentHealth = e.getCurrentHealth();
    baseDamage = e.getBaseDamage();
}

void Enemy::Move(int direction)
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

void Enemy::attack(MovableEntity entityToAttack)
{
    entityToAttack.takeDamage(baseDamage);
}
