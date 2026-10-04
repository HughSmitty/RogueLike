#ifndef ENGINE_H
#define ENGINE_H

#include "libtcod.h"
#include "Point.h"
#include "Input.h"


class Engine
{

private:
    Point playerLocation{ 40, 25 };

public:
    Engine();
    ~Engine() = default;

    void Run();

private:
    void InitTcod();
    void HandleInput();
    void Update();
    void Render();

    tcod::Console console;
    tcod::Context context;
    int screenWidth;
    int screenHeight;
    bool running{ true };   // cleared to end the game loop cleanly (Lab 4)
    Input inputHandler;
};

#endif // ENGINE_H
