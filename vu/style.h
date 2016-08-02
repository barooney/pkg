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

#ifndef __VU_STYLE_H
#define __VU_STYLE_H

#include <vu/text.h>
#include <vu/vec.h>

typedef struct {
  
  /* Box */
  
  fpath box_back_image;
  int   box_back_width;
  int   box_back_height;
  bool  box_back_tile;
  int   box_back_border_size;
  vec4  box_back_border_color;
  float box_glitch;
  int   box_blend_src;
  int   box_blend_dst;
  
  vec4 box_text_color;
  vec4 box_label_color;
  int  box_text_halign;
  int  box_text_valign;
  vec4 box_up_color;
  vec4 box_down_color;
  vec4 box_inset_color;
  
  /* Text  */
  
  fpath text_font;
  vec4  text_color;
  vec2  text_scale;
  
  /* Spinner */
  
  fpath spinner_image;
  float spinner_speed;

} vu_style;

/* Current */

extern vu_style* vu_style_current;

/* Defaults */

extern vu_style vu_style_corange;
extern vu_style vu_style_hunt;

#endif