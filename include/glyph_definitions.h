// Include Guard, prevents compilation errors
#ifndef GLYPH_DEFINITIONS_H
#define GLYPH_DEFINITIONS_H

#include "glyph.h"

/**
 * @brief Defines the segment pattern for a given codepoint.
 *
 * @param glyph Pointer to glyph to populate with segments
 * @return 0 on success, -1 if codepoint not supported
 */
int define_glyph_shape(Glyph* glyph);

#endif
