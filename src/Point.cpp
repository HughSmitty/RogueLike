#include "Point.h"
#include <cmath>

// The origin, {0, 0}. Defined once, here.
const Point Point::Zero{ 0, 0 };

// ---------- Worked examples: study these ----------

Point Point::operator+(const Point& rhs) const
{
    return { x + rhs.x, y + rhs.y }; // 
}

Point Point::operator*(int rhs) const
{
    return { x * rhs, y * rhs };
}

Point Point::operator/(int rhs) const
{
    return { x / rhs, y / rhs };
}

bool Point::operator==(const Point& rhs) const
{
    return x == rhs.x && y == rhs.y;
}

Point Point::operator-(const Point& rhs) const
{
    return { x - rhs.x, y - rhs.y }; // my one
}


float Point::DistanceTo(const Point& target) const
{
    int dx = x - target.x; //x gets the targets x
    int dy = y - target.y; //y gets the targets y
    return std::sqrt( static_cast<float>((dx * dx) + ( dy * dy)));
}