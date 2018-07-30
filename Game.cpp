//
// Created by dco on 7/22/18.
//

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"

Game::Game(): m_window("Snake", sf::Vector2u(800,600)), m_stateManager(&m_context) {
    m_context.m_wind = &m_window;
    m_context.m_eventManager = m_window.GetEventManager();
    m_context.m_textbox = &m_textbox;
    m_textbox.Setup(5,14,350,sf::Vector2f(225,0));
    m_textbox.Add("Seeded random number generator with: " + std::to_string(time(NULL)));

    m_stateManager.SwitchTo(StateType::Intro);
}

Game::~Game() { }

sf::Time Game::GetElapsed() { return m_elapsed; }
void Game::RestartClock() { m_elapsed = m_clock.getElapsedTime(); }

void Game::Update() {
    m_window.Update();
    m_stateManager.Update(m_elapsed);
}

void Game::Render() {
    m_window.BeginDraw();
// Render here.
    m_stateManager.Draw();
    m_textbox.Render(*m_window.GetRenderWindow());
    m_window.EndDraw();
}

void Game::LateUpdate() {
    m_stateManager.ProcessRequests();
    RestartClock();
}

Window* Game::GetWindow() { return &m_window; }