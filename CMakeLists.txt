cmake_minimum_required (VERSION 4.0)

# --------------------------------------------------------------------------
# Toolchain: use the bundled vcpkg submodule to fetch SDL3, libtcod, Catch2.
# --------------------------------------------------------------------------
if(NOT DEFINED CMAKE_TOOLCHAIN_FILE)
    set(CMAKE_TOOLCHAIN_FILE
        "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake"
        CACHE STRING "Vcpkg toolchain file")
endif()

project(
    roguelike
    LANGUAGES C CXX
)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")

# The whole project targets C++20 (the endpoint uses std::format, std::ranges,
# std::erase_if, designated initialisers, ...). Set it once, everywhere, below.
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --------------------------------------------------------------------------
# Dependencies (installed by vcpkg from vcpkg.json).
# --------------------------------------------------------------------------
find_package(SDL3 CONFIG REQUIRED)
find_package(libtcod CONFIG REQUIRED)
find_package(Catch2 3 CONFIG REQUIRED)

# --------------------------------------------------------------------------
# Shared warning / encoding settings, applied to every target we build.
# --------------------------------------------------------------------------
function(apply_project_options target)
    target_compile_features(${target} PRIVATE cxx_std_20)
    if (MSVC)
        target_compile_options(${target} PRIVATE /utf-8 /W4)
    else()
        target_compile_options(${target} PRIVATE -Wall -Wextra)
    endif()
endfunction()

# --------------------------------------------------------------------------
# 1) The game code as a STATIC LIBRARY.
#
#    Everything under src/ EXCEPT main.cpp (and the tests/ folder) is compiled
#    once into roguelike_lib. Both the game and the test runner then link this
#    one library, so the game code is built a single time and shared.
#
#    Because of GLOB_RECURSE + CONFIGURE_DEPENDS, any .cpp/.h you add under src/
#    is picked up automatically on the next build - you never edit this file.
# --------------------------------------------------------------------------
file(
    GLOB_RECURSE LIB_SOURCES
    CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/src/*.cpp
    ${PROJECT_SOURCE_DIR}/src/*.h
)
# main.cpp belongs to the executable, not the library (only one main() allowed).
list(FILTER LIB_SOURCES EXCLUDE REGEX ".*/main\\.cpp$")

add_library(roguelike_lib STATIC ${LIB_SOURCES})
apply_project_options(roguelike_lib)
# PUBLIC: anything linking the library also gets these headers + libs.
target_include_directories(roguelike_lib PUBLIC ${PROJECT_SOURCE_DIR}/src)
target_link_libraries(roguelike_lib PUBLIC SDL3::SDL3 libtcod::libtcod)

# --------------------------------------------------------------------------
# 2) The game executable: just main.cpp, linked against the library.
# --------------------------------------------------------------------------
add_executable(roguelike ${PROJECT_SOURCE_DIR}/src/main.cpp)
apply_project_options(roguelike)
target_link_libraries(roguelike PRIVATE roguelike_lib)

# --------------------------------------------------------------------------
# 3) The test runner: everything under tests/, linked against the SAME library
#    plus Catch2's supplied main(). Dormant until Lab 10 - it simply has no
#    test files to run before then.
#
#    To run the tests in Visual Studio: right-click the `tests` project ->
#    "Set as Startup Project", then run. Switch back to `roguelike` to play.
# --------------------------------------------------------------------------
file(
    GLOB_RECURSE TEST_SOURCES
    CONFIGURE_DEPENDS
    ${PROJECT_SOURCE_DIR}/tests/*.cpp
)

add_executable(tests ${TEST_SOURCES})
apply_project_options(tests)
target_link_libraries(tests PRIVATE roguelike_lib Catch2::Catch2WithMain)

# Register Catch2 tests with CTest, so a CI job can run them headlessly.
include(CTest)
include(Catch)
catch_discover_tests(tests)
