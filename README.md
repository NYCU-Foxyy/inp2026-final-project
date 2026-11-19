# inp2026-final-project
Introduction to Network Programming 2026 Final Project

[Sketch Report Slides](https://canva.link/xulhx3u8qn2xseh)

## Group 7 Members
- [@NYCU-Foxyy](https://github.com/NYCU-Foxyy)
- [@Kate816](https://github.com/Kate816)
- [@lyhung9537](https://github.com/lyhung9537)

## Installation Steps
1. `cmake -B build`
2. `cmake --build build`
3. `cmake --install build`

The compiled programs (`client`, `server`) will be in `bin/`.

## Testing Tutorial
Lets say we are building a test script in `tests/common/game-tick.cpp`, which tests the tick manager in `include/common/tick.h`.
The main testing function should have the same name as the test script (where the dash is converted to a underscore), in this case: `int game_tick(int argc, char* argv[])`.
A non-zero return value of the test function represents a test fail, otherwise a zero return value represents a test success.

After writing the test script, an entry should be added in `TEST_PROG_LIST` of `tests/common/CMakeLists.txt`.

To run a full test, run `ctest --test-dir build` in project's root directory after the project has been built.

An example test (`game-tick`) is available for view in `tests`.

## Development Notes
- When adding a source file in `src/`, add its corresponding entry in the respective `CMakeLists.txt` in the source file's directory.

## Project Structure
(Under Construction)
