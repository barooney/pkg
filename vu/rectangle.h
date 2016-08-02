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

#ifndef __VU_RECTANGLE_H
#define __VU_RECTANGLE_H

#include <vu/vec.h>
#include <vita2d.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  vec2 top_left;
  vec2 bottom_right;
  
  unsigned int color;
  vita2d_texture texture;
  int texture_width;
  int texture_height;
  bool texture_tile;
  
  float border_size;
  vec4 border_color;
  
  float glitch;
  float time;
  
//  GLenum blend_src;
//  GLenum blend_dst;
  
  bool active;
  
} vu_rectangle;

vu_rectangle* vu_rectangle_new();
void vu_rectangle_delete(vu_rectangle* r);

void vu_rectangle_move(vu_rectangle* r, vec2 pos);
void vu_rectangle_resize(vu_rectangle* r, vec2 size);
void vu_rectangle_set_texture(vu_rectangle* r, vita2d_texture tex, int width, int height, bool tile);
void vu_rectangle_set_border(vu_rectangle* r, float size, vec4 color);
void vu_rectangle_set_color(vu_rectangle* r, vec4 color);
vec2 vu_rectangle_center(vu_rectangle* r);
bool vu_rectangle_contains_point(vu_rectangle* r, vec2 pos);
//void vu_rectangle_blend(vu_rectangle* r, GLenum blend_src, GLenum blend_dst);

vec2 vu_rectangle_position(vu_rectangle* r);
vec2 vu_rectangle_size(vu_rectangle* r);

#endif
