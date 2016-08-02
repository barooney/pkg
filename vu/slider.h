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

#ifndef __VU_SLIDER_H
#define __VU_SLIDER_H

#include <vu/rectangle.h>
#include <vu/button.h>
#include <vu/vec.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  
  vu_button* label;

  vu_rectangle* slot;
  vu_rectangle* bar;  

  bool pressed;
  bool active;
  float amount;
  
} vu_slider;

vu_slider* vu_slider_new(void);
void vu_slider_delete(vu_slider* s);

void vu_slider_set_label(vu_slider* s, char* label);
void vu_slider_move(vu_slider* s, vec2 position);
void vu_slider_set_amount(vu_slider* s, float amount);
float vu_slider_get_amount(vu_slider* s);
void vu_slider_set_active(vu_slider* s, bool active);

void vu_slider_deactivate(vu_slider* s);
void vu_slider_activate(vu_slider* s);

void vu_slider_event(vu_slider* s, SceCtrlData ctrl);
void vu_slider_update(vu_slider* s);
void vu_slider_render(vu_slider* s);

#endif
