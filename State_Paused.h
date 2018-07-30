//
// Created by dco on 7/26/18.
//

#ifndef SNAKE_STATE_PAUSED_H
#define SNAKE_STATE_PAUSED_H
#include "BaseState.h"

class EventDetails;

class State_Paused : public BaseState {
public:
    explicit State_Paused(StateManager*);
    void OnCreate() override;
    void OnDestroy() override;
    void Activate() override;
    void Deactivate() override;
    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void Unpause(EventDetails* l_details = nullptr);
private:
    sf::Text m_text;
    sf::RectangleShape m_rect;
    sf::Font m_font;
};

#endif //SNAKE_STATE_PAUSED_H
