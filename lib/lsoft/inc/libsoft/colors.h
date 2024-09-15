#pragma once

#include <stdint.h>

typedef struct {
    uint8_t r;
    uint8_t g;
    uint8_t b;
} __attribute__((packed)) RGBColor;

RGBColor color_scale(RGBColor color, double scale);

static const RGBColor COLOR_WHITE = {.r = 255, .g = 255, .b = 255};
static const RGBColor COLOR_RED = {.r = 255, .g = 0, .b = 0};
