#ifndef RL_CORE_H
#define RL_CORE_H

/* To satisfy CoC */
#include "../types.h"

/* Init functions */
RL_Error RL_Init();

/* Quit functions */
RL_Error RL_Quit();

/* Create functions */
RL_Menu *RL_CreateMenu();
RL_Window *RL_CreateWindow(RL_GameInfo *gameinfo, int width, int height);
RL_GameInfo *RL_CreateGameInfo(char *name, char *description, char *version);

/* Helper functions */
RL_Error RL_AddMenuEntry(RL_Menu *menu, char *entry, void *(*func)(void));

/* Destroy functions */
RL_Error RL_DestroyGameInfo(RL_GameInfo *gameinfo);
RL_Error RL_DestroyWindow(RL_Window *window);
RL_Error RL_DestroyMenu(RL_Menu *menu);

#endif
