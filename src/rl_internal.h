#ifndef RL_INTERNAL_H
#define RL_INTERNAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include <stddef.h>

#include "renderline/renderline.h"

typedef struct RL_MenuEntryInternal {
  char *label;
  RL_MenuCallback callback;
  void *userdata;
} RL_MenuEntryInternal;

struct RL_GameInfo {
  char *name;
  char *description;
  char *version;
};

struct RL_Font {
  TTF_Font *ttf_font;
  uint8_t size;
  RL_Color color;
};

struct RL_Window {
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  RL_Font *default_font;
  char *title;
  int width;
  int height;
};

struct RL_Menu {
  RL_MenuEntryInternal *entries;
  size_t entry_count;
  size_t entry_capacity;
  const RL_MenuRenderer *renderer;
  void *renderer_userdata;
};

char *rl_strdup_i(const char *value);
SDL_Color rl_convert_rlcolor_to_sdlcolor_i(RL_Color color);

#endif
