#include "common/tick.h"

int game_tick(int argc, char* argv[]) {
	Game::Tick::setTick(-3);
	if (Game::Tick::getTick() != -3) return 1;

	Game::Tick::tick();
	if (Game::Tick::getTick() != -2) return 1;

	Game::Tick::tick();
	Game::Tick::tick();
	Game::Tick::tick();
	if (Game::Tick::getTick() != 1) return 1;

	return 0;
}
