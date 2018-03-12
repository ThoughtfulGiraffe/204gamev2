#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

class Player:
public:
    Player(int posX, int posY, sf::Texture character);
    ~Player();

    void Move();
    void Draw();

    float getXVelocity();
    float getYVelocity();

private:
    int playerPosX;
    int playerPosY;
    float _xvelocity;
    float _yvelocity;
    float _maxVelocity;

#endif // PLAYER_H_INCLUDED
