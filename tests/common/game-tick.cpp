#include "common/tick.h"
#include <chrono>
#include <thread>
#include <mutex>

using namespace std::chrono_literals;

int counter = 0;
std::mutex counterMutex;

void update() {
	counterMutex.lock();
	counter++;
	counterMutex.unlock();
}

int game_tick(int argc, char* argv[]) {
	if (Game::Tick::ticking)
		return 1;

	Game::Tick::setCallback(update);
	Game::Tick::start();
	std::this_thread::sleep_for(1000ms);
	if (counter != Game::Tick::rate + 1)
		return 1;

	Game::Tick::stop();
	if (Game::Tick::getTick() != Game::Tick::rate + 1)
		return 1;
	if (Game::Tick::ticking)
		return 1;

	return 0;
}
