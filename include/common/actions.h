#include "common/game.h"

#ifndef ACTIONS_H
#define ACTIONS_H

/**
 * @struct Action
 * @brief Represents a player action.
 *
 * This struct represents an action that is done by player \link playerId \endlink,
 * at tick \link tick \endlink
 */
struct Action {
	const size_t MAX_ARGS = 8; /**< Max argument count. */
	const size_t MAX_ARGLEN = 16; /**< Max argument length. */

	/**
	 * @enum Action::Type
	 * @brief A enumeration of all action types.
	 */
	enum Type {
		MOVE,
		RELOAD,
		MEDKIT,
		GRENADE,
		FLASHBANG
	} actionType;
	
	/**
	 * @brief The player information at action invocation.
	 *
	 * This variable is recorded for validation and movement calculation purposes.
	 */
	const Game::PlayerInfo player;
	const int tick; /**< The tick at action invocation. */
	const int argc; /**< The number of arguments. */
	/**
	 * @brief Arguments stored as strings.
	 *
	 * The argument strings are parsed upon action invocation.
	 */
	const char argv[MAX_ARGS][MAX_ARGLEN + 1];

	/**
	 * @brief Action constructor that represents a MOVE action \link Type \endlink.
	 *
	 * @param playerId The id of the moving player.
	 * @param tick The tick of the MOVE action.
	 */
	Action(int playerId, int tick);
	
	/**
	 * @brief Action constructor that takes a command invocation.
	 *
	 * @param playerId The player that invoked the command.
	 * @param tick The tick when the command was invoked.
	 * @param command The command string.
	 */
	Action(int playerId, int tick, char* command);
};

#endif // ACTIONS_H
