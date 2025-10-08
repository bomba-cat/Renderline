#ifndef RENDERLINE_H
#define RENDERLINE_H

typedef struct RL_GameInfo RL_GameInfo;

typedef enum {
  RL_OK = 0,
  RL_UNDEFINED_ERROR = 1,
} RL_Error;

RL_Error RL_Init();
RL_Error RL_SetGameInfo(RL_GameInfo gameinfo);
RL_Error RL_SetGameInfoParams(char *name, char *descprtion, char *version);
RL_Error RL_GetGameInfo(RL_GameInfo *gameinfo);
RL_Error RL_Quit();

#endif
