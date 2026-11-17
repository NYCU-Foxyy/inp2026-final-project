#ifndef UTILS_H
#define UTILS_H

/**
 * @struct Coord
 * @brief A utility struct for representing coordinates.
 *
 * This struct can be used whether on game field or screen.
 */
struct Coord {
	int r; /**< The row of the coordinate. */
	int c; /**< The column of the coordinate. */

	/**
	 * @brief The constructor of \link Coord \endlink.
	 *
	 * @param r The row of the coordinate.
	 * @param c The column of the coordinate.
	 */
	Coord(int r, int c);
};

#endif // UTILS_H
