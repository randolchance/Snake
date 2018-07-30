//
// Created by dco on 7/22/18.
//

#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H
#include "Window.h"
#include "World.h"
#include "Snake.h"
#include "Textbox.h"
#include "StateManager.h"
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Game{
public:
    Game();
    ~Game();
    //void HandleInput(); OBSOLETE
    void Update();
    void Render();
    Window* GetWindow();
    sf::Time GetElapsed();
    void RestartClock();
    void LateUpdate();

private:
    Window m_window;
    Textbox m_textbox;
    sf::Clock m_clock;
    sf::Time m_elapsed;
    StateManager m_stateManager;
    SharedContext m_context;
};

#endif //SNAKE_GAME_H
