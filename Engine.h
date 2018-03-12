#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <SFML\Graphics.hpp>

#include "ImageManager.h"
#include "Tile.h"
#include "Camera.h"
#include "Level.h"


class Engine {
    private:
        sf::RenderWindow* window;
        ImageManager imageManager;

        //Render Window (and Camera) size
        sf::Vector2i videoSize;

        //Camera
        Camera* camera;

        //Current Level
        Level* currentLevel;

        //Tile Dimensions
        int tileSize;

        //Initializes the engine
        bool Init();
        //Main Game Loop
        void MainLoop();
        //Renders one frame
        void RenderFrame();
        //Processes user input
        void ProcessInput();
        //Updates all Engine internals
        void Update();

        bool mouseDown;

    public:
        Engine(int w, int h, int tileSize);
        ~Engine();

        void Go();					//Starts the engine
};

#endif // ENGINE_H_INCLUDED
