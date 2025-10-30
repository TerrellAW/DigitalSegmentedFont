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
	Glyph* glyphs; // Array of Glyphs
	size_t glyph_count; // Amount of glyphs in font
} Font;

// Font API
Font font_create(Glyph* glyphs, size_t count); // Initialize and generate font
void font_free(Font font); // Release memory used to create Font

#endif // Closes FONT_H include guard
