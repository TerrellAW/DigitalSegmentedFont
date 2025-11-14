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
 * @brief Creates a dynamically allocated array of Glyph structs for a fixed Unicode range.
 *
 * Initializes one Glyph for each Unicode codepoint in the printable ASCII range (0x20 to 0x7E),
 * using glyph_create(). The resulting array contains 95 glyphs, each with its codepoint set.
 *
 * If the caller provides a non-NULL pointer to out_count, the total number of glyphs created
 * will be written to that location.
 *
 * @param out_count Optional pointer to a size_t variable to receive the number of glyphs created.
 * @return Pointer to a dynamically allocated array of Glyph structs, or NULL on failure.
 *
 * @note The caller is responsible for freeing the returned array using font_free().
 */
Glyph* glyphs_create(size_t* out_count);

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
int font_add_glyphs(Font* font, Glyph* glyphs); 

/**
 * @brief Computes the maximum ascent across all glyphs.
 *
 * Iterates through all segments of all glyphs to find the highest
 * vertical extent above the baseline.
 *
 * @param font Pointer to a Font struct.
 * @return The maximum ascent value, or -1 if glyphs is NULL.
 */
int compute_ascent(Font* font); 

/**
 * @brief Computes the maximum descent across all glyphs.
 *
 * Iterates through all segments of all glyphs to find the lowest
 * vertical extent below the baseline.
 *
 * @param font Pointer to a Font struct.
 * @return The maximum descent value, or -1 if glyphs is NULL.
 */
int compute_descent(Font* font); 

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
