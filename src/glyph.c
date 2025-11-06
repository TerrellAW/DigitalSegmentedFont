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

// Add segment at grid position
int glyph_add_block(Glyph* glyph, int grid_x, int grid_y) {
	const int SEGMENT_SIZE = 3; // Size of squares
	const int GAP = 1; // Size of space between squares
	const int GRID_STEP = SEGMENT_SIZE + GAP; // Actual size (4)

	int pixel_x = grid_x * GRID_STEP; // Measure horizontal pixels
	int pixel_y = grid_y * GRID_STEP; // Measure vertical pixels

	return glyph_add_segment(glyph, pixel_x, pixel_y, SEGMENT_SIZE); // Create the segment
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
	return x_max + 2; // Return with padding
}

// Release memory used to create glyph
void glyph_free(Glyph* glyph) {
	if (!glyph) return; // Check if glyph exists
	free(glyph->segments); // Release memory holding Segment structs
	glyph->segments = NULL; // Reset pointer
	glyph->segment_count = 0; // Reset count via pointer
}

// Debug output
void glyph_debug_print(Glyph* glyph) {
	if (!glyph) return;

	// Find bounds
    int max_x = 0, max_y = 0;
    for (size_t i = 0; i < glyph->segment_count; i++) {
        int right = glyph->segments[i].x + glyph->segments[i].size;
        int bottom = glyph->segments[i].y + glyph->segments[i].size;
        if (right > max_x) max_x = right;
        if (bottom > max_y) max_y = bottom;
    }
    
    printf("Glyph '%c' (U+%04X):\n", (char)glyph->codepoint, glyph->codepoint);
    
    // Print grid
    for (int y = 0; y < max_y; y++) {
        for (int x = 0; x < max_x; x++) {
            bool filled = false;
            // Check if this pixel is inside any segment
            for (size_t i = 0; i < glyph->segment_count; i++) {
                Segment* seg = &glyph->segments[i];
                if (x >= seg->x && x < seg->x + seg->size &&
                    y >= seg->y && y < seg->y + seg->size) {
                    filled = true;
                    break;
                }
            }
            printf("%s", filled ? "██" : "  ");
        }
        printf("\n");
    }
    printf("Advance width: %d\n\n", glyph->advance_width);
}
