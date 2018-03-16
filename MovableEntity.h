#ifndef MOVABLEENTITY_H
#define MOVABLEENTITY_H


class MovableEntity::public Entity
{
    public:
        MovableEntity(int pX, int pY, sf::Texture character);
        MovableEntity(int pX, int pY, sf::Texture character, string n, double mHealth, double bDamage);
        MovableEntity(MovableEntity e);
        virtual void Move(int direction);
        float getXVelocity();
        float getYVelocity();
        virtual void attack(MovableEntity entityToAttack);
        bool takeDamage(double damageDealt);
        void heal(double healthToHeal);
        void increaseMaxHealth(double healthToAdd);
        void setCurrentHealth(double cHealth);
        double getMaxHealth();
        double getCurrentHealth();
        double getBaseDamage();
    private:
        double maxHealth
        double currentHealth
        double baseDamage;
        int posX;
        int posY;
        float _xvelocity;
        float _yvelocity;
        float _maxVelocity;

};

#endif // MOVABLEENTITY_H
