// Include Guard, prevents compilation errors
#ifndef WRITER_H
#define WRITER_H

// Standard Libraries
#include <stdio.h>
#include <stdint.h>

// Font Header
#include "font.h"

// Main export function
/**
 * @brief Writes a complete TrueType Fron (TTF) file from a Font structure.
 *
 * Orchestrates the entire TTF file creation process by:
 * 1. 	Opening the output file for binary writing
 * 2. 	Writing the font directory header (table count, search range, etc.)
 * 3. 	Computing or buffering all required tables (head, hhea, hmtx, maxp, 
 * 		cmap, loca, glyph, name, post)
 * 4.	Calculating checksums and byte offsets for each table
 * 5.	Writing table directory entries with tags, checksums, offsets and lengths
 * 6.	Writing each table's data in the correct order
 * 7.	Updating the 'head' table checksum adjustment field if needed
 *
 * The resulting TTF file will be compatible with standard font renderers
 * and can be installed/used as a system font.
 *
 * @param font 		Pointer to the Font structure containing all glyph data and metrics.
 * 			   		Must have glyphs populated with segments, valid ascent/descent, 
 * 			   		and em_size.
 * @param filepath 	Path to the output TTF file. Will be created or overwritten.
 * 
 * @return 0 on success, -1 on failure (file I/O error, invalid font data, etc.)
 *
 * @note Tables are typically written in alphabetical order by tag for compatibility.
 */
int write_ttf(Font* font, const char* filepath);

// Table writers
/**
 * @brief Writes the 'head' table (font header).
 *
 * Contains global font information including version, checksum adjustment,
 * magic number, flags, units per em, creation/modification dates, bounding box,
 * mac style, smallest readable size, direction hint, index-to-location format,
 * and glyph data format.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing metrics and metadata.
 */
void write_head_table(FILE* out, Font* font);
/**
 * @brief Writes the 'hhea' table (horizontal header).
 *
 * Contains horizontal layout metrics including ascent, descent, line gap,
 * advance width max, min left/right side bearings, x max extent, caret slope,
 * reserved fields, metric data format, and number of horizontal metrics.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing horizontal metrics.
 */
void write_hhea_table(FILE* out, Font* font);
/**
 * @brief Writes the 'hmtx' table (horizontal metrics).
 *
 * Contains horizontal metrics for each glyph including advance width and
 * left side bearing. One entry per glyph in the font.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing glyph metrics.
 */
void write_hmtx_table(FILE* out, Font* font);
/**
 * @brief Writes the 'maxp' table (maximum profile).
 *
 * Contains the maximum values for various font-wide metrics including
 * number of glyphs, max points/contours per glyph, max composite points/contours,
 * max zones, twilight points, storage areas, function defs, instruction defs,
 * stack elements, instruction size, and component elements/depth.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing glyph data for analysis.
 */
void write_maxp_table(FILE* out, Font* font);
/**
 * @brief Writes the 'cmap' table (character to glyph mapping).
 *
 * Maps Unicode codepoints to glyph indices. Typically includes multiple
 * subtables for different platforms (Windows, Mac) and encodings (Unicode BMP,
 * full Unicode). Enables text rendering by translating characters to glyphs.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing glyph codepoint mappings.
 */
void write_cmap_table(FILE* out, Font* font);
/**
 * @brief Writes the 'loca' table (glyph location index).
 *
 * Stores byte offsets to each glyph's data in the 'glyph' table. Can use
 * short (16-bit) or long (32-bit) format depending on font size. Contains
 * one entry per glyph plus one extra entry to mark the end of the last glyph.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing glyph data.
 */
void write_loca_table(FILE* out, Font* font);
/**
 * @brief Writes the 'glyph' table (glyph data).
 *
 * Contains the actual outline data for each glyph including number of contours,
 * bounding box, and contour point data (coordinates, flags, instructions).
 * For simple glyphs: endpoint indices, flags array, x-coordinates, y-coordinates.
 * Empty glyphs (like space) have zero-length entries.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing segment data to convert to contours.
 */
void write_glyph_table(FILE* out, Font* font);
/**
 * @brief Writes the 'name' table (naming table).
 *
 * Contains human-readable metadata strings in multiple languages/platforms
 * including font family name, subfamily, unique ID, full name, version,
 * PostScript name, copyright, trademark, manufacturer, designer, description,
 * and license information.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing name metadata.
 */
void write_name_table(FILE* out, Font* font);
/**
 * @brief Writes the 'post' table (PostScript information).
 *
 * Contains PostScript-related data including format version, italic angle,
 * underline position/thickness, fixed pitch flag, memory usage hints, and
 * optionally glyph name indices for PostScript compatibility.
 *
 * @param out File pointer to write to.
 * @param font Pointer to the Font containing PostScript metadata.
 */
void write_post_table(FILE* out, Font* font);

// Binary helpers
/**
 * @brief Writes a 16-bit unsigned integer in big-endian format.
 * @param out File pointer to write to.
 * @param value 16-bit value to write.
 */
void write_uint16(FILE* out, uint16_t value);
/**
 * @brief Writes a 32-bit unsigned integer in big-endian format.
 * @param out File pointer to write to.
 * @param value 32-bit value to write.
 */
void write_uint32(FILE* out, uint32_t value);
/**
 * @brief Writes a 16-bit signed integer in big-endian format.
 * @param out File pointer to write to.
 * @param value 16-bit value to write.
 */
void write_int16(FILE* out, int16_t value);
/**
 * @brief Calculates TTF table checksum.
 * @param data Pointer to table data.
 * @param length Length of data in bytes.
 * @return Checksum value.
 */
uint32_t calculate_checksum(const uint8_t* data, size_t length);
/**
 * @brief Writes the TTF table directory (file header).
 * @param out File pointer to write to.
 * @param num_tables Number of tables in the font.
 */
void write_table_directory(FILE* out, uint16_t num_tables);
/**
 * @brief Writes a single table directory entry.
 * @param out File pointer to write to.
 * @param tag 4-character table tag (e.g., "head", "glyf").
 * @param checksum Table checksum.
 * @param offset Byte offset from beginning of file.
 * @param length Table length in bytes.
 */
void write_table_entry(FILE* out, const char* tag, uint32_t checksum, 
                       uint32_t offset, uint32_t length);

#endif // Closes WRITER_H include guard
