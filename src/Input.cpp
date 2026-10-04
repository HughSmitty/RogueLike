#include "Input.h"
#include <SDL3/SDL.h>
void Input::CheckForEvent()
{
	SDL_Event event{};
	// Put the game to sleep until SOMETHING happens (a key, the mouse, a window
	// close). This is what makes a roguelike turn-based: nothing moves until the
	// player acts. It is also kind to the laptop battery - no spinning in a loop.
	SDL_WaitEvent(nullptr);
	keyCode = 0; // forget last turn's key before reading this turn's events
	// Drain every event that is currently waiting.
	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_EVENT_QUIT)
		{
			quitRequested = true; // the player closed the window
		}
		else if (event.type == SDL_EVENT_KEY_DOWN)
		{
			keyCode = event.key.key; // remember which key
		}
	}
}
