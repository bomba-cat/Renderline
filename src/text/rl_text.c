#include "../rl_internal.h"

#include <stdlib.h>

SDL_Color rl_convert_rlcolor_to_sdlcolor_i(RL_Color color) {
  SDL_Color rl_sdl_color_i;

  rl_sdl_color_i.r = color.r;
  rl_sdl_color_i.g = color.g;
  rl_sdl_color_i.b = color.b;
  rl_sdl_color_i.a = color.a;

  return rl_sdl_color_i;
}

RL_Font *RL_CreateFont(const char *path, uint8_t size) {
  struct RL_Font *rl_font_i;

  rl_font_i = calloc(1, sizeof *rl_font_i);
  if (rl_font_i == NULL) {
    return NULL;
  }

  rl_font_i->ttf_font = TTF_OpenFont(path, size);
  rl_font_i->size = size;
  /* We can set this standard color
   * to fill the struct with something
   *
   * Though the developer can still change
   * it at any given time themselves, I believe
   * that adding this as a paramater is unecessary bloat*/
  rl_font_i->color = (struct RL_Color){0, 0, 0, 255};

  if (rl_font_i->ttf_font == NULL) {
    RL_DestroyFont(rl_font_i);
    return NULL;
  }

  return rl_font_i;
}

RL_Error RL_WindowSetDefaultFont(RL_Window *window, RL_Font *font) {
  if (window == NULL || font == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  window->default_font = font;

  return RL_OK;
}

RL_Error RL_DestroyFont(RL_Font *font) {
  if (font == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  if (font->ttf_font != NULL) {
    TTF_CloseFont(font->ttf_font);
  }
  free(font);
  return RL_OK;
}

RL_Error RL_FontSetColor(RL_Font *font, RL_Color color) {
  if (font == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  font->color = color;
  return RL_OK;
}

RL_Color RL_FontGetColor(const RL_Font *font) {
  if (font == NULL) {
    return (RL_Color){0, 0, 0, 0};
  }

  return font->color;
}

uint8_t RL_FontGetSize(const RL_Font *font) {
  if (font == NULL) {
    return 0;
  }

  return font->size;
}

RL_Font *RL_WindowGetDefaultFont(const RL_Window *window) {
  if (window == NULL) {
    return NULL;
  }

  return window->default_font;
}
