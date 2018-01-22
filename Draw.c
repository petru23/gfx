#define SDL_MAIN_HANDLED 1
#include <SDL.h>
#include "Draw.h"

draw_context_t *gfx_init(const char *title, unsigned int width, unsigned int height)
{
    draw_context_t *context = malloc(sizeof(draw_context_t));
    if (!context)
        return NULL;

    if (SDL_Init(SDL_INIT_VIDEO))
        return NULL;

    context->window = SDL_CreateWindow(title,
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            width,
            height,
            0);

    if (!context->window)
    {
        SDL_Quit();
        free(context);
        return NULL;
    }

    context->renderer = SDL_CreateRenderer(context->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(!context->renderer)
    {
        SDL_DestroyWindow(context->window);
        SDL_Quit();
        free(context);
        return NULL;
    }

    context->delta_time      = 0;
    context->width           = width;
    context->height          = height;
    context->aspect_ratio    = (float)width / (float)height;
    context->last = SDL_GetPerformanceCounter();

    return context;
}

void gfx_destroy(draw_context_t *context)
{
    SDL_DestroyRenderer(context->renderer);
   
    SDL_DestroyWindow(context->window);

    SDL_Quit();

    free(context);
}

void gfx_blit(draw_context_t *context)
{
    SDL_RenderPresent(context->renderer);
    unsigned long long now = SDL_GetPerformanceCounter();
    context->delta_time = (float)(now - context->last) / SDL_GetPerformanceFrequency();
    context->last = now;
}

void gfx_clear(draw_context_t *context, draw_color_t color)
{
    SDL_SetRenderDrawColor(context->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderClear(context->renderer);
}

void gfx_putPixel(draw_context_t *context, int x, int y, draw_color_t color)
{
    if (color.r > 255)
        color.r = 255;

    if (color.g > 255)
        color.g = 255;

    if (color.b > 255)
        color.b = 255;

    if (color.a > 255)
        color.a = 255;

    SDL_SetRenderDrawColor(context->renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(context->renderer, x, y);
}