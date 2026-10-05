#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "Point.h"
// A TEST_CASE has a name that says what it checks, and one or more REQUIRE
// checks inside it. If a REQUIRE is false, that test fails and Catch2 tells
// you exactly where and why.
TEST_CASE("Addition adds both coordinates")
{
	Point sum{ Point{ 3, 4 } + Point{ 1, 2 } };
	REQUIRE(sum.x == 4);
	REQUIRE(sum.y == 6);
}
TEST_CASE("Distance across a 3-4-5 triangle is 5")
{
	REQUIRE(Point{ 0, 0 }.DistanceTo(Point{ 3, 4 }) == Catch::Approx(5.0f));
}

TEST_CASE("Equality compares both coordinates")
{
	REQUIRE(Point{ 2, 7 } == Point{ 2, 7 });
	REQUIRE_FALSE(Point{ 2, 7 } == Point{ 2, 8 });
}

TEST_CASE("Subtraction subs both coordinates")
{
	Point sum{ Point{ 5, 5 } - Point{ 1, 2 } };
	REQUIRE(sum.x == 4);
	REQUIRE(sum.y == 3);
}

TEST_CASE("Multipliction multiplies player's coordinates by 2")
{
	Point sum{ Point{ 3, 4 } * 2 };
	REQUIRE(sum.x == 6);
	REQUIRE(sum.y == 8);
}

TEST_CASE("Division divides player's coordinates by 2")
{
	Point sum{ Point{ 6, 8 } / 2};
	REQUIRE(sum.x == 3);
	REQUIRE(sum.y == 4);
}

TEST_CASE("A straight-line distance")
{
	REQUIRE(Point{ 0, 0 }.DistanceTo(Point{ 0, 10 }) == 10);
}

TEST_CASE("A diagonal distance")
{
	REQUIRE(Point{ 0, 0 }.DistanceTo(Point{ 1, 1 }) == Catch::Approx(1.41421356f));
}
