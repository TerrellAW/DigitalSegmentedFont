// Standard Libraries
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Project Headers
#include "../test/test.h"
#include "../include/font.h"
#include "../include/glyph.h"
#include "../include/glyph_definitions.h"
#include "../include/writer.h"

int main(int argc, char* argv[]) {
	if (argc == 2 && strcmp(argv[1], "-t") == 0) {
		return test(); // Run glyph test output
	} else if (argc >= 2) { // Handle invalid args
		printf("Usage: %s OR %s -t\n", argv[0], argv[0]);
		return EXIT_FAILURE;
	}

	printf("Creating font...\n");

	// Create font
	Font font = font_create(); // Init font struct
	size_t count; // Init count var
	Glyph* glyphs = glyphs_create(&count); // Track count while creating glyphs
	
	printf("Created %zu glyphs\n", count);

	// Track glyph creation successes and failures
	int success_count = 0;
	int fail_count = 0;

	// Use glyph definitions
	for (size_t i = 0; i < count; i++) {
		if (define_glyph_shape(&glyphs[i]) == 0) {
			success_count++;
		} else {
			fail_count++;
			fprintf(stderr, "Warning: Failed to define glyph with codepoint 0x%X\n",
					glyphs[i].codepoint);
		}
	}
	if (success_count > 0) {
		printf("Successfully defined %d glyphs\n", success_count);
	}
	if (fail_count > 0) {
		printf("Failed to define %d glyphs\n", fail_count);
	}

	// Add glyphs to font
	font_add_glyphs(&font, glyphs, count);

	// Print font metrics
	printf("\nFont metrics:\n");
	printf("    Ascent:     %d\n", font.ascent);
	printf("    Descent:    %d\n", font.descent);
	printf("    EM Size:    %d\n", font.em_size);

	// Write BDF file
	printf("\nWriting BDF file...\n");
	if (write_bdf(&font, "DigitalSegmented.bdf") ==0) {
		printf("\nSuccess! Font file created: DigitalSegmented.bdf\n");
	} else {
		fprintf(stderr, "Failed to write BDF file\n");
		font_free(&font);
		return EXIT_FAILURE;
	}

	// Cleanup
	font_free(&font);

	printf("\nFont Generation Complete\n");

	return EXIT_SUCCESS;
}
