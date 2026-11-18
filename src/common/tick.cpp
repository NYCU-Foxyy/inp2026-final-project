#include "common/tick.h"
#include <thread>
#include <chrono>
#include <atomic>

namespace Game {
	namespace Tick {
		std::atomic<bool> ticking = false;

		std::function<void()> callback;
		std::chrono::time_point<std::chrono::steady_clock, std::chrono::nanoseconds> nextUpd;

		void tickLoop() {
			while (ticking) {
				std::thread run(Game::Tick::callback);
				run.detach();
				_tick = _tick + 1;
				nextUpd += Game::Tick::tickInterval;
		
				std::this_thread::sleep_until(nextUpd);
			}
		}

		tick_t getTick(void) {
			return _tick;
		}

		void start(void) {
			if (ticking) return;
			ticking = true;
			nextUpd = std::chrono::steady_clock::now();
			std::thread run(tickLoop);
			run.detach();
		}

		void stop(void) {
			ticking = false;
		}

		void setCallback(const std::function<void()>& newCallback) {
			callback = newCallback;
		}
	}
}
