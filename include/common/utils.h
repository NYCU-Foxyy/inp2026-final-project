#ifndef UTILS_H
#define UTILS_H

/**
 * @struct Coord
 * @brief A utility struct for representing coordinates.
 *
 * This struct can be used whether on game field or screen.
 *
 * @tparam T The type of the coordinate.
 */
template<typename T>
struct Coord {
	T r; /**< The row of the coordinate. */
	T c; /**< The column of the coordinate. */

	/**
	 * @brief The constructor of \link Coord \endlink.
	 *
	 * @param r The row of the coordinate.
	 * @param c The column of the coordinate.
	 */
	Coord(T r, T c);
};

#endif // UTILS_H
