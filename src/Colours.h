#ifndef COLOURS_H
#define COLOURS_H

#include <cstdint>

// Our own colour type: just three numbers - red, green, blue - each 0 to 255.
// Notice it knows NOTHING about libtcod. That is deliberate (see TcodColour.h).
struct Colour
{
    std::uint8_t r{ 0 };
    std::uint8_t g{ 0 };
    std::uint8_t b{ 0 };
};

// The palette. We will add more colours to this list in later labs.
constexpr Colour White{ 255, 255, 255 };
constexpr Colour Black{ 0, 0, 0 };
constexpr Colour Red{ 191, 0, 0 };
constexpr Colour Yellow{ 255, 255, 0 };
constexpr Colour LightGrey{ 159, 159, 159 };
constexpr Colour DesaturatedGreen{ 63, 127, 63 };
constexpr Colour Violet{ 127, 0, 255 };
constexpr Colour Cyan{ 0, 255, 255 };

#endif // COLOURS_H