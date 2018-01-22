#include <string.h>
#include <stdlib.h>
#include <SDL.h>
#ifndef DRAW_H
#define DRAW_H

typedef struct draw_context
{
    SDL_Window *window;
    SDL_Renderer *renderer;
    unsigned int width;
    unsigned int height;
    int full_screen;
    float delta_time;
    float aspect_ratio;
    unsigned long long last;
} draw_context_t;

typedef struct draw_color
{
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} draw_color_t;

draw_context_t *gfx_init(const char *,unsigned int, unsigned int);
void gfx_destroy(draw_context_t *);
void gfx_blit(draw_context_t *);
void gfx_clear(draw_context_t *, draw_color_t);
void gfx_putPixel(draw_context_t *, int, int, draw_color_t);
#endif