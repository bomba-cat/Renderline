#include "../../include/renderline.h"
#include "rl_internal.h"

struct RL_GameInfo rl_gameinfo_i;

RL_Error RL_SetGameInfoStruct(RL_GameInfo gameinfo) {
  if (gameinfo.description == NULL || gameinfo.name == NULL ||
      gameinfo.version == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  rl_gameinfo_i.description = strdup(gameinfo.description);
  rl_gameinfo_i.name = strdup(gameinfo.name);
  rl_gameinfo_i.version = strdup(gameinfo.version);

  if (strcmp(rl_gameinfo_i.description, gameinfo.description) ||
      strcmp(rl_gameinfo_i.name, gameinfo.name) ||
      strcmp(rl_gameinfo_i.version, gameinfo.version)) {
    return RL_UNDEFINED_ERROR;
  }

  return RL_OK;
}

RL_Error RL_SetGameInfoParams(char *name, char *description, char *version) {
  if (description == NULL || name == NULL || version == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  rl_gameinfo_i.description = strdup(description);
  rl_gameinfo_i.name = strdup(name);
  rl_gameinfo_i.version = strdup(version);

  if (strcmp(rl_gameinfo_i.description, description) ||
      strcmp(rl_gameinfo_i.name, name) ||
      strcmp(rl_gameinfo_i.version, version)) {
    return RL_UNDEFINED_ERROR;
  }

  return RL_OK;
}

RL_Error RL_GetGameInfo(RL_GameInfo *gameinfo) {
  if (rl_gameinfo_i.description == NULL || rl_gameinfo_i.name == NULL ||
      rl_gameinfo_i.version == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  gameinfo->description = strdup(rl_gameinfo_i.description);
  gameinfo->name = strdup(rl_gameinfo_i.name);
  gameinfo->version = strdup(rl_gameinfo_i.version);

  if (strcmp(rl_gameinfo_i.description, gameinfo->description) ||
      strcmp(rl_gameinfo_i.name, gameinfo->name) ||
      strcmp(rl_gameinfo_i.version, gameinfo->version)) {
    return RL_UNDEFINED_ERROR;
  }
  return RL_OK;
}

RL_Error RL_Quit() {
  free(rl_gameinfo_i.description);
  free(rl_gameinfo_i.name);
  free(rl_gameinfo_i.version);

  return RL_OK;
}
