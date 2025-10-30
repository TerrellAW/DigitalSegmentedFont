// Include Guard, prevents compilation errors
#ifndef GLYPH_H
#define GLYPH_H

// Standard Libraries
#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

// Define Segment struct
typedef struct {
	// Coordinates
	int x;
	int y;

	// Size of square
	int size;
} Segment;

// Define Glyph struct
typedef struct {
	// Unicode value
	uint32_t codepoint;
	
	// Distance to move cursor after drawing glyph
	int advance_width;

	// Dynamic array of square segments
	Segment* segments;

	// Amount of square segments
	size_t segment_count;
} Glyph;

// Glyph API
Glyph glyph_create(uint32_t codepoint); // Allocate and initialize glyph
void glyph_add_segment(Glyph* glyph, int x, int y, int size); // Add square segement to glyph
void glyph_free(Glyph* glyph); // Release memory used to create glyph

#endif // Closes GLYPH_H include guard
