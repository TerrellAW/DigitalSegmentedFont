#include <stdio.h>
#include <stdlib.h>

#include "../include/glyph.h"
#include "../include/utils.h"

// Allocate and initialize glyph
Glyph glyph_create(uint32_t codepoint) {
	Glyph glyph;
	glyph.codepoint = codepoint;
	glyph.advance_width = 0;
	glyph.segments = NULL;
	glyph.segment_count = 0;
	return glyph;
}

// Add square segment to glyph 
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
		fprintf(stderr, "glyph_add_segment: failed due to glyph or size: %d\n", size); // Print to error output stream
		return -1; // Failure
	}
}

// Compute space between glyphs
int compute_advance(Glyph* glyph) {
	if (!glyph) return -1;
	int x_max = 0; // Initialize empty variable for right-most x coordinate
	for (size_t i = 0; i < glyph->segment_count; i++) { // Iterate through segments of glyph
		int right_edge = glyph->segments[i].x + glyph->segments[i].size; // Find right edge of segment
		if (right_edge > x_max) { // Compare right edge of segment to highest x coord
			x_max = right_edge; // Set highest x coord to higher value
		}
	}
	return x_max + 1; // Return with padding
}

// Release memory used to create glyph
void glyph_free(Glyph* glyph) {
	if (!glyph) return; // Check if glyph exists
	free(glyph->segments); // Release memory holding Segment structs
	glyph->segments = NULL; // Reset pointer
	glyph->segment_count = 0; // Reset count via pointer
}
