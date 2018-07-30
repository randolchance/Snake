//
// Created by dco on 7/25/18.
//

#ifndef SNAKE_STATE_INTRO_H
#define SNAKE_STATE_INTRO_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "BaseState.h"

class EventDetails;

class State_Intro : public BaseState {
public:
    explicit State_Intro(StateManager*);
    void OnCreate() override;
    void OnDestroy() override;
    void Activate() override;
    void Deactivate() override;
    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void Continue(EventDetails* l_details = nullptr);
private:
    sf::Texture m_introTexture;
    sf::Sprite m_introSprite;
    sf::Text m_text;
    sf::Font m_font;
    float m_timePassed;
};

#endif //SNAKE_STATE_INTRO_H
