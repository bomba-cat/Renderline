#ifndef RENDERLINE_H
#define RENDERLINE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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

typedef struct RL_Menu {
  char **entries;
  void *(**functions)(void);
} RL_Menu;

typedef enum {
  RL_OK = 0,
  RL_UNDEFINED_ERROR = 1,
} RL_Error;

/* Init functions */
RL_Error RL_Init();

/* Quit functions */
RL_Error RL_Quit();

/* Helper functions */
RL_Error RL_AddMenuEntry(RL_Menu *menu, char *entry, void *(*func)(void));
RL_Error RL_ShowMenu(RL_Menu *menu);

/* Constructor fucntions */
RL_Menu *RL_CreateMenu();
RL_Window *RL_CreateWindow(RL_GameInfo *gameinfo, int width, int height);
RL_GameInfo *RL_CreateGameInfo(char *name, char *description, char *version);

/* Destructor classes */
RL_Error RL_DestroyGameInfo(RL_GameInfo *gameinfo);
RL_Error RL_DestroyWindow(RL_Window *window);
RL_Error RL_DestroyMenu(RL_Menu *menu);

#endif
