// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Project Headers
#include "../include/font.h"
#include "../include/glyph.h"
#include "../include/glyph_definitions.h"
#include "../include/writer.h"
#include "../include/utils.h"

int main() {
	// Debug test ouput
	Glyph test_A = glyph_create('A');
	Glyph test_B = glyph_create('B');
	define_glyph_shape(&test_A);
	define_glyph_shape(&test_B);
	glyph_debug_print(&test_A);
	glyph_debug_print(&test_B);
	glyph_free(&test_A);
	glyph_free(&test_B);

	// TODO: Call and use functions from headers
};
