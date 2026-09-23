#include "Engine.h"
#include "SDL3/SDL.h"

constexpr int WINDOW_WIDTH{ 80 };
constexpr int WINDOW_HEIGHT{ 50 };

Engine::Engine() : screenWidth(WINDOW_WIDTH), screenHeight(WINDOW_HEIGHT)
{
    InitTcod();
}

void Engine::Run()
{
    // Our traditional game loop. `while (running)` - not `while (true)` - so the
    // game can be asked to stop and shut down cleanly (see Lab 4).
    while (running)
    {
        HandleInput();
        Update();
        Render();
        context.present(console);
    }
}

void Engine::InitTcod()
{
    console = tcod::Console{ screenWidth, screenHeight };  // Main console.
    auto tileset = tcod::load_tilesheet("dejavu32x8.png", { 32, 8 }, tcod::CHARMAP_TCOD);

    TCOD_ContextParams params{};
    params.console = console.get();
    params.tcod_version = TCOD_COMPILEDVERSION;
    params.columns = screenWidth;
    params.rows = screenHeight;
    params.tileset = tileset.get();
    params.window_title = "Roguelike";
    params.vsync = 1;
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    context = tcod::Context(params);
}

void Engine::HandleInput()
{
    // Nothing yet - fleshed out in Lab 4, when we add the Input class.
    // (For now the game responds only to Visual Studio's Stop button; Lab 4
    //  makes the window's close button work.)
}

void Engine::Render()
{
    console.clear();

    console.at(40, 25).ch = '@';
    console.at(40, 25).fg = tcod::ColorRGB{ 255, 255, 255 };
}

void Engine::Update()
{
    // Nothing here yet. This method runs every turn.
}
