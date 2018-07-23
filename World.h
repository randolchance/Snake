//
// Created by dco on 7/22/18.
//

#ifndef SNAKE_WORLD_H
#define SNAKE_WORLD_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"

class World {
public:
    World(sf::Vector2u l_windSize);
    ~World();

    int GetBlockSize();

    void RespawnApple();
    bool isAppleEaten();

    void Update(Snake& l_player);
    void Render(sf::RenderWindow& l_window);

private:
    sf::Vector2u m_windowSize;
    sf::Vector2i m_item;
    int m_blockSize;
    bool apple_eaten;

    sf::CircleShape m_appleShape;
    sf::RectangleShape m_bounds[4];
};

#endif //SNAKE_WORLD_H
