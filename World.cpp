//
// Created by dco on 7/22/18.
//
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Snake.h"
#include "World.h"

World::World(sf::Vector2u l_windSize){
    m_blockSize = 16;
    m_windowSize = l_windSize;
    RespawnApple();
    m_appleShape.setFillColor(sf::Color::Red);
    m_appleShape.setRadius(m_blockSize / 2);

    for(int i = 0; i < 4; ++i) {
        m_bounds[i].setFillColor(sf::Color(150,0,0));
        if (!((i + 1) % 2)) {
            m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
        } else {
            m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y));
        }
        if (i < 2) {
            m_bounds[i].setPosition(0,0);
        } else {
            m_bounds[i].setOrigin(m_bounds[i].getSize()); // Sets origin to bottom-right corner of wall
            m_bounds[i].setPosition(sf::Vector2f(m_windowSize)); // Sets position to bottom-right corner of screen
        }
    }
}
World::~World() { }

void World::RespawnApple() {
    int maxX = (m_windowSize.x / m_blockSize) - 2;
    int maxY = (m_windowSize.y / m_blockSize) - 2;
    m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
    m_appleShape.setPosition(m_item.x * m_blockSize, m_item.y * m_blockSize);
}

bool World::isAppleEaten() { return m_apple_eaten; }

void World::Update(Snake& l_player){
    m_apple_eaten = false;
    if(l_player.GetPosition() == m_item) {
        l_player.Extend();
        l_player.IncreaseScore();
        RespawnApple();
        m_apple_eaten = true;
    }
    int gridSize_x = m_windowSize.x / m_blockSize;
    int gridSize_y = m_windowSize.y / m_blockSize;
    if ((l_player.GetPosition().x <= 0) || (l_player.GetPosition().y <= 0) ||
        (l_player.GetPosition().x >= gridSize_x - 1) || (l_player.GetPosition().y >= gridSize_y - 1)) {
        l_player.Lose();
    }
}

void World::Render(sf::RenderWindow& l_window){
    for (const auto& side : m_bounds) {
        l_window.draw(side);
    }
    l_window.draw(m_appleShape);
}

int World::GetBlockSize(){ return m_blockSize; }