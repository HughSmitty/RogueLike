#include "Engine.h"
#include "SDL3/SDL.h"
#include "Colours.h"
#include "TcodColour.h"

constexpr int WINDOW_WIDTH{ 80 };
constexpr int WINDOW_HEIGHT{ 50 };

void Engine::Render()
{
    console.clear();
    console.at(playerLocation.x, playerLocation.y).ch = '@';
    console.at(playerLocation.x, playerLocation.y).fg = ToTcodA(White);
}





Engine::Engine() : screenWidth(WINDOW_WIDTH), screenHeight(WINDOW_HEIGHT)
{
    InitTcod();
}

void Engine::Run()
{
    while (running)
    {
        HandleInput();
        if (inputHandler.IsQuitRequested()) // player closed the window
        {
            running = false;
        }
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
    params.window_title = "Children Of The Sun";
    params.vsync = 1;
    params.sdl_window_flags = SDL_WINDOW_RESIZABLE;
    context = tcod::Context(params);
}

void Engine::HandleInput()
{
    inputHandler.CheckForEvent();
}


void Engine::Update()
{
    // Turn the arrow key into a direction to step in.
    Point delta{ Point::Zero };
    switch (inputHandler.GetKeyCode())
    {
    case SDLK_UP:
        delta = { 0, -1 }; // up is one row less
        break;
    case SDLK_DOWN:
        delta = { 0, 1 };
        break;
    case SDLK_LEFT:
        delta = { -1, 0 };
        break;
    case SDLK_RIGHT:
        delta = { 1, 0 };
        break;
    default:
        break; // any other key: no movement
    }
    Point newLocation{ playerLocation + delta }; // <-- Point's operator+, from

    bool inBounds{ newLocation.x >= 0 && newLocation.x < screenWidth && newLocation.y >= 0 && newLocation.y < screenHeight };

        if (inBounds)
        {
            playerLocation = newLocation;
        }
}

