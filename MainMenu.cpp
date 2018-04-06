//include statements here...
#include <stdio.h>
#include <tchar.h>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include <map>
#include <iostream>
#include <cassert>
#include "MainMenu.h"

MainMenu::MenuResult MainMenu::Show(sf::RenderWindow*& window) {

    //Load menu image from file
    sf::Texture image;
    image.loadFromFile("images/Mainmenu.png");
    sf::Sprite sprite(image);

    //Setup clickable regions

    //Play menu item coordinates
    MenuItem playButton;
    playButton.rect.top= 113;
    playButton.rect.height = 190;
    playButton.rect.left = 0;
    playButton.rect.width = 607;
    playButton.action = Play;

    //Exit menu item coordinates
    MenuItem exitButton;
    exitButton.rect.left = 0;
    exitButton.rect.width = 607;
    exitButton.rect.top = 304;
    exitButton.rect.height = 145;
    exitButton.action = Exit;

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    (*window).draw(sprite);
    (*window).display();

    return Show(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y) {
    std::list<MenuItem>::iterator it;

    for ( it = _menuItems.begin(); it != _menuItems.end(); it++) {
        sf::Rect<int> menuItemRect = (*it).rect;
        if( x > menuItemRect.left && x < menuItemRect.left + menuItemRect.width && y > menuItemRect.top && y < menuItemRect.height + menuItemRect.top) {
            return (*it).action;
        }
    }

    return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window) {
    sf::Event menuEvent;

    while(true){

        while(window.pollEvent(menuEvent)) {
            if(menuEvent.type == sf::Event::MouseButtonPressed) {
                return HandleClick(menuEvent.mouseButton.x, menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed){
                return Exit;
            }
        }
    }
}

