// A single trivial test so the `tests` target compiles and runs from day one,
// before any real tests exist. Lab 10 is where real tests start arriving here.
// You can delete this once PointTests.cpp (or similar) exists.
#include <catch2/catch_test_macros.hpp>

TEST_CASE("the test runner itself works")
{
    REQUIRE(1 + 1 == 2);
}
