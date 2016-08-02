/*
 * Based on the Corange UI API.
 * Copyright (c) 2010 Daniel Holden
 * Copyright (c) 2016 Josh de Kock
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons to whom the Software is furnished to do
 * so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __VU_TEXT_H
#define __VU_TEXT_H

#include <stdbool.h>

#include <vu/vec.h>
#include <vu/font.h>

enum {
  TEXT_ALIGN_LEFT   = 0,
  TEXT_ALIGN_RIGHT  = 1,
  TEXT_ALIGN_CENTER = 2,
};

enum {
  TEXT_ALIGN_TOP    = 0,
  TEXT_ALIGN_BOTTOM = 1,
};

typedef struct {
  
  /* private */
  char* string;
  
  //GLuint positions_buffer;
  //GLuint texcoords_buffer;
  //GLuint colors_buffer;
  
  int num_positions;
  int num_texcoords;
  
  vec2 top_left;
  vec2 bottom_right;
  
  /* public */
  vu_font *font;  
  
  vec2 position;
  float scale;
  int color;
  
  int halign;
  int valign;
  
  float line_spacing;
  float char_spacing;
  float rotation;
  
  float line_length;
  
  bool active;
  
} vu_text;

vu_text* vu_text_new();
vu_text* vu_text_new_string(char* string);
void vu_text_delete(vu_text* t);

void vu_text_move(vu_text* t, vec2 pos);
void vu_text_set_font(vu_text* t, vu_font *font);
void vu_text_set_color(vu_text* t, vec4 color);
void vu_text_set_scale(vu_text* t, float scale);
void vu_text_align(vu_text* t, int halign, int valign);

void vu_text_draw(vu_text* t);
void vu_text_draw_string(vu_text* t, char* string);

bool vu_text_contains_point(vu_text* t, vec2 pos);

#endif
