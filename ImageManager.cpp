#include "ImageManager.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

#include <SFML\Graphics.hpp>

#include "rapidxml.hpp"

using namespace rapidxml;

ImageManager::ImageManager() {

}

ImageManager::~ImageManager() {

}

void ImageManager::AddImage(sf::Texture& image, int id) {
	imageList.push_back(image);

	//Map for pairing image ids and the image's index in imageList
	imageIDs[id] = imageList.size() - 1;
}

sf::Texture& ImageManager::GetImage(int id) {
	return imageList[imageIDs[id]];
}

void ImageManager::LoadTileset(std::string filename, int firstid) {
	//Load the file
	std::ifstream inFile(filename.c_str());

	if(!inFile)
		throw "Could not load tileset: " + filename;

	//Dump contents of file into a string
	std::string xmlContents;

	//Blocked out of preference
	{
		std::string line;
		while(std::getline(inFile, line))
			xmlContents += line;
	}

	//Convert string to rapidxml readable char*
	std::vector<char> xmlData = std::vector<char>(xmlContents.begin(), xmlContents.end());
    xmlData.push_back('\0');

	//Create a parsed document with &xmlData[0] which is the char*
	xml_document<> doc;
	doc.parse<parse_no_data_nodes>(&xmlData[0]);

	//Get the root node
	xml_node<>* root = doc.first_node();

	//Some variables used in the following code
	std::string imagePath;
	sf::Image tileset;
	int id = firstid;

	//Go through each imagefile
	xml_node<>* imagefile = root->first_node("image");
	//while(imagefile) {
		//Get the image file we're parsing and load it
		imagePath = imagefile->first_attribute("source")->value();
		std::cout << imagePath << std::endl;

		tileset.loadFromFile(imagePath);


        int maxX = atoi(imagefile->first_attribute("width")->value()) / 32;
        int maxY = atoi(imagefile->first_attribute("height")->value()) / 32;
        std::cout << imagePath << maxX << maxY << std::endl;
        //Go through each tile
		for (int y = 0; y < maxY; y++) {
            //std::cout << y << std::endl;
			//Copy the right tile image from tileset
			for (int x = 0; x < maxX; x++) {
                //std::cout << x << std::endl;
                sf::Image tileImage;
                tileImage.create(tileSize, tileSize);
                tileImage.copy(tileset, 0, 0, sf::IntRect(x * tileSize, y * tileSize, 1 * tileSize, tileSize), true);

                //Add the image to our image list
                sf::Texture newTile;
                newTile.loadFromImage(tileImage);
                AddImage(newTile, id);
                id = id + 1;
                //Go to the next tile
                //tile = tile->next_sibling();
			}
		}

		//Go to the next imagefile
		//imagefile = imagefile->next_sibling();
	//}
	sf::Image background;
	background.loadFromFile("images/tree.png");
	sf::Texture backgroundTex;
	backgroundTex.loadFromImage(background);
	AddImage(backgroundTex, 999);
}
