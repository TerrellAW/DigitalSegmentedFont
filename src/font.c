#include <stdio.h>
#include <stdlib.h>

#include "../include/utils.h"
#include "../include/glyph.h"
#include "../include/font.h"

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
	const uint32_t start = 0x20; // Space
	const uint32_t end	 = 0x7E; // Tilde

	size_t count = end - start + 1; // Adding 1 ensures inclusive
	if (out_count) *out_count = count; // Optional external pointer

	// Allocate memory for glyph array
	Glyph* glyphs = safe_malloc(count * sizeof(Glyph));

	// Initialize each glyph
	for (size_t i = 0; i < count; i++) {
		uint32_t codepoint = start + 1;
		glyphs[i] = glyph_create(codepoint);
	}

	return glyphs;
}

// Add glyph to font
int font_add_glyphs(Font* font, Glyph* glyph) {
	
}

// Compute max height of glyphs
int compute_ascent(Glyph* glyphs, size_t count) {
	
}

// Compute max depth of glyphs
int compute_descent(Glyph* glyphs, size_t count) {
	
}

// Release memory used to create Font
void font_free(Font* font) {
	if (!font) return; // Check if font exists
	
	for (size_t i = 0; i < font->glyph_count; i++) { // Iterate through glyphs
		glyph_free(&font->glyphs[i]); // Free memory
	}
	free(font); // Release memory holding font
	font = NULL;
}
