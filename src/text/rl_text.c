#include "../../include/renderline.h"
#include "../core/rl_internal.h"

SDL_Color *rl_convert_rlcolor_to_sdlcolor_i(RL_Color color) {
  SDL_Color *rl_sdl_color_i = (SDL_Color *)malloc(sizeof(SDL_Color) * 1);
  if (rl_sdl_color_i == NULL) {
    return NULL;
  }

  rl_sdl_color_i->r = color.r;
  rl_sdl_color_i->g = color.g;
  rl_sdl_color_i->b = color.b;
  rl_sdl_color_i->a = color.a;

  return rl_sdl_color_i;
}

RL_Font *RL_CreateFont(const char *path, uint8_t size) {
  struct RL_Font *rl_font_i =
      (struct RL_Font *)malloc(sizeof(struct RL_Font) * 1);
  if (rl_font_i == NULL) {
    return NULL;
  }

  return rl_font_i;
}
