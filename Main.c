#define SDL_MAIN_HANDLED
#include <stdio.h>
#include <math.h>
#include <float.h>
#include "Draw.h"

#define BLACK {0, 0, 0, 255}
#define RED {255, 0, 0, 255}
#define YELLOW {255, 255, 0, 255}
#define GREEN {0, 255, 0, 255}
#define BLUE {0, 0, 255, 255}

draw_color_t black = BLACK;
draw_color_t red = RED;
draw_color_t yellow = YELLOW;
draw_color_t green = GREEN;
draw_color_t blue = BLUE;

int main(int argc, char *argv[])
{
    draw_context_t *context = gfx_init("gfx_PutPixel", 600, 600);

    for(;;)
    {
        gfx_clear(context, black);

        gfx_putPixel(context, 300, 300, red);

         SDL_Event e;
        if (SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                break;
            }
        }
        gfx_blit(context);
    }
    gfx_destroy(context);
    return 0;
}