#ifndef TILE_H_INCLUDED
#define TILE_H_INCLUDED

#include <SFML\Graphics.hpp>

class Tile {
    private:
        sf::Sprite baseSprite;

    public:
        Tile(sf::Texture& image);
        ~Tile();

        void Draw(int x, int y, sf::RenderWindow* rw);
};


#endif // TILE_H_INCLUDED
