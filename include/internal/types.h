#ifndef RL_TYPES_H
#define RL_TYPES_H

/* To satisfy CoC */
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct RL_GameInfo {
  char *name;
  char *description;
  char *version; /* The reason this is kept as a character is
                  * for games going with versions like: 0.1.2 */
} RL_GameInfo;

typedef struct RL_Color {
  uint8_t r, g, b, a;
} RL_Color;

typedef struct RL_Font {
  TTF_Font *ttf_font;
  uint8_t size;
  RL_Color color;
} RL_Font;

typedef struct RL_Window {
  SDL_Window *sdl_window;
  RL_Font *default_font;
  char *title;
} RL_Window;

typedef struct RL_Menu {
  char **entries;
  void *(**functions)(void);
} RL_Menu;

typedef enum {
  RL_OK = 0,
  RL_UNDEFINED_ERROR = 1,
} RL_Error;

#endif
