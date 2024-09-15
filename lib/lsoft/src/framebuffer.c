#include "framebuffer.h"

#include <stdlib.h>

Framebuffer* framebuffer_create(uintmax_t width, uintmax_t height)
{
    Framebuffer* framebuffer = (Framebuffer*)malloc(sizeof(Framebuffer));
    framebuffer->width = width;
    framebuffer->height = height;
    framebuffer->data = (RGBColor*)calloc(width * height, sizeof(RGBColor));
    return framebuffer;
}

void framebuffer_destroy(Framebuffer* framebuffer)
{
    free(framebuffer->data);
    free(framebuffer);
}

void framebuffer_clear(Framebuffer* framebuffer, RGBColor color)
{
    for (uintmax_t index = 0; index < framebuffer->height * framebuffer->width; index++)
        framebuffer->data[index] = color;
}

void framebuffer_export_ppm(Framebuffer* framebuffer, FILE* output)
{
    fprintf(output, "P6\n%ju %ju\n255\n", framebuffer->width, framebuffer->height);
    fwrite(framebuffer->data, sizeof(RGBColor), framebuffer->width * framebuffer->height, output);
}
