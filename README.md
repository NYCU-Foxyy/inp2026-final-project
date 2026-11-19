# inp2026-final-project
Introduction to Network Programming 2026 Final Project

[Sketch Report Slides](https://canva.link/xulhx3u8qn2xseh)

# Group 7 Members
- [@NYCU-Foxyy](https://github.com/NYCU-Foxyy)
- [@Kate816](https://github.com/Kate816)
- [@lyhung9537](https://github.com/lyhung9537)

# Installation Steps
1. `cmake -B build`
2. `cmake --build build`
3. `cmake --install build`

The compiled programs (`client`, `server`) will be in `bin/`.

# Testing Tutorial
Lets say we are building a test script in `tests/common/game-tick.cpp`, which tests the tick manager in `include/common/tick.h`.
The main testing function should have the same name as the test script (where the dash is converted to a underscore), in this case: `int game_tick(int argc, char* argv[])`.
A non-zero return value of the test function represents a test fail, otherwise a zero return value represents a test success.

After writing the test script, an entry should be added in `TEST_PROG_LIST` of `tests/common/CMakeLists.txt`.

To run a full test, run `ctest --test-dir build` in project's root directory after the project has been built.

An example test (`game-tick`) is available for view in `tests`.

# Development Notes
- When adding a source file in `src/`, add its corresponding entry in the respective `CMakeLists.txt` in the source file's directory.

# Project Structure
(Under Construction)

# Issue Writing
- **Important**: create an issue whenever something pops up in your mind, so that you could spend less effort keeping track of all the tasks you have to do, plus breaking tasks down can help reduce the psychological load as completing a module can seem overwhelming.
- **Important**: do not use LLMs or any AI-generation tools to 'help' you write issues.
- The title should concisely and accurately represent the issue.
- Make sure to assign the priority field when creating issues, in order to prevent being occupied for prolonged periods of time on a single less-important task.

# AI assistance on development
AI assistance is not entirely prohibited, it is understable that working on a project can feel difficult or seem impossible at glance. However when utilizing such code generation tools, please keep the maintainability at an acceptable level for other co-developers. That means:
- Your code should be well-documented.
- You need to have a good understanding of your own code. As debugging will require multiple times the effort when the internal workings are unbeknownst to you. And you need to be able to provide a good explanation when inquired about your modules.

Lastly, you might miss out on the fun if you let your agent design everything!
