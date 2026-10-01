#include <cassert>        // add near the top
#include "Point.h"        // add near the top
#include "Engine.h"

int main()
{
    // --- TEMPORARY Point self-check: delete after it passes ---
    assert(((Point{ 3, 4 } + Point{ 1, 2 }) == Point{ 4, 6 }));   // given operator+
    assert(((Point{ 5, 5 } - Point{ 1, 2 }) == Point{ 4, 3 }));   // YOUR operator-
    assert(((Point{ 3, 4 } *2) == Point{ 6, 8 }));     // given operator*
    assert((Point{ 0, 0 }.DistanceTo(Point{ 3, 4 }) > 4.99f));    // YOUR DistanceTo
    assert((Point{ 0, 0 }.DistanceTo(Point{ 3, 4 }) < 5.01f));    // (should be 5.0)
    // --- end TEMPORARY self-check ---

    Engine engine;
    engine.Run();
    return 0;
}