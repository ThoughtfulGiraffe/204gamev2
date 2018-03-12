#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <stdio.h>

#include "Level.h"
#include "Tile.h"
#include "ImageManager.h"
#include <iostream>

#include "rapidxml.hpp"
#include "rapidxml_print.hpp"

using namespace rapidxml;

Level::Level() {

}

Level::~Level() {

}

int Level::GetHeight() {
	return h;
}

int Level::GetWidth() {
	return w;
}

void Level::SetDimensions(int w, int h) {
	//w rows
	map.resize(w);

	//Each row has h columns of null Tile pointers
	for(int i = 0; i < w; i++)
	{
		map.at(i).resize(h, 0);
	}
}

void Level::AddTile(int x, int y, Tile* tile) {
	map[x][y] = tile;
}

Tile* Level::GetTile(int x, int y) {
	if(x < map.capacity())
	{
		if(y < map[x].capacity())
		{
			return map[x][y];
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void Level::LoadLevel(std::string filename, ImageManager& imageManager) {
	//Loads a level from xml file
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

	//Get level attributes
	int width = atoi(root->first_attribute("width")->value());
	int height = atoi(root->first_attribute("height")->value());

	//Resize level
	this->w = width;
	this->h = height;
	SetDimensions(width, height);

	//Load each necessary tileset
	xml_node<>* tileset = root->first_node("tileset");

	while(tileset) {
		std::string path = tileset->first_attribute("source")->value();
        std::cout << path << std::endl;
		int firstid = atoi(tileset->first_attribute("firstgid")->value());
		//Load tileset
        imageManager.LoadTileset(path, firstid);

		//Go to next tileset
		tileset = tileset->next_sibling("tileset");
	}

    xml_node<>* data = root->first_node("data");

	while (data){
        std::string tiles = data->first_attribute("source")->value();
        std::stringstream ss(tiles);
        int i;
        int x = 0;
        int y = 0;
        int test = 0;

        while (ss >> i) {
            if (i != 0) {
                Tile* newTile = new Tile(imageManager.GetImage(i));
                AddTile(x, y, newTile);
            }
            x++;
            if (ss.peek() == ',') {
                ss.ignore();
            }
            if (x == 50) {
                x = 0;
                y++;
            } else {

            }
            test++;
        }
        data = data->next_sibling("data");
    }
}
