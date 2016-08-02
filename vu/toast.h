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

#ifndef __VU_TOAST_H
#define __VU_TOAST_H

#include <vu/text.h>
#include <vu/rectangle.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {

  vu_text* label;  
  float opacity;
  bool active;
  
} vu_toast;

void vu_toast_popup(char* fmt, ...);

vu_toast* vu_toast_new();
void vu_toast_delete(vu_toast* t);

void vu_toast_set_label(vu_toast* t, char* label);
void vu_toast_set_font(vu_toast* t, asset_hndl f);

void vu_toast_event(vu_toast* t, SceCtrlData ctrl);
void vu_toast_update(vu_toast* t);
void vu_toast_render(vu_toast* t);

#endif
