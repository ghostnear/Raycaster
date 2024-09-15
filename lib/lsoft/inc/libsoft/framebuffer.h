#pragma once

#include "colors.h"

#include <stdint.h>
#include <stdio.h>

typedef struct {
    uintmax_t width;
    uintmax_t height;
    RGBColor* data;
} Framebuffer;

Framebuffer* framebuffer_create(uintmax_t width, uintmax_t height);
void framebuffer_destroy(Framebuffer* framebuffer);
void framebuffer_clear(Framebuffer* framebuffer, RGBColor color);
void framebuffer_export_ppm(Framebuffer* framebuffer, FILE* output);
