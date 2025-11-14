#include "test.h"

int test() {
	// Debug test ouput
	printf("Test 1: Create single glyph\n");
    Glyph g = glyph_create('A');
    printf("Created glyph with codepoint: %c\n", g.codepoint);
    
    printf("Test 2: Define glyph shape\n");
    int result = define_glyph_shape(&g);
    printf("Define result: %d, segment_count: %zu\n", result, g.segment_count);
    
    printf("Test 3: Print glyph\n");
    glyph_debug_print(&g);

    printf("Test 4: Compute advance\n");
    int adv = compute_advance(&g);
    printf("Advance width: %d\n", adv);
    
    printf("Test 5: Free glyph\n");
    glyph_free(&g);
    printf("Freed successfully\n");
    
    printf("\nTest 6: Try string function\n");
    glyph_debug_print_string("21 A:B C");
	
	return 0;
}
