// Include Guard, prevents compilation errors
#ifndef FONT_H
#define FONT_H

// Standard Library
#include <stddef.h>
#include <stdio.h>

// Glyph Header
#include "glyph.h"

typedef struct {
	char* name; // Font name
	
	// Vertical metrics
	int ascent;
	int descent;

	int em_size; // Size of grid
	Glyph** glyphs; // Array of Glyphs
	size_t glyph_count; // Amount of glyphs in font
} Font;

// Font API
Font font_create(); // Initialize empty font
int font_add_glyphs(Font* font, Glyph* glyph); // Add glyph to font
int compute_ascent(Glyph** glyphs, size_t count); // Compute max height of glyphs
int compute_descent(Glyph** glyphs, size_t count); // Compute max depth of glyphs
void font_free(Font* font); // Release memory used to create Font

#endif // Closes FONT_H include guard
