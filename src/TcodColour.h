#ifndef TCODCOLOUR_H
#define TCODCOLOUR_H

#include "libtcod.h"
#include "Colours.h"

// The ONE place that knows both our Colour and libtcod's colour types.
// Drawing code converts here, at the boundary, so the rest of the game never
// has to mention a libtcod colour.

inline tcod::ColorRGB ToTcod(const Colour& c)
{
    return tcod::ColorRGB{ c.r, c.g, c.b };
}

inline TCOD_ColorRGBA ToTcodA(const Colour& c)
{
    return TCOD_ColorRGBA{ c.r, c.g, c.b, 255 };   // 255 = fully opaque
}

#endif // TCODCOLOUR_H