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

#ifndef __VU_LISTBOX_H
#define __VU_LISTBOX_H

#include <vu/rectangle.h>
#include <vu/text.h>
#include <vu/vec.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  
  vu_rectangle* back;
  
  int scroll;  
  int num_items;
  vu_text** items;
  
  bool active;
  void (*onselect)(vu_text* entry);
  
} vu_listbox;

vu_listbox* vu_listbox_new();
void vu_listbox_delete(vu_listbox* lb);

void vu_listbox_clear(vu_listbox* lb);
vu_text* vu_listbox_add_item(vu_listbox* lb, char* item);

void vu_listbox_move(vu_listbox* lb, vec2 pos);
void vu_listbox_resize(vu_listbox* lb, vec2 size);

void vu_listbox_event(vu_listbox* lb, SceCtrlData ctrl);
void vu_listbox_update(vu_listbox* lb);
void vu_listbox_render(vu_listbox* lb);

void vu_listbox_set_onselect(vu_listbox* lb, void (*onselect)(vu_text* entry));

#endif