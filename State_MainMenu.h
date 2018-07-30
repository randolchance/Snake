//
// Created by dco on 7/26/18.
//

#ifndef SNAKE_STATE_MAINMENU_H
#define SNAKE_STATE_MAINMENU_H
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "BaseState.h"

class EventDetails;

class State_MainMenu : public BaseState {
public:
    explicit State_MainMenu(StateManager*);
    void OnCreate() override;
    void OnDestroy() override;
    void Activate() override;
    void Deactivate() override;
    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void MouseClick(EventDetails* l_details);
private:
    sf::Text m_text;
    sf::Vector2f m_buttonSize;
    sf::Vector2f m_buttonPos;
    unsigned int m_buttonPadding;
    sf::RectangleShape m_rects[3];
    sf::Text m_labels[3];
    sf::Font m_font;
};


#endif //SNAKE_STATE_MAINMENU_H
