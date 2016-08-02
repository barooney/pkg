/*
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

#include <vu/button.h>

vu_button* vu_button_new()
{

}
void vu_button_delete(vu_button* b)
{

}

void vu_button_move(vu_button* b, vec2 pos)
{

}
void vu_button_resize(vu_button* b, vec2 size)
{

}
void vu_button_set_label(vu_button* b, char* label)
{

}
void vu_button_set_label_color(vu_button* b, vec4 color)
{

}
void vu_button_set_font(vu_button* b, asset_hndl f)
{

}
void vu_button_set_onclick(vu_button* b, void(*onclick)(vu_button*, void*))
{

}
void vu_button_set_onclick_data(vu_button* b, void* data)
{

}
void vu_button_set_active(vu_button* b, bool active)
{

}
void vu_button_set_enabled(vu_button* b, bool enabled)
{

}
void vu_button_set_texture(vu_button* b, asset_hndl tex, int width, int height, bool tile)
{

}
void vu_button_disable(vu_button* b)
{

}
void vu_button_enable(vu_button* b)
{

}

vec2 vu_button_position(vu_button* b)
{

}
vec2 vu_button_size(vu_button* b)
{

}

void vu_button_event(vu_button* b, SceCtrlData ctrl)
{

}
void vu_button_update(vu_button* b)
{

}
void vu_button_render(vu_button* b)
{

}

bool vu_button_contains_point(vu_button* b, vec2 pos)
{

}
