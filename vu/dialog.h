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

#ifndef __VU_DIALOG_H
#define __VU_DIALOG_H

#include <vu/text.h>
#include <vu/button.h>

#include <stdbool.h>
#include <psp2/ctrl.h>
 
extern int dialog_count;

typedef struct {
  
  vu_button* back;
  vu_text* title;
  vu_text* contents;
  
  bool single_button;
  
  vu_button* left;
  vu_button* right;

} vu_dialog;

vu_dialog* vu_dialog_new();
void vu_dialog_delete(vu_dialog* d);

void vu_dialog_set_single_button(vu_dialog* d, bool single);
void vu_dialog_set_title(vu_dialog* d, char* title);
void vu_dialog_set_contents(vu_dialog* d, char* contents);
void vu_dialog_set_button_left(vu_dialog* d, char* left, void (*onleft)(vu_button*, void*));
void vu_dialog_set_button_right(vu_dialog* d, char* right, void (*onright)(vu_button*, void*));
void vu_dialog_set_font(vu_dialog* d, asset_hndl fnt);

void vu_dialog_event(vu_dialog* d, SceCtrlData ctrl);
void vu_dialog_update(vu_dialog* d);
void vu_dialog_render(vu_dialog* d);

#endif