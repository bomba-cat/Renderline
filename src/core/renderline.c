#include "../../include/renderline.h"
#include "rl_internal.h"

RL_Error RL_Init() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    return RL_UNDEFINED_ERROR;
  }
  if (TTF_Init() != 0) {
    SDL_Quit();
    return RL_UNDEFINED_ERROR;
  }
  return RL_OK;
}

RL_Error RL_Quit() {
  TTF_Quit();
  SDL_Quit();
  return RL_OK;
}

RL_Error rl_draw_hint_i(RL_Window *window) { return RL_OK; }

RL_Window *RL_CreateWindow(RL_GameInfo *gameinfo, int width, int height) {
  if (gameinfo == NULL || width <= 0 || height <= 0) {
    return NULL;
  } else if (gameinfo->name == NULL) {
    return NULL;
  }

  struct RL_Window *rl_window_i =
      (struct RL_Window *)malloc(sizeof(struct RL_Window));
  if (rl_window_i == NULL) {
    return NULL;
  }

  rl_window_i->sdl_window = SDL_CreateWindow(
      gameinfo->name, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width,
      height, SDL_WINDOW_SHOWN);
  rl_window_i->title = strdup(gameinfo->name);

  if (rl_window_i->sdl_window == NULL ||
      strcmp(rl_window_i->title, gameinfo->name)) {
    RL_DestroyWindow(rl_window_i);
    return NULL;
  }
  return rl_window_i;
}

RL_Error RL_DestroyWindow(RL_Window *window) {
  if (window == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  SDL_DestroyWindow(window->sdl_window);
  free(window->title);
  free(window);
  window = NULL;

  return RL_OK;
}

RL_GameInfo *RL_CreateGameInfo(char *name, char *description, char *version) {
  if (description == NULL || name == NULL || version == NULL) {
    return NULL;
  }

  struct RL_GameInfo *rl_gameinfo_i =
      (struct RL_GameInfo *)malloc(sizeof(struct RL_GameInfo));
  if (rl_gameinfo_i == NULL) {
    return NULL;
  }

  rl_gameinfo_i->description = strdup(description);
  rl_gameinfo_i->name = strdup(name);
  rl_gameinfo_i->version = strdup(version);

  if (strcmp(rl_gameinfo_i->description, description) ||
      strcmp(rl_gameinfo_i->name, name) ||
      strcmp(rl_gameinfo_i->version, version)) {
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
  gameinfo = NULL;

  return RL_OK;
}
