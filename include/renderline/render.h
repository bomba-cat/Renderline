#ifndef RENDERLINE_RENDER_H
#define RENDERLINE_RENDER_H

#include <stddef.h>

#include "renderline/types.h"

typedef void (*RL_MenuCallback)(void *userdata);

typedef struct RL_MenuRenderer {
  RL_Error (*show)(RL_Window *window, const RL_Menu *menu, void *userdata);
} RL_MenuRenderer;

RL_Menu *RL_CreateMenu(void);
RL_Error RL_DestroyMenu(RL_Menu *menu);

RL_Error RL_MenuAddEntry(RL_Menu *menu, const char *label,
                         RL_MenuCallback callback, void *userdata);
size_t RL_MenuGetEntryCount(const RL_Menu *menu);
const char *RL_MenuGetEntryLabel(const RL_Menu *menu, size_t index);
RL_MenuCallback RL_MenuGetEntryCallback(const RL_Menu *menu, size_t index);
void *RL_MenuGetEntryUserData(const RL_Menu *menu, size_t index);

RL_Error RL_MenuSetRenderer(RL_Menu *menu, const RL_MenuRenderer *renderer,
                            void *userdata);
RL_Error RL_ShowMenu(RL_Window *window, const RL_Menu *menu);

#endif
