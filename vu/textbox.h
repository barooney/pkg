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

#ifndef __VU_TEXTBOX_H
#define __VU_TEXTBOX_H

#include <vu/rectangle.h>
#include <vu/text.h>
#include <vu/vec.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  
  vu_rectangle* outer;
  vu_rectangle* inner;
  
  vu_text* contents;
  vu_text* label;
  
  bool password;
  int max_chars;
  
  bool selected;
  bool active;
  bool enabled;
  
} vu_textbox;

vu_textbox* vu_textbox_new();
void vu_textbox_delete(vu_textbox* tb);

void vu_textbox_set_password(vu_textbox* tb, bool password);
void vu_textbox_set_max_chars(vu_textbox* tb, int l);
void vu_textbox_addchar(vu_textbox* tb, char c);
void vu_textbox_rmchar(vu_textbox* tb);

void vu_textbox_move(vu_textbox* tb, vec2 pos);
void vu_textbox_resize(vu_textbox* tb, vec2 size);

void vu_textbox_set_font(vu_textbox* tb, asset_hndl f);
void vu_textbox_set_label(vu_textbox* tb, char* label);
void vu_textbox_set_contents(vu_textbox* tb, char* label);
void vu_textbox_set_alignment(vu_textbox* tb, int halign, int valign);

void vu_textbox_disable(vu_textbox* tb);
void vu_textbox_enable(vu_textbox* tb);

void vu_textbox_event(vu_textbox* tb, SceCtrlData ctrl);
void vu_textbox_update(vu_textbox* tb);
void vu_textbox_render(vu_textbox* tb);

bool vu_textbox_contains_point(vu_textbox* tb, vec2 p);

#endif