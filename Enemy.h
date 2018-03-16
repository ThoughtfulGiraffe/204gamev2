#ifndef ENEMY_H
#define ENEMY_H


class Enemy::public MovableEntity
{
    public:
        Enemy(int pX, int pY, sf::Texture character);
        Enemy(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage);
        Enemy(Enemy e);
        void attack(MovableEntity entityToAttack);
        void Move();
};

#endif // ENEMY_H
