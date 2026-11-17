/** @file game.h
 *  @brief Class prototypes for various game components.
 *
 *	This file contains the Game namespace, along with the
 *	prototypes of different game objects: TickManager,
 *	World and Lobby.
 *
 *	@author Foxyy
 */

#include <cstdint>
#include "common/utils.h"
#include "common/actions.h"

#ifndef GAME_H
#define GAME_H

/**
 * @namespace Game
 * @brief The namespace that wraps all the prototypes of different game objects.
 */
namespace Game {

	/**
	 * @typedef tick_t int32_t
	 */
	using tick_t = int32_t;

	/**
	 * @namespace Tick
	 * @brief The namespace containing tick operations.
	 */
	namespace Tick {
		/**
		 * @typedef tickt int32_t;
		 */
		using tick_t = int32_t;

		const uint32_t rate = 60;

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

	/**
	 * @struct Field
	 * @brief Represents the game field. Contains a 2D-grid of cells
	 */
	struct Field {
		static const size_t MAX_ROWS = 200; /**< Max field rows. (height) */
		static const size_t MAX_COLS = 200; /**< Max field columns. (width) */
		
		const size_t rows; /**< Field rows. */
		const size_t cols; /**< Field cols. */

		/**
		 * @enum CellEnum
		 * @brief The enum type of each grid cells.
		 */
		enum CellEnum {
			EMPTY,
			PLAYER,
			OBSTACLE
		};
		
		CellEnum grid[MAX_ROWS][MAX_COLS]; /**< The grid data variable. */

		/**
		 * @brief \link Field \endlink constructor.
		 *
		 * @param rows The number of field rows.
		 * @param cols The number of field columns.
		 */
		Field(size_t rows, size_t cols);

		/**
		 * @brief Updates a grid cell with \p newType.
		 *
		 * @param coord The coordiate of the cell to update.
		 * @param newType The \link CellEnum \endlink type to replace \link grid[r][c] \endlink with.
		 */
		void updateCell(Coord<int> coord, CellEnum newType);
	};

	/**
	 * @struct PlayerInfo
	 * @brief Represents a player.
	 */
	struct PlayerInfo {
		static const size_t MAX_NAME_LEN = 16; /**< Max name length */

		int id; /**< The id of the player. */
		Coord<float> pos; /**< The position of the player. */
		Coord<float> velocity; /**< The velocity of the player. */
		char name[MAX_NAME_LEN + 1]; /**< The name of the player. */
		int health; /**< The health points of the player. */
		int armor; /**< The armor points of the player. */
		int medkits; /**< Remaining medkits of the player. */
		int grenades; /**< Remaining grenades of the player. */
		int flashbangs; /**< Remaining flashbangs of the player. */
	};

	/**
	 * @struct World
	 * @brief Represents the world state. Including the game field and player information.
	 */
	struct World {
		static const size_t MAX_PLAYERS = 8; /**< Max player count. */

		Field field; /**< Game field. */
		PlayerInfo playerList[MAX_PLAYERS]; /**< Player list. */

		/**
		 * @brief Updates \link playerList[playerId] \endlink with \p playerInfo.
		 *
		 * @param playerId The index of \link playerList \endlink to update.
		 * @param playerInfo The \link PlayerInfo \endlink to update the specified slot with.
		 */
		void updatePlayer(int playerId, const PlayerInfo& playerInfo);

		/**
		 * @brief Applies an action to the game world.
		 *
		 * @param action The action to apply.
		 */
		void applyAction(const Action& action);

		/**
		 * @brief Undoes an action that was applied to the game world.
		 *
		 * @param action The action to undo.
		 */
		void undoAction(const Action& action);
	};
}

#endif // GAME_H
