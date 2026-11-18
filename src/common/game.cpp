#include "common/game.h"

namespace Game {
	namespace Tick {
		tick_t getTick(void) {
			return _tick;
		}
		
		void setTick(tick_t newTick) {
			_tick = newTick;
		}

		void tick() {
			_tick = _tick + 1;
		}
	}
}
