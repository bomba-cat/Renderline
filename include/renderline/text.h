#ifndef RENDERLINE_TEXT_H
#define RENDERLINE_TEXT_H

#include "renderline/types.h"

RL_Font *RL_CreateFont(const char *path, uint8_t size);
RL_Error RL_DestroyFont(RL_Font *font);

RL_Error RL_FontSetColor(RL_Font *font, RL_Color color);
RL_Color RL_FontGetColor(const RL_Font *font);
uint8_t RL_FontGetSize(const RL_Font *font);

RL_Error RL_WindowSetDefaultFont(RL_Window *window, RL_Font *font);
RL_Font *RL_WindowGetDefaultFont(const RL_Window *window);

#endif
