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

#ifndef __VU_BROWSER_H
#define __VU_BROWSER_H

#include <vu/rectangle.h>
#include <vu/text.h>
#include <vu/listbox.h>

#include <stdbool.h>
#include <psp2/ctrl.h>

typedef struct {
  
  vu_rectangle* outer;
  vu_listbox* inner;
  
  fpath directory;
    
  bool active;
    
} vu_browser;

vu_browser* vu_browser_new();
void vu_browser_delete(vu_browser* b);

void vu_browser_chdir(vu_browser* b, fpath dir);

void vu_browser_event(vu_browser* b, SceCtrlData ctrl);
void vu_browser_update(vu_browser* b);
void vu_browser_render(vu_browser* b);

#endif