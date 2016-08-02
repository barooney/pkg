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

#ifndef __VU_VEC_H
#define __VU_VEC_H

#define VEC2(name, type)  typedef struct name \
                          {                   \
                            type x;           \
                            type y;           \
                          } name


VEC2(vec2, int);
VEC2(vecf2, float);
VEC2(vecd2, double);

#define VEC4(name, type)  typedef struct name \
                          {                   \
                            type x;           \
                            type y;           \
                            type z;           \
                            type w;           \
                          } name

VEC4(vec4, int);
VEC4(vecf4, float);
VEC4(vecd4, double);

#define VEC4_TO_RGBA8(r) ((((r.x)&0xFF)<<24) | (((r.y)&0xFF)<<16) | (((r.z)&0xFF)<<8) | (((r.w)&0xFF)<<0))

#define VEC2_ADD(a, b) (vec2){a.x + b.x, a.y + b.y}
#define VECF2_ADD(a, b) (vecf2){a.x + b.x, a.y + b.y}
#define VECD2_ADD(a, b) (vecd2){a.x + b.x, a.y + b.y}

#define VEC2_SUB(a, b) (vec2){a.x - b.x, a.y - b.y}
#define VECF2_SUB(a, b) (vecf2){a.x - b.x, a.y - b.y}
#define VECD2_SUB(a, b) (vecd2){a.x - b.x, a.y - b.y}

#define VEC4_ADD(a, b) (vec4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w }
#define VECF4_ADD(a, b) (vecf4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w }
#define VECD4_ADD(a, b) (vecd4){a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w }

#define VEC4_SUB(a, b) (vec4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w }
#define VECF4_SUB(a, b) (vecf4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w }
#define VECD4_SUB(a, b) (vecd4){a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w }

#endif
