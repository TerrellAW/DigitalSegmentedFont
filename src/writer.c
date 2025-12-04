#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include "../include/writer.h"

// Convert current time to TTF format
uint64_t get_ttf_timestamp() {
	time_t now = time(NULL);

	// Add Unix epoch (seconds from 1904 to 1970)
	uint64_t ttf_time = (uint64_t)now + 2082844800ULL;
	return ttf_time;
}

void write_head_table(FILE* out, Font* font) {
	// Table version (Fixed: 16.16 format) - version 1.0
	write_uint32(out, 0x00010000);

	// Font revision (Fixed: 16.16 format) - version 1.0
	write_uint32(out, 0x00010000);

	// Checksum placeholder
	write_uint32(out, 0x00000000);

	// Magic number must be 0x5F0F3CF5
	write_uint32(out, 0x5F0F3CF5);

	// Flags
	write_uint16(out, 0x0009);

	// Units per em
	write_uint16(out, (uint16_t)font->em_size);

	// Creation date - calculated in seconds since 12:00 midnight, January 1, 1904
	// TODO: Add actual time
	write_uint32(out, 0x00000000); // High 32 bits
	write_uint32(out, 0x00000000); // Low 32 bits

	// Minimum x coordinate across all glyph bounding boxes
	write_int16(out, 0);

	// Minimum y coordinate
	write_int16(out, (int16_t)(-font->descent));

	// Maximum x coordinate across all glyph bounding boxes
	int16_t xMax = 0;
	for (size_t i = 0; i < font->glyph_count; i++) {
		int advance = font->glyphs[i].advance_width;
		if (advance > xMax) xMax = (int16_t)advance;
	}
	write_int16(out, xMax);

	// Maximum y coordinate
	write_int16(out, (int16_t)font->ascent);

	// Mac style - bit 0: bold, bit 1: italic
	write_int16(out, 0x0000);

	// Lowest recommended PPEM, ie. smallest readable size in pixels
	write_uint16(out, 8);

	// Font direction hint
	write_int16(out, 2);

	// Index to loc format, 0 for short 16-bit, 1 for long 32-bit
	write_int16(out, 1);

	// Glyph data format, 0 for current format
	write_int16(out, 0);
}

bool is_valid(const char* filepath) {
	// TODO: validate filepath with regex
	return false;
}

int write_ttf(Font* font, const char* filepath) {
	// If file path is null, throw error
	if (!filepath) {
		fprintf(stderr, "Write failed: ouput path %s does not exist", filepath); // Print error to error stream
		return 1; // Error code
	}
	// If filepath is invalid, throw error
	if (!is_valid(filepath)) {
		fprintf(stderr, "Write failed: output path %s is invalid", filepath); // Print error to error stream
		return 1; // Error code
	}

	// TODO: Use write functions

	return 1;
}
