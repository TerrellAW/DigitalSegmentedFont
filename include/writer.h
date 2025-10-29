// Include Guard, prevents compilation errors
#ifndef WRITER_H
#define WRITER_H

// Standard Libraries
#include <stdio.h>
#include <stdint.h>

// Font Header
#include "font.h"

// Main export function
int write_ttf(Font* font, const char* filepath);

// Table writers
void write_head_table(FILE* out, Font* font);
void write_cmap_table(FILE* out, Font* font);
void write_glyph_table(FILE* out, Font* font);

// TODO: Binary helpers

#endif // Closes WRITER_H include guard
