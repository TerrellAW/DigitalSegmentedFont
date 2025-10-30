#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/glyph.h"
#include "../include/utils.h"

/**
 * @brief Creates a new glyph with the given Unicode codepoint.
 *
 * Initializes the glyph with no segments and an advance width of 0.
 *
 * @param codepoint The Unicode codepoint representing the glyph. Cannot be 0.
 * @return A Glyph struct with initialized fields.
 */
Glyph glyph_create(uint32_t codepoint) {
	Glyph glyph;
	glyph.codepoint = codepoint;
	glyph.advance_width = 0;
	glyph.segments = NULL;
	glyph.segment_count = 0;
	return glyph;
}

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
int glyph_add_segment(Glyph* glyph, int x, int y, int size) {
	// Calculate new size
	size_t new_size = (glyph->segment_count + 1) * sizeof(Segment);

	// Input validation
	if (glyph != NULL && size > 0) {
		glyph->segments = safe_realloc(glyph->segments, new_size); // Allocate memory for Segment struct array
		glyph->segments[glyph->segment_count] = (Segment){x, y, size}; // Add Segment struct to array using compound literal
		glyph->segment_count++; // Increment count via pointer
		return 0; // Success
	} else {
		fprintf(stderr, "Invalid glyph or size in glyph_add_segment\n"); // Print to error output stream
		return -1; // Failure
	}
}

/**
 * @brief Computes the width between glyphs based on the glyph's segments.
 *
 * Calculates the right-most edge of all segments and returns the highest value with a padding of 1 pixel.
 *
 * @param glyph Pointer to the glyph whose advance width is being computed.
 * @return The computed advance width, or -1 if glyph is NULL.
 */
int compute_advance(Glyph* glyph) {
	if (!glyph) return -1;
	int x_max = 0; // Initialize empty variable for right-most x coordinate
	for (int i = 0; i < glyph->segment_count; i++) { // Iterate through segments of glyph
		int right_edge = glyph->segments[i].x + glyph->segments[i].size; // Find right edge of segment
		if (right_edge > x_max) { // Compare right edge of segment to highest x coord
			x_max = right_edge; // Set highest x coord to higher value
		}
	}
	return x_max + 1; // Return with padding
}

/**
 * @brief Frees the memory used by a glyph's segment array.
 *
 * Releases the dynamically allocated segment array and resets related fields.
 *
 * @param glyph Pointer to the glyph to clean up.
 */
void glyph_free(Glyph* glyph) {
	if (!glyph) return; // Check if glyph exists
	free(glyph->segments); // Release memory holding Segment structs
	glyph->segments = NULL; // Reset pointer
	glyph->segment_count = 0; // Reset count via pointer
}
