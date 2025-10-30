#include "../include/glyph.h"
#include "../include/font.h"

// Function declarations
int compute_ascent(Glyph* glyphs, size_t count);
int compute_descent(Glyph* glyphs, size_t count);

// Function implementations

Font font_create(Glyph* glyphs, size_t count) {
	Font font;
	font.glyphs = glyphs;
	font.glyph_count = count;
	font.em_size = 1000;
	font.name = "DigitalSegmented";
	font.ascent = compute_ascent(glyphs, count);
	font.descent = compute_descent(glyphs, count);
	return font;
}

int compute_ascent(Glyph* glyphs, size_t count) {
	int yMax = 0; // Temp
	
	// TODO: Loop through glyphs and find highest vertical coord
	
	return yMax;
}

int compute_descent(Glyph* glyphs, size_t count) {
	int yMin = 0; // Temp
	
	// TODO: Loop through glyphs and find the lowest vertical coord
	
	return yMin;
}

void font_free(Font font) {
	// TODO: Free memory
}

