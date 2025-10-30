#include <stddef.h>
#include <limits.h>

#include "../include/glyph.h"

// Function Declarations
int computeAdvance();

Glyph glyph_create(uint32_t codepoint) {
	Glyph glyph;
	glyph.codepoint = codepoint;
	glyph.advance_width = computeAdvance();
	glyph.segment_count = 0;
	return glyph;
}

void glyph_add_segment(Glyph* glyph, int x, int y, int size) {
	// TODO: Create square and add it to array of segments in glyph struct
	glyph->segment_count++; // Increment count via pointer
}

void glyph_free(Glyph* glyph) {
	// TODO: Free memory
}
