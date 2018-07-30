//
// Created by dco on 7/29/18.
// Original source for this Snake game project can be found in the text
// 'SFML Game Development by Example' by Raimondas Pupius and published
// through Packt Publishing. All trademarks and copyrights belong to
// their respective owners.
//

#include "State_Credits.h"

#include "Window.h"
#include "StateManager.h"

State_Credits::State_Credits(StateManager* l_stateManager): BaseState(l_stateManager) { }

void State_Credits::OnCreate() {
    m_timePassed = 0.0f;
    sf::Vector2u windowSize = m_stateMgr->GetContext()->m_wind->GetRenderWindow()->getSize();
    m_font.loadFromFile("arial.ttf");
    m_text.setFont(m_font);
    m_text.setString({ "The very first 'Snake' game, according to Wikipedia, originated in 1976.\n\n"
                       "Then called 'Blockade', the game featured two-player action with each player\n"
                       "creating a wall behind them as they moved on the screen. The goal, naturally,\n"
                       "was to out-think and out-maneuver your opponent to cause them to crash\n"
                       "their player into a wall.\n\n"
                       "'Snake' (aka 'Blockade') evolved into many forms over the years, and has an\n"
                       "interesting and colourful history that Wikipedia - as far as I know - does\n"
                       "complete and utter justice. Head there to learn more!\n\n"
                       "Considering the immutable historical fact this game is decades old and its\n"
                       "evolution is well documented, it would be absolute folly of me to attempt\n"
                       "to take credit for the game. In fact I didn't even design the bulk of it;\n"
                       "this project comes from a good text on C++ game design called\n\n"
                       "'SFML Game Development by Example'\n\n"
                       "Whomever this Example person is, they've done fine work. And it is their fine\n"
                       "work that you see here, with only a few modifications and additions made\n"
                       "by myself.\n\n"
                       "All trademarks and copyrights related to 'Snake' (and its kin) are the\n"
                       "property of their respective owners.\n\n"
                       "Press SPACE to continue"
    });
    m_text.setCharacterSize(15);
    m_text.setColor(sf::Color::White);
    sf::FloatRect textRect = m_text.getLocalBounds();
    m_text.setOrigin(textRect.left + textRect.width / 2.0f, textRect.top + textRect.height / 2.0f);
    m_text.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->AddCallback(StateType::Credits, "Credits_Close", &State_Credits::Close, this);
}

void State_Credits::OnDestroy() {
    EventManager* evMgr = m_stateMgr->GetContext()->m_eventManager;
    evMgr->RemoveCallback(StateType::Credits,"Credits_Close");
}

void State_Credits::Update(const sf::Time& l_time) {
    m_timePassed += l_time.asSeconds();
}

void State_Credits::Draw() {
    sf::RenderWindow* window = m_stateMgr->GetContext()->m_wind->GetRenderWindow();
    if(m_timePassed >= 5.0f) {
        window->draw(m_text);
    }
}

void State_Credits::Close(EventDetails* l_details) {
    if(m_timePassed >= 5.0f) {
        m_stateMgr->SwitchTo(StateType::MainMenu);
        m_stateMgr->Remove(StateType::Credits);
    }
}

void State_Credits::Activate() { }
void State_Credits::Deactivate() { }