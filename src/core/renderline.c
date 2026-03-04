#include "../rl_internal.h"

#include <stdlib.h>
#include <string.h>

char *rl_strdup_i(const char *value) {
  size_t value_length;
  char *copy;

  if (value == NULL) {
    return NULL;
  }

  value_length = strlen(value) + 1;
  copy = malloc(value_length);
  if (copy == NULL) {
    return NULL;
  }

  memcpy(copy, value, value_length);
  return copy;
}

RL_Error RL_Init(void) {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    return RL_UNDEFINED_ERROR;
  }
  if (TTF_Init() != 0) {
    SDL_Quit();
    return RL_UNDEFINED_ERROR;
  }
  return RL_OK;
}

RL_Error RL_Quit(void) {
  TTF_Quit();
  SDL_Quit();
  return RL_OK;
}

RL_Window *RL_CreateWindow(const RL_GameInfo *gameinfo, int width, int height) {
  struct RL_Window *rl_window_i;

  if (gameinfo == NULL || width <= 0 || height <= 0) {
    return NULL;
  }
  if (gameinfo->name == NULL) {
    return NULL;
  }

  rl_window_i = calloc(1, sizeof *rl_window_i);
  if (rl_window_i == NULL) {
    return NULL;
  }

  rl_window_i->sdl_window = SDL_CreateWindow(
      gameinfo->name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
      height, SDL_WINDOW_SHOWN);
  if (rl_window_i->sdl_window == NULL) {
    RL_DestroyWindow(rl_window_i);
    return NULL;
  }

  rl_window_i->sdl_renderer =
      SDL_CreateRenderer(rl_window_i->sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (rl_window_i->sdl_renderer == NULL) {
    RL_DestroyWindow(rl_window_i);
    return NULL;
  }

  /* Explicitly set this to NULL for now
   * TODO: Maybe create a real standard font*/
  rl_window_i->default_font = NULL;
  rl_window_i->width = width;
  rl_window_i->height = height;

  rl_window_i->title = rl_strdup_i(gameinfo->name);
  if (rl_window_i->title == NULL) {
    RL_DestroyWindow(rl_window_i);
    return NULL;
  }
  return rl_window_i;
}

RL_Error RL_DestroyWindow(RL_Window *window) {
  if (window == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  if (window->sdl_renderer != NULL) {
    SDL_DestroyRenderer(window->sdl_renderer);
  }
  if (window->sdl_window != NULL) {
    SDL_DestroyWindow(window->sdl_window);
  }
  free(window->title);
  free(window);

  return RL_OK;
}

RL_GameInfo *RL_CreateGameInfo(const char *name, const char *description,
                               const char *version) {
  struct RL_GameInfo *rl_gameinfo_i;

  if (description == NULL || name == NULL || version == NULL) {
    return NULL;
  }

  rl_gameinfo_i = calloc(1, sizeof *rl_gameinfo_i);
  if (rl_gameinfo_i == NULL) {
    return NULL;
  }

  rl_gameinfo_i->description = rl_strdup_i(description);
  rl_gameinfo_i->name = rl_strdup_i(name);
  rl_gameinfo_i->version = rl_strdup_i(version);

  if (rl_gameinfo_i->description == NULL || rl_gameinfo_i->name == NULL ||
      rl_gameinfo_i->version == NULL) {
    RL_DestroyGameInfo(rl_gameinfo_i);
    return NULL;
  }

  return rl_gameinfo_i;
}

RL_Error RL_DestroyGameInfo(RL_GameInfo *gameinfo) {
  if (gameinfo == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  free(gameinfo->description);
  free(gameinfo->name);
  free(gameinfo->version);
  free(gameinfo);

  return RL_OK;
}

const char *RL_GameInfoGetName(const RL_GameInfo *gameinfo) {
  if (gameinfo == NULL) {
    return NULL;
  }

  return gameinfo->name;
}

const char *RL_GameInfoGetDescription(const RL_GameInfo *gameinfo) {
  if (gameinfo == NULL) {
    return NULL;
  }

  return gameinfo->description;
}

const char *RL_GameInfoGetVersion(const RL_GameInfo *gameinfo) {
  if (gameinfo == NULL) {
    return NULL;
  }

  return gameinfo->version;
}

const char *RL_WindowGetTitle(const RL_Window *window) {
  if (window == NULL) {
    return NULL;
  }

  return window->title;
}

int RL_WindowGetWidth(const RL_Window *window) {
  if (window == NULL) {
    return 0;
  }

  return window->width;
}

int RL_WindowGetHeight(const RL_Window *window) {
  if (window == NULL) {
    return 0;
  }

  return window->height;
}
