cmake_minimum_required(VERSION 3.15)

project(
	Renderline
	VERSION 0.1
	DESCRIPTION "A simple, portable C library for building visual novels across multiple platforms."
	LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(RENDERLINE_SOURCES
	src/audio/rl_audio.c
	src/core/renderline.c
	src/io/rl_file.c
	src/render/rl_sprite.c
	src/render/rl_surface.c
	src/text/rl_text.c
)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} include)

add_library(Renderline SHARED
	${RENDERLINE_SOURCES}
)

target_link_libraries(Renderline
	PRIVATE
	SDL2::SDL2
)

target_include_directories(Renderline PUBLIC include)
