#include "Player.h"

Player::Player(int pX, int pY, sf::Texture character)
{
    posX = pX;
    posY = pY;
    name = "An enemy!!! Grr!!! Argh!!!";
    maxHealth = currentHealth = 1.0;
    baseDamage = 1.0;
    currentWeapon = new Weapon();
}

Player::Player(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage, Weapon w)
{
    posX = pX;
    posY = pY;
    name = n;
    maxHealth = currentHealth = mHealth;
    baseDamage = bDamage;
    currentWeapon = new Weapon(w);
}

Player::Player(Player p)
{
    posX = p.getPosX();
    posY = p.getPosY();
    name = p.getName();
    maxHealth = p.getMaxHealth();
    currentHealth = p.getCurrentHealth();
    baseDamage = p.getBaseDamage();
    currentWeapon = new Weapon(p.getCurrentWeapon())
}

void Player::Move(int direction)
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

void Player::attack(MovableEntity entityToAttack)
{
    entityToAttack.takeDamage(baseDamage + currentWeapon.getDamageDealt());
}

void Player::changeWeapon(Weapon w)
{
    currentWeapon = new Weapon(w);
}

Weapon Player::getCurrentWeapon()
{
    return currentWeapon;
}
