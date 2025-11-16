#include "../include/glyph_definitions.h"

int define_glyph_shape(Glyph* glyph) {
	if (!glyph) return -1; // Return error code
	
	switch(glyph->codepoint) {
		case ' ':
			glyph->advance_width = 12; // Advance to next char slot
			break;
		case ':':
			// Row 1: One segment
			glyph_add_block(glyph, 0, 1);

			// Row 3: One segment
			glyph_add_block(glyph, 0, 3);

			glyph->advance_width = compute_advance(glyph);
			break;
		case '0':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides and top of bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 2, 1); // Middle Right
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right sides
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 1, 3); // Middle Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case '1':
			// Row 0: One segment
			glyph_add_block(glyph, 0, 0);

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1);

			// Row 2: One segment
			glyph_add_block(glyph, 0, 2);
			
			// Row 3: One segment
			glyph_add_block(glyph, 0, 3);

			// Row 4: One segment
			glyph_add_block(glyph, 0, 4);

			glyph->advance_width = compute_advance(glyph);
			break;
		case '2':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '3':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '4':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: One segment
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '5':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '6':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '7':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: One segment
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: One segment
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case '8':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case '9':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: One segment
			glyph_add_block(glyph, 3, 4); // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'A':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right
			
			// Row 1: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right
			
			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3);  // Left
			glyph_add_block(glyph, 3, 3);  // Right
			
			// Row 4: Left and right sides (bottom)
			glyph_add_block(glyph, 0, 4);  // Left
			glyph_add_block(glyph, 3, 4);  // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'B':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle
			glyph_add_block(glyph, 2, 0); // Right
			
			// Row 1: Left stem and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right
			
			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle
			glyph_add_block(glyph, 2, 2); // Right
			
			// Row 3: Left stem and bulged right side
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right
			
			// Row 4: Segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle
			glyph_add_block(glyph, 2, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'C':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: One segment
			glyph_add_block(glyph, 0, 2); // Left

			// Row 3: One segment
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'D':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle
			glyph_add_block(glyph, 2, 0); // Right

			// Row 1: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right sides
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle
			glyph_add_block(glyph, 2, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'E':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left side
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left side
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'F':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left side
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left side
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Left side
			glyph_add_block(glyph, 0, 4); // Left

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'G':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left side
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Left and right hook
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'H':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'I':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle
			glyph_add_block(glyph, 2, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 1, 1); // Middle
			
			// Row 2: One segment
			glyph_add_block(glyph, 1, 2); // Middle
			
			// Row 3: One segment
			glyph_add_block(glyph, 1, 3); // Middle

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle
			glyph_add_block(glyph, 2, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'J':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 1, 0); // Left
			glyph_add_block(glyph, 2, 0); // Middle
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 2, 1); // Middle
			
			// Row 2: One segment
			glyph_add_block(glyph, 2, 2); // Middle
			
			// Row 3: One segment
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 2, 3); // Middle

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle
			glyph_add_block(glyph, 2, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'K':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 2, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 2, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'L':
			// Row 0: One segment
			glyph_add_block(glyph, 0, 0); // Left

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: One segment
			glyph_add_block(glyph, 0, 2); // Left

			// Row 3: One segment
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'M':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 1, 1); // Middle Left
			glyph_add_block(glyph, 2, 1); // Middle Right
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'N':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 1, 1); // Middle Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 2, 3); // Middle Right
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'O':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides and top of bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right sides
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'P':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides and top of bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: One segment
			glyph_add_block(glyph, 0, 4); // Left
			
			glyph->advance_width = compute_advance(glyph);
			break;
		case 'Q':
			// Row 0: Three segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right sides and top of bar
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right sides
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 2, 3); // Middle Right
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Three segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			// Descent: One segment
			glyph_add_block(glyph, 2, 5); // Middle Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'R':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 2, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'S':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 0, 1); // Left

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right
			
			// Row 3: One segment
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'T':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: One segment
			glyph_add_block(glyph, 1, 1); // Middle
			
			// Row 2: One segment
			glyph_add_block(glyph, 1, 2); // Middle
			
			// Row 3: One segment
			glyph_add_block(glyph, 1, 3); // Middle

			// Row 4: One segment
			glyph_add_block(glyph, 1, 4); // Middle

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'U':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right side
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'V':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Left and right side
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Two segments
			glyph_add_block(glyph, 1, 3); // Middle Left
			glyph_add_block(glyph, 2, 3); // Middle Right

			// Row 4: One segment
			glyph_add_block(glyph, 1, 4); // Middle Left

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'W':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 2: Left and right sides
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 0, 2); // Left
			glyph_add_block(glyph, 1, 2); // Middle Left
			glyph_add_block(glyph, 2, 2); // Middle Right
			glyph_add_block(glyph, 3, 2); // Right

			// Row 3: Horizontal bar
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 1, 3); // Middle Left
			glyph_add_block(glyph, 2, 3); // Middle Right
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'X':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 1, 2); // Left
			glyph_add_block(glyph, 2, 2); // Right

			// Row 3: Left and right sides
			glyph_add_block(glyph, 0, 3); // Left
			glyph_add_block(glyph, 3, 3); // Right

			// Row 4: Left and right sides
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'Y':
			// Row 0: Left and right sides
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Left and right side
			glyph_add_block(glyph, 0, 1); // Left
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 1, 2); // Left
			glyph_add_block(glyph, 2, 2); // Right

			// Row 3: One segment
			glyph_add_block(glyph, 1, 3); // Middle Left

			// Row 4: One segment
			glyph_add_block(glyph, 1, 4); // Middle Left

			glyph->advance_width = compute_advance(glyph);
			break;
		case 'Z':
			// Row 0: Four segments across the top
			glyph_add_block(glyph, 0, 0); // Left
			glyph_add_block(glyph, 1, 0); // Middle Left
			glyph_add_block(glyph, 2, 0); // Middle Right
			glyph_add_block(glyph, 3, 0); // Right

			// Row 1: Right side
			glyph_add_block(glyph, 3, 1); // Right

			// Row 2: Horizontal bar
			glyph_add_block(glyph, 1, 2); // Left
			glyph_add_block(glyph, 2, 2); // Right

			// Row 3: Left side
			glyph_add_block(glyph, 0, 3); // Left

			// Row 4: Four segments across the bottom
			glyph_add_block(glyph, 0, 4); // Left
			glyph_add_block(glyph, 1, 4); // Middle Left
			glyph_add_block(glyph, 2, 4); // Middle Right
			glyph_add_block(glyph, 3, 4); // Right

			glyph->advance_width = compute_advance(glyph);
			break;
		default:
			return -1;
	}

	return 0;
}
