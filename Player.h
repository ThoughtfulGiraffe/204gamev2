#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player::public MovableEntity
{
    public:
        Player(int pX, int pY, sf::Texture character);
        Player(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage);
        Player(Player p);
        void attack(MovableEntity entityToAttack);
        void Move();
        void changeWeapon(Weapon w);
        Weapon getCurrentWeapon();
    private:
        Weapon currentWeapon;
};



#endif // PLAYER_H_INCLUDED
