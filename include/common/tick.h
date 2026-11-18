/** @file tick.h
 *  @brief Prototypes for game tick functions.
 *
 *  @author Foxyy
 */

#ifndef TICK_H
#define TICK_H

#include <cstdint>

namespace Game {

	/**
	 * @namespace Tick
	 * @brief The namespace containing tick operations.
	 */
	namespace Tick {
		/**
		 * @typedef tickt int32_t;
		 */
		using tick_t = int32_t;

		const uint32_t rate = 64;

		/**
		 * @namespace <anonymous>
		 * @brief Local tick variable
		 */
		namespace {
			tick_t _tick; /**< Game tick. */
		}

		/**
		 * @brief Returns current game tick.
		 * 
		 * @return Current \link tick \endlink.
		 */ 
		tick_t getTick(void);
		
		/**
		 * @brief Sets @var tick to @p newTick.
		 *
		 * @param newTick The new game tick value to set @var tick to.
		 */
		void setTick(tick_t newTick);

		/**
		 * @brief Ticks the game by 1.
		 */
		void tick(void);
	}
}

#endif // TICK_H
