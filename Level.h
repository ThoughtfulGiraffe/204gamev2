#ifndef LEVEL_H_INCLUDED
#define LEVEL_H_INCLUDED

#include <string>
#include <vector>
#include "Tile.h"
#include "ImageManager.h"

class Level {
    private:
        //A 2D array of Tile pointers
        std::vector<std::vector<Tile*> > map;

        //Width and height of level (in tiles)
        int w;
        int h;

        void SetDimensions(int w, int h);

    public:
        Level();
        ~Level();

        void AddTile(int x, int y, Tile* tile);
        Tile* GetTile(int x, int y);

        void LoadLevel(std::string filename, ImageManager& imageManager);

        int GetWidth();
        int GetHeight();
};

#endif // LEVEL_H_INCLUDED
