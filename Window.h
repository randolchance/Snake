//
// Created by dco on 7/22/18.
//

#ifndef SNAKE_WINDOW_H
#define SNAKE_WINDOW_H

#include <string>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

#include "EventManager.h"

class Window{
public:
    Window();
    Window(const std::string& l_title,const sf::Vector2u& l_size);
    ~Window();
    void BeginDraw(); // Clear the window.
    void EndDraw(); // Display the changes.
    void Update();
    bool IsDone();
    bool IsFullscreen();
    sf::Vector2u GetWindowSize();
    void ToggleFullscreen(EventDetails* l_details);
    void Draw(sf::Drawable& l_drawable);
    sf::RenderWindow* GetRenderWindow();

    bool IsFocused();
    EventManager* GetEventManager();
    void Close(EventDetails* l_details);
private:
    void Setup(const std::string& l_title, const sf::Vector2u& l_size);
    void Destroy();
    void Create();
    sf::RenderWindow m_window;
    sf::Vector2u m_windowSize;
    std::string m_windowTitle;
    bool m_isDone;
    bool m_isFullscreen;
    EventManager m_eventManager;
    bool m_isFocused;
};

#endif //SNAKE_WINDOW_H
