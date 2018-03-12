#ifndef IMAGEMANAGER_H_INCLUDED
#define IMAGEMANAGER_H_INCLUDED

#include <vector>
#include <map>
#include <string>
#include <SFML\Graphics.hpp>

using std::vector;

class ImageManager {
    private:
        vector<sf::Texture> imageList;

        std::map<int, int> imageIDs;

        int tileSize;
    public:
        ImageManager();
        ~ImageManager();

        void setTileSize(int tileSize) {
             this->tileSize = tileSize;
        }

        void AddImage(sf::Texture& image, int id);
        sf::Texture& GetImage(int id);

        void LoadTileset(std::string filename, int firstid);
};

#endif // IMAGEMANAGER_H_INCLUDED
