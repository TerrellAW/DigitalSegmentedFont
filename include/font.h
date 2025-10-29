// Include Guard, prevents compilation errors
#ifndef FONT_H
#define FONT_H

// Glyph Header
#include "glyph.h"

typedef struct {
	char* name; // Font name
	
	// Vertical metrics
	int ascent;
	int descent;

	int units_per_em; // Size of grid
	Glyph** glyphs; // Array of pointers to Glyph
	int glyph_count; // Amount of glyphs in font
} Font;

// Font API
Font* font_create(const char* name); // Allocate and initialize new font
void font_add_glyph(Font* font, Glyph* glyph); // Add glyph to font
void font_set_metrics(Font* font, int ascent, int descent, int units_per_em); // Set font size and layout
void font_free(Font* font); // Release memory used to create Font

#endif // Closes FONT_H include guard
