#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Window.h"
#include "World.h"
#include "Snake.h"

int main(int argc, void** argv[]){
    // Program entry point.
    Game game; // Creating our game object.

    while(!game.GetWindow()->IsDone()){
    // Game loop.
        //game.HandleInput();
        game.Update();
        game.Render();
        game.RestartClock(); // Restarting our clock.
    }

    return 0;
}