#include <malloc.h>
#include <string.h>
#include <math.h>
#include <vu/text.h>

vu_text* vu_text_new()
{
    vu_text *t = malloc(sizeof(vu_text));
    t->font.pgf = vita2d_load_default_pgf();
    return t;
}

vu_text* vu_text_new_string(char* string)
{
    vu_text *t = vu_text_new();
    t->string = strdup(string);
    return t;
}

void vu_text_delete(vu_text* t)
{
    if (!t)
        return;
    if (t->string)
        free(t->string);
    if (t->font) {
        switch (t->font.type) {
        case FONT_PGF:
            vita2d_free_pgf(t->font.pgf);
            break;
        case FONT_PVF:
            /* XXX: not implemented in libvita2d */
            break;
        case FONT_FREETYPE:
            vita2d_free_font(t->font.ft);
            break;
        }
    }
    free(t);
}

void vu_text_move(vu_text* t, vec2 pos)
{
    if (!t)
        return;
    t->top_left = pos;
}

void vu_text_set_font(vu_text* t, vu_font *font)
{
    memmove(t->font, font, sizeof(vu_font));
}

void vu_text_set_color(vu_text* t, vec4 color)
{
    t->color = VEC4_TO_RGBA8(color);
}

void vu_text_set_scale(vu_text* t, float scale)
{
    t->scale = scale;
}

void vu_text_align(vu_text* t, int halign, int valign)
{
    t->halign = halign;
    t->valign = valign;
}

void vu_text_draw(vu_text* t)
{
    if (!t || !t->font || !t->string)
        return;

    switch (t->font.type) {
    case FONT_PGF:
        vita2d_pgf_draw_text(t->font.pgf, t->top_left.x, t->top_left->y,
                             t->color, t->scale, t->string);
        break;
    case FONT_PVF:
        /* XXX: not implemented in libvita2d */
        break;
    case FONT_FREETYPE:
        vita2d_font_draw_text(t->font.tf, t->top_left.x, t->top_left->y,
                              t->color, llrint(t->scale*10), t->string);
        break;
    }
}

void vu_text_draw_string(vu_text* t, char* string)
{

}

bool vu_text_contains_point(vu_text* t, vec2 pos)
{
    if (!t)
        return false;
    if (pos.x >= t->top_left.x &&
        pos.y >= t->top_left.y &&
        pos.x <= t->bottom_right.x &&
        pos.y <= t->bottom_right.y)
        return true;
    return false;
}

