// Include Guard, prevents compilation errors
#ifndef WRITER_H
#define WRITER_H

// Standard Libraries
#include <stdio.h>
#include <stdint.h>

// Font Header
#include "font.h"

/**
 * @brief Writes a font to a BDF (Bitmap Distribution Format) file.
 *
 * Converts the font's glyphs into BDF format, which can be compiled
 * to PCF format for use with X11/Linux systems including SDDM.
 *
 * @param font Pointer to the Font to write.
 * @param filepath Path to the output BDF file.
 * @return 0 on success, -1 on failure.
 */
int write_bdf(Font* font, const char* filepath);

#endif // Closes WRITER_H include guard
