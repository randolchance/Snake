//
// Created by dco on 7/22/18.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include "Window.h"
#include "World.h"
#include "Snake.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    ~Game();
    void HandleInput();
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
private:
    World m_world;
    Snake m_snake;
    Window m_window;
    sf::Clock m_clock;
    sf::Time m_elapsed;
};

#endif //SNAKE_GAME_H
