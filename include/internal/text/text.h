#ifndef RL_TEXT_H
#define RL_TEXT_H

/* To satisfy CoC */
#include "../types.h"

/* Create functions */
RL_Error RL_DefaultWindowFont(RL_Window *window, RL_Font *font);
RL_Font *RL_CreateFont(const char *path, uint8_t size);

/* Destroy functions */
RL_Error RL_DestroyFont(RL_Font *font);

#endif
