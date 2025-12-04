#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/writer.h"
#include "../include/font.h"
#include "../include/utils.h"

// Rasterize glyph segments into a bitmap
void rasterize_glyph(Glyph* glyph, int height, int width, bool* bitmap) {
    // Initialize bitmap to false (empty)
    memset(bitmap, 0, height * width * sizeof(bool));
    
    // Fill in pixels where segments exist
    for (size_t i = 0; i < glyph->segment_count; i++) {
        Segment* s = &glyph->segments[i];
        
        // Fill the square segment
        for (int y = s->y; y < s->y + s->size && y < height; y++) {
            for (int x = s->x; x < s->x + s->size && x < width; x++) {
                if (x >= 0 && y >= 0) {
                    bitmap[y * width + x] = true;
                }
            }
        }
    }
}

// Convert bitmap row to hex string
void bitmap_row_to_hex(bool* row, int width, char* hex_out) {
    int bytes = (width + 7) / 8; // Round up to nearest byte
    
    for (int b = 0; b < bytes; b++) {
        unsigned char byte = 0;
        for (int bit = 0; bit < 8; bit++) {
            int pixel_index = b * 8 + bit;
            if (pixel_index < width && row[pixel_index]) {
                byte |= (0x80 >> bit); // Set bit from left to right
            }
        }
        sprintf(hex_out + (b * 2), "%02X", byte);
    }
}

int write_bdf(Font* font, const char* filepath) {
    if (!font || !filepath) {
        fprintf(stderr, "write_bdf: invalid font or filepath\n");
        return -1;
    }
    
    FILE* out = fopen(filepath, "w");
    if (!out) {
        fprintf(stderr, "write_bdf: could not open %s for writing\n", filepath);
        return -1;
    }
    
    int total_height = font->ascent + font->descent;
    
    // Calculate max width
    int max_width = 0;
    for (size_t i = 0; i < font->glyph_count; i++) {
        if (font->glyphs[i].advance_width > max_width) {
            max_width = font->glyphs[i].advance_width;
        }
    }
    
    // Write BDF header
    fprintf(out, "STARTFONT 2.1\n");
    fprintf(out, "FONT -misc-%s-medium-r-normal--%d-120-75-75-m-%d-iso10646-1\n",
            font->name, total_height, max_width * 10);
    fprintf(out, "SIZE %d 75 75\n", total_height);
    fprintf(out, "FONTBOUNDINGBOX %d %d 0 %d\n", max_width, total_height, -font->descent);
    fprintf(out, "STARTPROPERTIES 2\n");
    fprintf(out, "FONT_ASCENT %d\n", font->ascent);
    fprintf(out, "FONT_DESCENT %d\n", font->descent);
    fprintf(out, "ENDPROPERTIES\n");
    fprintf(out, "CHARS %zu\n\n", font->glyph_count);
    
    // Allocate bitmap buffer using safe_malloc
    bool* bitmap = safe_malloc(total_height * max_width * sizeof(bool));
    
    // Write each glyph
    for (size_t i = 0; i < font->glyph_count; i++) {
        Glyph* g = &font->glyphs[i];
        
        char glyph_name[32];
        if (g->codepoint == 32) {
            strcpy(glyph_name, "space");
        } else if (g->codepoint >= 33 && g->codepoint <= 126) {
            snprintf(glyph_name, sizeof(glyph_name), "char%u", g->codepoint);
        } else {
            snprintf(glyph_name, sizeof(glyph_name), "uni%04X", g->codepoint);
        }
        
        fprintf(out, "STARTCHAR %s\n", glyph_name);
        fprintf(out, "ENCODING %u\n", g->codepoint);
        fprintf(out, "SWIDTH %d 0\n", g->advance_width * 1000 / font->em_size);
        fprintf(out, "DWIDTH %d 0\n", g->advance_width);
        
        int glyph_width = g->advance_width > 0 ? g->advance_width : max_width;
        fprintf(out, "BBX %d %d 0 %d\n", glyph_width, total_height, -font->descent);
        fprintf(out, "BITMAP\n");
        
        // Rasterize this glyph
        rasterize_glyph(g, total_height, glyph_width, bitmap);
        
        // Output bitmap rows from top to bottom
        char hex_row[256];
        for (int y = total_height - 1; y >= 0; y--) {
            bitmap_row_to_hex(&bitmap[y * glyph_width], glyph_width, hex_row);
            fprintf(out, "%s\n", hex_row);
        }
        
        fprintf(out, "ENDCHAR\n\n");
    }
    
    fprintf(out, "ENDFONT\n");
    
    free(bitmap);
    fclose(out);
    
    printf("BDF font written to %s\n", filepath);
    printf("To install:\n");
    printf("  bdftopcf %s -o %s.pcf\n", filepath, font->name);
    printf("  gzip %s.pcf\n", font->name);
    printf("  sudo cp %s.pcf.gz /usr/share/fonts/misc/\n", font->name);
    printf("  sudo mkfontdir /usr/share/fonts/misc\n");
    printf("  fc-cache -fv\n");
    
    return 0;
}
