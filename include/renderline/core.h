#ifndef RENDERLINE_CORE_H
#define RENDERLINE_CORE_H

#include "renderline/types.h"

RL_Error RL_Init(void);
RL_Error RL_Quit(void);

RL_GameInfo *RL_CreateGameInfo(const char *name, const char *description,
                               const char *version);
RL_Error RL_DestroyGameInfo(RL_GameInfo *gameinfo);

const char *RL_GameInfoGetName(const RL_GameInfo *gameinfo);
const char *RL_GameInfoGetDescription(const RL_GameInfo *gameinfo);
const char *RL_GameInfoGetVersion(const RL_GameInfo *gameinfo);

RL_Window *RL_CreateWindow(const RL_GameInfo *gameinfo, int width, int height);
RL_Error RL_DestroyWindow(RL_Window *window);

const char *RL_WindowGetTitle(const RL_Window *window);
int RL_WindowGetWidth(const RL_Window *window);
int RL_WindowGetHeight(const RL_Window *window);

#endif
