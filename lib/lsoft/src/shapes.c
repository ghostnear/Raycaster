#include "shapes.h"

void framebuffer_draw_pixel(Framebuffer* framebuffer, double x, double y, RGBColor color)
{
    if (x >= 0 && x < framebuffer->width && y >= 0 && y < framebuffer->height)
        framebuffer->data[(int)y * framebuffer->width + (int)x] = color;
}

void framebuffer_draw_rect(Framebuffer* framebuffer, double x, double y, double width, double height, RGBColor color)
{
    for (int cy = y; cy < y + height; cy++)
    {
        for (int cx = x; cx < x + width; cx++)
            framebuffer_draw_pixel(framebuffer, cx, cy, color);
    }
}

void framebuffer_draw_circle(Framebuffer* framebuffer, double x, double y, double radius, RGBColor color)
{
    for (int cy = y - radius; cy < y + radius; cy++)
    {
        for (int cx = x - radius; cx < x + radius; cx++)
        {
            double dx = cx - x;
            double dy = cy - y;
            double distance = sqrt(dx * dx + dy * dy);
            if (distance < radius)
                framebuffer_draw_pixel(framebuffer, cx, cy, color);
        }
    }
}
