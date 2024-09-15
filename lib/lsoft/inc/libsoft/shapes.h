#pragma once

#include "framebuffer.h"

#include <math.h>

void framebuffer_draw_pixel(Framebuffer* framebuffer, double x, double y, RGBColor color);
void framebuffer_draw_rect(Framebuffer* framebuffer, double x, double y, double width, double height, RGBColor color);
void framebuffer_draw_circle(Framebuffer* framebuffer, double x, double y, double radius, RGBColor color);
