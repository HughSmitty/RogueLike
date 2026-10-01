#ifndef POINT_H
#define POINT_H

// A 2D coordinate: a column (x) and a row (y). This is a "value type" - small,
// cheap to copy, and used all over the game. We keep it deliberately simple:
// it is just two numbers with some handy operations. No inheritance, nothing fancy.
struct Point
{
    int x{ 0 };
    int y{ 0 };

    constexpr Point() = default;
    constexpr Point(int x, int y) : x(x), y(y) {}

    float DistanceTo(const Point& target) const;

    Point operator+(const Point& rhs) const;
    Point operator-(const Point& rhs) const;
    Point operator/(int rhs) const;
    Point operator*(int rhs) const;
    bool  operator==(const Point& rhs) const;
    bool  operator!=(const Point& rhs) const { return !(*this == rhs); }

    static const Point Zero;
};

#endif // POINT_H