cmake_minimum_required(VERSION 3.5)

project(LSoft)

set(CMAKE_C_STANDARD 23)

add_library(
    LSoft
    "src/framebuffer.c"
    "src/animation.c"
    "src/shapes.c"
    "src/colors.c"
)

target_include_directories(
    LSoft
    PUBLIC
    "inc"
    PRIVATE
    "inc/libsoft"
)

target_compile_options(
    ${PROJECT_NAME}
    PRIVATE
    -Wall
    -Wextra
    -Wpedantic
    -Werror
    -Wno-deprecated-declarations
)