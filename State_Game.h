//
// Created by dco on 7/26/18.
//

#ifndef SNAKE_STATE_GAME_H
#define SNAKE_STATE_GAME_H

#include "BaseState.h"
#include "Snake.h"
#include "World.h"

class EventDetails;

class State_Game : public BaseState{
public:
    State_Game(StateManager*);
    void OnCreate() override;
    void OnDestroy() override;
    void Activate() override;
    void Deactivate() override;
    void Update(const sf::Time& l_time) override;
    void Draw() override;

    void MainMenu(EventDetails* l_details = nullptr);
    void Pause(EventDetails* l_details = nullptr);
    void MoveLeft(EventDetails* = nullptr);
    void MoveRight(EventDetails* = nullptr);
    void MoveUp(EventDetails* = nullptr);
    void MoveDown(EventDetails* = nullptr);
    void ToggleTextbox(EventDetails* = nullptr);
private:
    World m_world;
    Snake m_snake;
    sf::Time m_time;
    bool m_textboxHidden;
};

#endif //SNAKE_STATE_GAME_H
