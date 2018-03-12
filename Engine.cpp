#include "Engine.h"
#include "Camera.h"
#include "Tile.h"
#include <iostream>

#include <SFML\Graphics.hpp>

Engine::Engine(int w, int h, int tileSize) {
    videoSize = sf::Vector2i(w, h);
	this->tileSize = tileSize;
	imageManager.setTileSize(tileSize);
}

Engine::~Engine() {

}

bool Engine::Init() {
	window = new sf::RenderWindow(sf::VideoMode(videoSize.x, videoSize.y, 32), "Doki Doki Sheep Club");
    camera = new Camera(videoSize.x, videoSize.y, 4.0f);

	mouseDown = false;

	if(!window)
		return false;

    currentLevel = new Level();
	currentLevel->LoadLevel("LevelOne.xml", imageManager);

	return true;
}

void Engine::ProcessInput() {
	sf::Event evt;
	//Loop through all window events
	while(window->pollEvent(evt))
	{
		if(evt.type == sf::Event::Closed)
			window->close();

		/*if((evt.type == sf::Event::MouseButtonPressed) && (mouseDown == false))
		{
			int x = camera->GetPosition().x + evt.mouseButton.x;
			int y = camera->GetPosition().y + evt.mouseButton.y;
			camera->GoToCenter(x, y);
			mouseDown = true;
		}
		if(evt.type == sf::Event::MouseButtonReleased)
			mouseDown = false;*/
        if(evt.type == sf::Event::KeyPressed) {
            if (evt.key.code == sf::Keyboard::Up) {
                int x = camera->GetPosition().x;
                int y = camera->GetPosition().y;
                camera->GoToCenter(x, y);
            } else if (evt.key.code == sf::Keyboard::Left) {
                int x = camera->GetPosition().x;
                int y = camera->GetPosition().y;
                camera->GoToCenter(x, y);
            } else if (evt.key.code == sf::Keyboard::Down) {
                int x = camera->GetPosition().x;
                int y = camera->GetPosition().y;
                camera->GoToCenter(x, y);
            } else if (evt.key.code == sf::Keyboard::Right) {
                int x = camera->GetPosition().x;
                int y = camera->GetPosition().y;
                camera->GoToCenter(x, y);
            }
        }
	}
}

void Engine::Update() {
    camera->Update();
}

void Engine::MainLoop() {
	//Loop until our window is closed
	while(window->isOpen())
	{
		ProcessInput();
		Update();
		RenderFrame();
	}
}

void Engine::Go() {
	if(!Init())
		throw "Could not initialize Engine";

	MainLoop();
}

void Engine::RenderFrame() {
	//Camera offsets
	int camOffsetX, camOffsetY;

	Tile* tile;

	window->clear();

	//Get the tile bounds that are needed to draw and Camera bounds
	sf::IntRect bounds = camera->GetTileBounds(tileSize);

	//Figure out how much to offset each tile
	camOffsetX = camera->GetTileOffset(tileSize).x;
	camOffsetY = camera->GetTileOffset(tileSize).y;

	//Loop through and draw each tile
	//Keeping track of two variables in each loop. How many tiles
	//are drawn (x and y), and which tile on the map are drawing (tileX
	//and tileY)
	for(int y = 0, tileY = bounds.top; y < bounds.height; y++, tileY++)
	{
		for(int x = 0, tileX = bounds.left; x < bounds.width; x++, tileX++)
		{
			//Get the tile we're drawing
			tile = currentLevel->GetTile(tileX, tileY);
			if (tile != 0) {
                tile->Draw((x * tileSize) - camOffsetX, (y * tileSize) - camOffsetY, window);
			} else {
                Tile* backgroundTile = new Tile(imageManager.GetImage(999));
                backgroundTile->Draw((x * tileSize) - camOffsetX, (y * tileSize) - camOffsetY, window);
			}

		}
	}
	window->display();
}

