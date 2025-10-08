#ifndef RENDERLINE_H
#define RENDERLINE_H

#include <SDL2/SDL.h>

typedef struct RL_GameInfo {
  char *name;
  char *description;
  char *version; /* The reason this is kept as a character is
                  * for games going with versions like: 0.1.2 */
} RL_GameInfo;

typedef struct RL_Window {
  SDL_Window *sdl_window;
  char *title;
} RL_Window;

typedef enum {
  RL_OK = 0,
  RL_UNDEFINED_ERROR = 1,
} RL_Error;

RL_Error RL_Init();
RL_Window *RL_CreateWindow(RL_GameInfo *gameinfo, int width, int height);
RL_GameInfo *RL_CreateGameInfo(char *name, char *description, char *version);
RL_Error RL_DestroyGameInfo(RL_GameInfo *gameinfo);
RL_Error RL_DestroyWindow(RL_Window *window);

#endif
