#include <SFML/Graphics.hpp>
#include "Game.h"

using namespace sf;
using namespace std;

int main()
{
    Game game;

    while (game.isRunning())
    {
        game.processInput();
        game.Update();
        game.lateUpdate();
        game.Draw();
        game.calculateDeltaTime();
    }
}