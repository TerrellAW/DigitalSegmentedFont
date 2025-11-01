// Include Guard, prevents compilation errors
#ifndef FONT_H
#define FONT_H

// Standard Library
#include <stddef.h>
#include <stdio.h>

// Glyph Header
#include "glyph.h"

/**
 * @brief Represents a font composed of multiple glyphs.
 *
 * Stores the name of the font, its vertical metrics (ascent and descent),
 * pixels per em, an array of glyphs and the amount of glyphs in that array.
 */
typedef struct {
	char* name; // Font name
	
	// Vertical metrics
	int ascent;
	int descent;

	int em_size; // Size of grid
	Glyph* glyphs; // Array of Glyphs
	size_t glyph_count; // Amount of glyphs in font
} Font;

// Font API
/**
 * @brief Creates a new, unconfigured DigitalSegmented font.
 *
 * Initializes a Font struct with default values:
 * - name set to "DigitalSegmented"
 * - em_size set to 1000
 * - glyphs set to NULL
 * - ascent and descent set to 0
 *
 * @return A Font struct with initialized fields.
 */
Font font_create(); 

/**
 * @brief Adds an array of glyphs to the font.
 *
 * Replaces the font's glyph array with the provided one and updates
 * the glyph count. Also computes and sets the font's ascent and descent
 * based on the vertical extents of all glyph segments.
 *
 * @param font Pointer to the Font to modify.
 * @param glyph Pointer to the first element of the Glyph array to add.
 * @return 0 on success, -1 if font or glyph is NULL.
 */
int font_add_glyphs(Font* font, Glyph* glyph); 

/**
 * @brief Computes the maximum ascent across all glyphs.
 *
 * Iterates through all segments of all glyphs to find the highest
 * vertical extent above the baseline.
 *
 * @param glyphs Pointer to an array of Glyphs.
 * @param count Number of glyphs in the array.
 * @return The maximum ascent value, or -1 if glyphs is NULL.
 */
int compute_ascent(Glyph* glyphs, size_t count); 

/**
 * @brief Computes the maximum descent across all glyphs.
 *
 * Iterates through all segments of all glyphs to find the lowest
 * vertical extent below the baseline.
 *
 * @param glyphs Pointer to an array of Glyphs.
 * @param count Number of glyphs in the array.
 * @return The maximum descent value, or -1 if glyphs is NULL.
 */
int compute_descent(Glyph* glyphs, size_t count); 

/**
 * @brief Frees all memory associated with a Font.
 *
 * Frees the segment arrays of each glyph, then frees the glyph array itself.
 * Resets the font's fields to safe defaults.
 *
 * @param font Pointer to the Font to free.
 */
void font_free(Font* font); 

#endif // Closes FONT_H include guard
