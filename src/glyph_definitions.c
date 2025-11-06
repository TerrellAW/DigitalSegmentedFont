#include "../include/glyph_definitions.h"

int define_glyph_shape(Glyph* glyph) {
	if (!glyph) return -1; // Return error code
	
	switch(glyph->codepoint) {
		case ' ':
			glyph->advance_width = 13; // Advance to next char slot
			break;
		case ':':
			glyph_add_block(glyph, 0, 1);

			glyph_add_block(glyph, 0, 3);

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'A':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0);  // Left
			glyph_add_block(glyph, 1, 0);  // Middle
			glyph_add_block(glyph, 2, 0);  // Right
			
			// Row 1: Left and right sides only
			glyph_add_block(glyph, 0, 1);  // Left
			glyph_add_block(glyph, 2, 1);  // Right
			
			// Row 2: Horizontal bar (three segments)
			glyph_add_block(glyph, 0, 2);  // Left
			glyph_add_block(glyph, 1, 2);  // Middle
			glyph_add_block(glyph, 2, 2);  // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3);  // Left
			glyph_add_block(glyph, 2, 3);  // Right
			
			// Row 4: Left and right sides (bottom)
			glyph_add_block(glyph, 0, 4);  // Left
			glyph_add_block(glyph, 2, 4);  // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'B':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0);  // Left
			glyph_add_block(glyph, 1, 0);  // Middle
			glyph_add_block(glyph, 2, 0);
			
			// Row 1: Left stem and bulged right side
			glyph_add_block(glyph, 0, 1);  // Left stem
			glyph_add_block(glyph, 2, 1);  // Bulged right (x=12 pixels)
			
			// Row 2: Horizontal bar (three segments)
			glyph_add_block(glyph, 0, 2);  // Left
			glyph_add_block(glyph, 1, 2);  // Middle
			
			// Row 3: Left stem and bulged right side
			glyph_add_block(glyph, 0, 3);  // Left stem
			glyph_add_block(glyph, 2, 3);  // Bulged right (x=12 pixels)
			
			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4);  // Left
			glyph_add_block(glyph, 1, 4);  // Middle
			glyph_add_block(glyph, 2, 4);
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'C':
			glyph_add_block(glyph, 0, 0);
			glyph_add_block(glyph, 1, 0);
			glyph_add_block(glyph, 2, 0);

			glyph_add_block(glyph, 0, 1);

			glyph_add_block(glyph, 0, 2);

			glyph_add_block(glyph, 0, 3);

			glyph_add_block(glyph, 0, 4);
			glyph_add_block(glyph, 1, 4);
			glyph_add_block(glyph, 2, 4);

			glyph->advance_width = compute_advance(glyph);
			break;
		default:
			return -1;
	}

	return 0;
}
