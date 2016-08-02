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

#ifndef __VU_OPTION_H
#define __VU_OPTION_H

#include <vu/button.h>
#include <vu/vec.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct vu_option {
  vu_button* label;
  int num_options;
  vu_button** options;
  bool active;
  int selected;
  void (*onselect)(struct vu_option*);
} vu_option;

vu_option* vu_option_new(void);
void vu_option_delete(vu_option* o);

void vu_option_set_active(vu_option* o, bool active);
void vu_option_move(vu_option* o, vec2 position);
void vu_option_set_options(vu_option* o, char* label, int num, char** values);
int  vu_option_get_selected(vu_option* o);
void vu_option_set_selected(vu_option* o, int selected);
void vu_option_set_onselect(vu_option* o, void(*onselect)(vu_option*));

void vu_option_deactivate(vu_option* o);
void vu_option_activate(vu_option* o);

void vu_option_event(vu_option* o, SceCtrlData ctrl);
void vu_option_update(vu_option* o);
void vu_option_render(vu_option* o);

#endif
