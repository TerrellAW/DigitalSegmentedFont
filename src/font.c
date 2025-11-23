#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/glyph.h"
#include "../include/font.h"

// Initialize constants
static const int BASELINE = 19;

// Initialize font
Font font_create() {
	Font font;
	font.glyphs = NULL;
	font.glyph_count = 0;
	font.em_size = 1000;
	font.name = "DigitalSegmented";
	font.ascent = 0;
	font.descent = 0;
	return font;
}

// Create array of Glyph structs
Glyph* glyphs_create(size_t* out_count) {
	// Define range of Unicode codepoints
	// const uint32_t start = 0x20; // Space
	// const uint32_t end	 = 0x7E; // Tilde
	// size_t count = end - start + 1; // Adding 1 ensures inclusive
	
	// Define only the 37 supported characters
	const uint32_t codepoints[] = {
		' ', ':',
		'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
		'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'
	};

	size_t count = sizeof(codepoints) / sizeof(codepoints[0]); // Get amount of elements in array
	if (out_count) *out_count = count; // Optional external pointer

	// Allocate memory for glyph array
	Glyph* glyphs = safe_malloc(count * sizeof(Glyph));

	// Initialize each glyph
	for (size_t i = 0; i < count; i++) {
		// uint32_t codepoint = start + i;
		glyphs[i] = glyph_create(codepoints[i]);
	}

	return glyphs;
}

// Add glyph to font
int font_add_glyphs(Font* font, Glyph* glyphs, size_t glyph_count) {
	if (!font || !glyphs) return -1;

	font->glyphs = glyphs;
	font->glyph_count = glyph_count;
	font->ascent = compute_ascent(font);
	font->descent = compute_descent(font);

	return 0;
}

// Compute max height of glyphs
int compute_ascent(Font* font) {
	if (!font->glyphs) return -1; // Return if array is null
	int max_a = 0; // Init var for highest y coordinate
	for (size_t i = 0; i < font->glyph_count; i++) {
		for (size_t j = 0; j < font->glyphs[i].segment_count; j++) {
			int top = font->glyphs[i].segments[j].y;
			int ascent = BASELINE - top;
			if (ascent > max_a) max_a = ascent;
		}
	}
	return max_a;
}

// Compute max depth of glyphs
int compute_descent(Font* font) {
	if (!font->glyphs) return -1; // Return if array is null
	int max_d = 0;
	for (size_t i = 0; i < font->glyph_count; i++) {
		for (size_t j = 0; j < font->glyphs[i].segment_count; j++) {
			int bot = font->glyphs[i].segments[j].y + font->glyphs[i].segments[j].size;
			int descent = bot - BASELINE;
			if (descent > max_d) max_d = descent;
		}
	}
	return max_d;
}

// Release memory used to create Font
void font_free(Font* font) {
	if (!font) return; // Check if font exists
	
	for (size_t i = 0; i < font->glyph_count; i++) { // Iterate through glyphs
		glyph_free(&font->glyphs[i]); // Free memory
	}

	free(font->glyphs); // Free glyphs array
	
	// Reset fields
	font->glyphs = NULL;
	font->glyph_count = 0;
	font->ascent = 0;
	font->descent = 0;
}
