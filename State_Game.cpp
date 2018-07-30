//
// Created by dco on 7/26/18.
//
#include "State_Game.h"

#include "Window.h"
#include "StateManager.h"
#include "Textbox.h"

State_Game::State_Game(StateManager* l_stateManager): BaseState(l_stateManager),
                                                      m_snake(m_world.GetBlockSize(),15),
                                                      m_world(sf::Vector2u(800,600)),
                                                      m_textboxHidden(false) { }

void State_Game::OnCreate() {
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Game, "Key_Escape", &State_Game::MainMenu, this);
    evMgr->AddCallback(StateType::Game, "Key_P", &State_Game::Pause, this);
    evMgr->AddCallback(StateType::Game, "MoveLeft", &State_Game::MoveLeft, this);
    evMgr->AddCallback(StateType::Game, "MoveRight", &State_Game::MoveRight, this);
    evMgr->AddCallback(StateType::Game, "MoveUp", &State_Game::MoveUp, this);
    evMgr->AddCallback(StateType::Game, "MoveDown", &State_Game::MoveDown, this);
    evMgr->AddCallback(StateType::Game, "Key_Tab", &State_Game::ToggleTextbox, this);

    m_stateMgr->GetContext()->m_textbox->SetHidden(m_textboxHidden);
}

void State_Game::OnDestroy() {
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Game,"Key_Escape");
    evMgr->RemoveCallback(StateType::Game,"Key_P");
    evMgr->RemoveCallback(StateType::Game,"MoveLeft");
    evMgr->RemoveCallback(StateType::Game,"MoveRight");
    evMgr->RemoveCallback(StateType::Game,"MoveUp");
    evMgr->RemoveCallback(StateType::Game,"MoveDown");
    evMgr->RemoveCallback(StateType::Game,"Key_Tab");
}

void State_Game::Update(const sf::Time& l_time) {
    auto time_lapse = l_time - m_time;
    Textbox* textbox = m_stateMgr->GetContext()->m_textbox;
    float step = 1.0f / m_snake.GetSpeed();
    sf::Time time_step = sf::seconds(step);
    if (time_lapse >= time_step) {
        m_time = l_time;
        m_snake.Tick();
        m_world.Update(m_snake);
        if (m_world.isAppleEaten()) {
            textbox->Add("You ate an apple! You feel longer!");
            textbox->Add(std::to_string(m_snake.GetScore()) + " pts");
        } else if (m_snake.WasBit()) {
            textbox->Add("You bit your tail off!");
            m_snake.ResetBit();
        }
        if(m_snake.HasLost()) {
            textbox->Clear();
            textbox->Add("You heckin' died!");
            m_snake.Reset();
        }
    }
}

void State_Game::Draw() {
    auto l_renderWindow = m_stateMgr->GetContext()->m_wind->GetRenderWindow();

    m_world.Render(*l_renderWindow);
    m_snake.Render(*l_renderWindow);
}

void State_Game::MainMenu(EventDetails* l_details) {
    m_stateMgr->SwitchTo(StateType::MainMenu);
}
void State_Game::Pause(EventDetails* l_details) {
    m_stateMgr->SwitchTo(StateType::Paused);
}
void State_Game::MoveLeft(EventDetails* l_details) {
    if (m_snake.GetPhysicalDirection() != Direction::Right) m_snake.SetDirection(Direction::Left);
}
void State_Game::MoveRight(EventDetails* l_details) {
    if (m_snake.GetPhysicalDirection() != Direction::Left) m_snake.SetDirection(Direction::Right);
}
void State_Game::MoveUp(EventDetails* l_details) {
    if (m_snake.GetPhysicalDirection() != Direction::Down) m_snake.SetDirection(Direction::Up);
}
void State_Game::MoveDown(EventDetails* l_details) {
    if (m_snake.GetPhysicalDirection() != Direction::Up) m_snake.SetDirection(Direction::Down);
}
void State_Game::ToggleTextbox(EventDetails* l_details) {
    m_stateMgr->GetContext()->m_textbox->ToggleHidden();
    m_textboxHidden = m_stateMgr->GetContext()->m_textbox->IsHidden();
}

void State_Game::Activate() { m_stateMgr->GetContext()->m_textbox->SetHidden(m_textboxHidden); }
void State_Game::Deactivate() { m_stateMgr->GetContext()->m_textbox->SetHidden(true); }