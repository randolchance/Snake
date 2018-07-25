//
// Created by dco on 7/22/18.
//

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game(): m_window("Snake", sf::Vector2u(800,600)),m_snake(m_world.GetBlockSize()),m_world(sf::Vector2u(800,600)) {
    m_textbox.Setup(5,14,350,sf::Vector2f(225,0));
    m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));
    m_window.GetEventManager()->AddCallback("MoveLeft", &Game::MoveLeft, this);
    m_window.GetEventManager()->AddCallback("MoveRight", &Game::MoveRight, this);
    m_window.GetEventManager()->AddCallback("MoveUp", &Game::MoveUp, this);
    m_window.GetEventManager()->AddCallback("MoveDown", &Game::MoveDown, this);
}

Game::~Game() { }

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed += m_clock.restart(); }

/* Replaced with MoveLeft MoveRight MoveUp MoveDown
void Game::HandleInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down) {
        m_snake.SetDirection(Direction::Up);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up) {
        m_snake.SetDirection(Direction::Down);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right) {
        m_snake.SetDirection(Direction::Left);
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left) {
        m_snake.SetDirection(Direction::Right);
    }
}
 */
void Game::MoveLeft(EventDetails* l_details = nullptr) {
    if (m_snake.GetPhysicalDirection() != Direction::Right) m_snake.SetDirection(Direction::Left);
}
void Game::MoveRight(EventDetails* l_details = nullptr) {
    if (m_snake.GetPhysicalDirection() != Direction::Left) m_snake.SetDirection(Direction::Right);
}
void Game::MoveUp(EventDetails* l_details = nullptr) {
    if (m_snake.GetPhysicalDirection() != Direction::Down) m_snake.SetDirection(Direction::Up);
}
void Game::MoveDown(EventDetails* l_details = nullptr) {
    if (m_snake.GetPhysicalDirection() != Direction::Up) m_snake.SetDirection(Direction::Down);
}

void Game::Update() {
    m_window.Update();
    float step = 1.0f / m_snake.GetSpeed();
    sf::Time time_step = sf::seconds(step);
    if (m_elapsed >= time_step) {
        m_snake.Tick();
        m_world.Update(m_snake);
        if (m_world.isAppleEaten()) {
            m_textbox.Add("You ate an apple! You feel longer!");
            m_textbox.Add(std::to_string(m_snake.GetScore()) + " pts");
        } else if (m_snake.WasBit()) {
            m_textbox.Add("You bit your tail off!");
            m_snake.ResetBit();
        }
        m_elapsed -= time_step;
        if(m_snake.HasLost()){
            m_textbox.Clear();
            m_textbox.Add("You heckin' died!");
            m_snake.Reset();
        }
    }
}

void Game::Render() {
    m_window.BeginDraw();
// Render here.
    m_world.Render(*m_window.GetRenderWindow());
    m_snake.Render(*m_window.GetRenderWindow());
    m_textbox.Render(*m_window.GetRenderWindow());

    m_window.EndDraw();
}

Window* Game::GetWindow() { return &m_window; }