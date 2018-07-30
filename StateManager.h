//
// Created by dco on 7/25/18.
//

#ifndef SNAKE_STATEMANAGER_H
#define SNAKE_STATEMANAGER_H

#include <functional>
#include <unordered_map>
#include <vector>

#include "Window.h"


class BaseState;
class Textbox;

enum class StateType {
    Intro = 1, MainMenu, Game, Paused, GameOver, Credits
};

struct SharedContext {
    SharedContext(): m_wind(nullptr), m_eventManager(nullptr), m_textbox(nullptr) { }
    Window* m_wind;
    EventManager* m_eventManager;
    Textbox* m_textbox;
};

using StateContainer = std::vector<std::pair<StateType, BaseState*> >;

using TypeContainer = std::vector<StateType>;

using StateFactory = std::unordered_map<StateType, std::function<BaseState*(void)>, EnumClassHash>;

class StateManager {
public:
    explicit StateManager(SharedContext* l_shared);
    ~StateManager();
    void Update(const sf::Time& l_time);
    void Draw();
    void ProcessRequests();
    SharedContext* GetContext();
    bool HasState(const StateType& l_type);
    void SwitchTo(const StateType& l_type);
    void Remove(const StateType& l_type);
private:
// Methods.
    void CreateState(const StateType& l_type);
    void RemoveState(const StateType& l_type);
    template<class T>
    void RegisterState(const StateType& l_type) {
        m_stateFactory[l_type] = [this]() -> BaseState* {
            return new T(this);
        };
    }
// Members.
    SharedContext* m_shared;
    StateContainer m_states;
    TypeContainer m_toRemove;
    StateFactory m_stateFactory;
};



#endif //SNAKE_STATEMANAGER_H
