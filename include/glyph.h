// Include Guard, prevents compilation errors
#ifndef GLYPH_H
#define GLYPH_H

// Standard Libraries
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

/**
 * @brief Represents a segment of a glyph.
 * 
 * Stores the coordinates and size of the segment.
 */
typedef struct {
	// Coordinates
	int x;
	int y;

	// Size of square
	int size;
} Segment;

/**
 * @brief Represents a glyph of the font.
 * 
 * Stores the Unicode codepoint, width of space between glyphs,
 * and a list of square segments that make up the glyph's shape.
 */
typedef struct {
	// Unicode value
	uint32_t codepoint;
	
	// Distance to move cursor after drawing glyph
	int advance_width;

	// Dynamic array of square segments
	Segment* segments;

	// Amount of square segments
	size_t segment_count;
} Glyph;

// Glyph API
/**
 * @brief Creates a new glyph with the given Unicode codepoint.
 *
 * Initializes the glyph with no segments and an advance width of 0.
 *
 * @param codepoint The Unicode codepoint representing the glyph. Cannot be 0.
 * @return A Glyph struct with initialized fields.
 */
Glyph glyph_create(uint32_t codepoint); 

/**
 * @brief Adds a square segment to the glyph.
 *
 * Dynamically resizes the segment array and appends a new segment of the specified size at the specified (x,y) coordinates.
 *
 * @param glyph Pointer to the glyph to modify.
 * @param x X-coordinate of the new segment. Must be a valid integer.
 * @param y Y-coordinate of the new segment. Must be a valid integer.
 * @param size Width/Height of the square segment. Must be a valid integer.
 * @return 0 on success, -1 if glyph is NULL or size is 0 or less.
 */
int glyph_add_segment(Glyph* glyph, int x, int y, int size); 

/**
 * @brief Adds a 3x3 segment to the glyph at the specified grid position.
 * 
 * Automatically converts grid coordinates to pixel coordinates with 1-pixel gaps.
 * Each grid position is 4 units apart (3-unit segment + 1-unit gap).
 * 
 * @param glyph Pointer to the glyph to modify.
 * @param grid_x Grid column position. Converted to pixel_x.
 * @param grid_y Grid row position. Converted to pixel_y.
 * @return 0 on success, -1 if the glyph is NULL or the segment addition fails.
 */
int glyph_add_block(Glyph* glyph, int grid_x, int grid_y);

/**
 * @brief Computes the width between glyphs based on the glyph's segments.
 *
 * Calculates the right-most edge of all segments and returns the highest value with a padding of 1 pixel.
 *
 * @param glyph Pointer to the glyph whose advance width is being computed.
 * @return The computed advance width, or -1 if glyph is NULL.
 */
int compute_advance(Glyph* glyph);

/**
 * @brief Frees the memory used by a glyph's segment array.
 *
 * Releases the dynamically allocated segment array and resets related fields.
 *
 * @param glyph Pointer to the glyph to clean up.
 */
void glyph_free(Glyph* glyph); 

/**
 * @brief Prints output to the terminal for debugging.
 */
void glyph_debug_print(Glyph* glyph);

/**
 * @brief Prints output in the form of a string of characters to the terminal for debugging.
 */
void glyph_debug_print_string(const char* str);

#endif // Closes GLYPH_H include guard
