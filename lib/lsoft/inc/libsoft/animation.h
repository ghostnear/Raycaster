#pragma once

#include "framebuffer.h"

typedef struct {
    uintmax_t width;
    uintmax_t height;
    uintmax_t frames;
    Framebuffer* data;
} Animation;

Animation* animation_create(uintmax_t width, uintmax_t height, uintmax_t frames);
void animation_add_frame(Animation* animation, Framebuffer* framebuffer, uintmax_t frame);
void animation_export_ppm(Animation* animation, FILE* output);
