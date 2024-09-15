#include "animation.h"
#include "framebuffer.h"

#include <stdint.h>
#include <stdlib.h>

Animation* animation_create(uintmax_t width, uintmax_t height, uintmax_t frames)
{
    Animation* animation = malloc(sizeof(Animation));
    animation->width = width;
    animation->height = height;
    animation->frames = frames;
    animation->data = calloc(sizeof(Framebuffer), frames);
    return animation;
}

void animation_add_frame(Animation* animation, Framebuffer* framebuffer, uintmax_t frame)
{
    animation->data[frame].width = framebuffer->width;
    animation->data[frame].height = framebuffer->height;

    animation->data[frame].data = calloc(sizeof(RGBColor), framebuffer->width * framebuffer->height);
    for (uintmax_t y = 0; y < framebuffer->height; y++)
        for (uintmax_t x = 0; x < framebuffer->width; x++)
            animation->data[frame].data[y * framebuffer->width + x] = framebuffer->data[y * framebuffer->width + x];
}

void animation_export_ppm(Animation* animation, FILE* output)
{
    fprintf(output, "P6\n%ju %ju\n255\n", animation->width, animation->height);
    for (uintmax_t frame = 0; frame < animation->frames; frame++)
    {
        for (uintmax_t y = 0; y < animation->height; y++)
        {
            for (uintmax_t x = 0; x < animation->width; x++)
            {
                RGBColor color = animation->data[frame].data[y * animation->width + x];
                fputc(color.r, output);
                fputc(color.g, output);
                fputc(color.b, output);
            }
        }
    }
}
