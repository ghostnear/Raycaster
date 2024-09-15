cmake_minimum_required(VERSION 3.5)

project(WebTest)

set(CMAKE_C_STANDARD 23)

add_subdirectory(lib)

add_executable(
    ${PROJECT_NAME}
    "src/main.c"
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    "inc"
)

find_package(SDL2 CONFIG REQUIRED)
target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE
        LSoft
        $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
        $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>
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