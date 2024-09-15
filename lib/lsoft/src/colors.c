#include "colors.h"

RGBColor color_scale(RGBColor color, double scale)
{
    return (RGBColor){
        .r = color.r * scale,
        .g = color.g * scale,
        .b = color.b * scale
    };
}
