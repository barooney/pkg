#include <malloc.h>
#include <vu/rectangle.h>

vu_rectangle* vu_rectangle_new()
{
    vu_rectangle *r = malloc(sizeof(vu_rectangle));
    r->top_left = (vec2){0,0};
    r->bottom_right = (vec2){0,0};
    return r;
}

void vu_rectangle_delete(vu_rectangle* r)
{
    if (r)
        free(r);
}

void vu_rectangle_render(vu_rectangle* r)
{
    if (!r || !r->active)
        return;
    vec2 size = vu_rectangle_size(r);
    vita2d_draw_rectangle(r->top_left.x, r->top_left.y, size.x, size.y, r->color);
}

void vu_rectangle_move(vu_rectangle* r, vec2 pos)
{
    if (!r) 
        return;
    vec2 size = vu_rectangle_size(r);
    r->top_left = pos;
    r->bottom_right = VEC2_ADD(pos, size);
}

void vu_rectangle_resize(vu_rectangle* r, vec2 size)
{
   if (!r)
       return;
   r->bottom_right = VEC2_ADD(r->top_left, size); 
}

void vu_rectangle_set_texture(vu_rectangle* r, vita2d_texture tex, int width, int height, bool tile)
{

}

void vu_rectangle_set_border(vu_rectangle* r, float size, vec4 color)
{

}

void vu_rectangle_set_color(vu_rectangle* r, vec4 color)
{
    r->color = VEC4_TO_RGBA8(color);
}

vec2 vu_rectangle_center(vu_rectangle* r)
{
    if (!r)
        return (vec2){0,0};
    return (vec2){(r->bottom_right.x + r->top_left.x) / 2, (r->bottom_right.y + r->top_left.y) / 2};
}

bool vu_rectangle_contains_point(vu_rectangle* r, vec2 pos)
{
    if (!r)
        return false;
    if (pos.x >= r->top_left.x &&
        pos.y >= r->top_left.y &&
        pos.x <= r->bottom_right.x &&
        pos.y <= r->bottom_right.y)
        return true;
    return false;
}

//void vu_rectangle_blend(vu_rectangle* r, GLenum blend_src, GLenum blend_dst)
//{
//
//}

vec2 vu_rectangle_position(vu_rectangle* r)
{
    if (!r)
        return (vec2){0,0};
    return r->top_left;
}

vec2 vu_rectangle_size(vu_rectangle* r)
{
    if (!r)
        return (vec2){0,0};
    return VEC2_SUB(r->bottom_right, r->top_left);
}
