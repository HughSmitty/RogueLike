#ifndef INPUT_H
#define INPUT_H

// Reads the keyboard (and, later, the mouse) each turn. Notice: this header
// mentions no SDL and no libtcod at all - all of that lives in Input.cpp. The
// rest of the game can use Input without dragging those libraries in.
class Input
{


public:
	// Call once per turn, before Update(). Waits for the next event, then reads
	// every event currently waiting.
	void CheckForEvent();
	// The key pressed this turn (0 if none). "const" because asking does not
	// change anything.
	unsigned int GetKeyCode() const { return keyCode; }
	// Did the player close the window? Sticky: once true, it stays true.
	bool IsQuitRequested() const { return quitRequested; }
private:
	unsigned int keyCode{ 0 };
	bool quitRequested{ false };
};
#endif // INPUT_H