//
// Created by dco on 7/29/18.
//

#ifndef SNAKE_STATE_CREDITS_H
#define SNAKE_STATE_CREDITS_H

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "BaseState.h"

class EventDetails;

class State_Credits : public BaseState {
public:
    explicit State_Credits(StateManager*);
    void OnCreate() override;
    void OnDestroy() override;
    void Activate() override;
    void Deactivate() override;
    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void Close(EventDetails* l_details);
private:
    sf::Text m_text;
    sf::Font m_font;
    float m_timePassed;
};


#endif //SNAKE_STATE_CREDITS_H
