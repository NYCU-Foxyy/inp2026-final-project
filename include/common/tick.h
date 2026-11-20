/** @file tick.h
 *  @brief Prototypes for game tick functions.
 *
 *  @author Foxyy
 */

#ifndef TICK_H
#define TICK_H

#include <cstdint>
#include <functional>
#include <chrono>
#include <atomic>

namespace Game {

	/**
	 * @namespace Game::Tick
	 * @brief The namespace containing tick operations.
	 *
	 * This presents the interface of the game tick manager, on every tick update and
	 * at the beginning of ticking, the \link callback \endlink function is called.
	 * Developers should set their update function as the \link callback \endlink
	 * function, and handle other function calling from within said update function.
	 *
	 * A ticker thread will be spawned once ticking is started, and will be destroyed
	 * when ticking stops. Said ticker thread will spawn another thread to call \link
	 * callback \endlink on every \link _tick \endlink update, thus the caller should
	 * take multithreading measures when designing the callback function.
	 *
	 * \link _tick \endlink will always start from 0, and the \c time_point at the
	 * beginning of ticking will be recorded, every tick update will then be at
	 * (beginTime + tickInterval * n) where n >= 0.
	 */
	namespace Tick {
		/**
		 * @typedef tick_t int32_t;
		 */
		using tick_t = int32_t;

		const uint32_t rate = 64; /**< Tick rate, set to 64 for nice integer division. */
		const std::chrono::nanoseconds tickInterval(1000000000 / rate);
		
		extern std::atomic<bool> ticking; /**< Is ticking on? */

		/**
		 * @namespace <anonymous>
		 * @brief Local tick variable
		 */
		namespace {
			std::atomic<tick_t> _tick = 0; /**< Game tick. */
		}

		/**
		 * @brief Returns current game tick.
		 * 
		 * @return Current \link tick \endlink.
		 */ 
		tick_t getTick(void);

		/**
		 * @brief Starts ticking.
		 */
		void start(void);

		/**
		 * @brief Stops ticking.
		 */
		void stop(void);

		/**
		 * @brief Sets \link callback \endlink function.
		 *
		 * @param newCallback The new callback function to \link callback \endlink to.
		 */
		void setCallback(const std::function<void()>& newCallback);
	}
}

#endif // TICK_H
