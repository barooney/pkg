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

#ifndef __VU_SPINNER_H
#define __VU_SPINNER_H

#include <vu/vec.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  vec2 top_left;
  vec2 bottom_right;
  
  vec4 color;
  asset_hndl texture;
  
  float speed;
  float rotation;
  
  bool active;
} vu_spinner;

vu_spinner* vu_spinner_new();
void vu_spinner_delete(vu_spinner* s);

void vu_spinner_event(vu_spinner* s, SceCtrlData ctrl);
void vu_spinner_update(vu_spinner* s);
void vu_spinner_render(vu_spinner* s);


#endif
