//
// Created by dco on 7/22/18.
//

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Window.h"
#include "EventManager.h"

Window::Window() { Setup("Window", sf::Vector2u(640,480)); }
Window::Window(const std::string& l_title, const sf::Vector2u& l_size) {
    Setup(l_title,l_size);
}

Window::~Window(){ Destroy(); }

void Window::Setup(const std::string& l_title, const sf::Vector2u& l_size) {
    m_windowTitle = l_title;
    m_windowSize = l_size;
    m_isFullscreen = false;
    m_isDone = false;
    m_isFocused = true; // Default value for focused flag.
    m_eventManager.AddCallback("Fullscreen_toggle", &Window::ToggleFullscreen, this);
    m_eventManager.AddCallback("Window_close", &Window::Close, this);
    Create();
}

void Window::Create() {
    sf::Uint32 style = (m_isFullscreen ? sf::Style::Fullscreen : sf::Style::Default);
    m_window.create({ m_windowSize.x, m_windowSize.y, 32 }, m_windowTitle, style);
}

void Window::Destroy() {
    m_window.close();
}

void Window::Update(){
    sf::Event event;
    while(m_window.pollEvent(event)){
        if (event.type == sf::Event::LostFocus){
            m_isFocused = false;
            m_eventManager.SetFocus(false);
        }
        else if (event.type == sf::Event::GainedFocus){
            m_isFocused = true;
            m_eventManager.SetFocus(true);
        }
        m_eventManager.HandleEvent(event);
    }
    m_eventManager.Update();
}

void Window::ToggleFullscreen(EventDetails* l_details) {
    m_isFullscreen = !m_isFullscreen;
    Destroy();
    Create();
}

void Window::BeginDraw(){ m_window.clear(sf::Color::Black); }
void Window::EndDraw(){ m_window.display(); }

bool Window::IsDone() { return m_isDone; }
bool Window::IsFullscreen() { return m_isFullscreen; }
sf::Vector2u Window::GetWindowSize() { return m_windowSize; }
void Window::Draw(sf::Drawable& l_drawable) {
    m_window.draw(l_drawable);
}

sf::RenderWindow* Window::GetRenderWindow() { return &m_window; }

void Window::Close(EventDetails* l_details = nullptr){ m_isDone = true; }

EventManager* Window::GetEventManager() { return &m_eventManager; }

