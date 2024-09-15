#include "libsoft/all.h"

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

int main()
{
    auto framebuffer = framebuffer_create(128, 128);

    double player_x = 3.5;
    double player_y = 2.5;
    double player_a = acos(-1) / 2;
    double fov = acos(-1) / 2.5;

    const char map[] = "0000222222220000"\
                       "1              0"\
                       "1      11111   0"\
                       "1     0        0"\
                       "0     0  1110000"\
                       "0     3        0"\
                       "0   10000      0"\
                       "0   0   11100  0"\
                       "0   0   0      0"\
                       "0   0   1  00000"\
                       "0       1      0"\
                       "2       1      0"\
                       "0       0      0"\
                       "0 0000000      0"\
                       "0              0"\
                       "0002222222200000";

    SDL_Window* window = SDL_CreateWindow("Raycaster", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, framebuffer->width * 6, framebuffer->height * 6, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_RenderSetLogicalSize(renderer, framebuffer->width, framebuffer->height);
    bool running = true;

    while(running)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
        {
            if(event.type == SDL_QUIT)
            {
                running = false;
            }
            if(event.type == SDL_KEYDOWN)
            {
                if(event.key.keysym.sym == SDLK_ESCAPE)
                {
                    running = false;
                }
                if(event.key.keysym.sym == SDLK_w)
                {
                    player_x += 1 * cos(player_a);
                    player_y += 1 * sin(player_a);
                }
                if(event.key.keysym.sym == SDLK_s)
                {
                    player_x -= 1 * cos(player_a);
                    player_y -= 1 * sin(player_a);
                }
                if(event.key.keysym.sym == SDLK_a)
                {
                    player_a += acos(-1) / 2;
                }
                if(event.key.keysym.sym == SDLK_d)
                {
                    player_a -= acos(-1) / 2;
                }
            }
        }

        framebuffer_clear(framebuffer, COLOR_WHITE);
        for(uintmax_t index = 0; index < framebuffer->width; index++)
        {
            float angle = player_a - fov / 2 + fov * index / framebuffer->width;

            double step = 0.5;
            while(step < 300)
            {
                double x = player_x + step * cos(angle);
                double y = player_y + step * sin(angle);

                if(map[(int)y * 16 + (int)x] != ' ')
                {
                    double size = framebuffer->width / (step * cos(angle - player_a)) ;
                    framebuffer_draw_rect(
                        framebuffer, 
                        index, framebuffer->width / 2 - size / 2, 1, size, 
                        color_scale(COLOR_RED, 1 / (1 + step * step / 10))
                    );
                    break;
                }

                step += 1.0 / framebuffer->width;
            }
        }

        SDL_RenderClear(renderer);
        for(uintmax_t y = 0; y < framebuffer->height; y++)
        {
            for(uintmax_t x = 0; x < framebuffer->width; x++)
            {
                SDL_SetRenderDrawColor(renderer, framebuffer->data[y * framebuffer->width + x].r, framebuffer->data[y * framebuffer->width + x].g, framebuffer->data[y * framebuffer->width + x].b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    framebuffer_destroy(framebuffer);

    return 0;
}
