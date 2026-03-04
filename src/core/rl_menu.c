#include "../rl_internal.h"

#include <stdlib.h>

static RL_Error rl_menu_reserve_i(RL_Menu *menu, size_t minimum_capacity) {
  RL_MenuEntryInternal *resized_entries;
  size_t new_capacity;

  if (menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  if (menu->entry_capacity >= minimum_capacity) {
    return RL_OK;
  }

  new_capacity = menu->entry_capacity == 0 ? 4 : menu->entry_capacity;
  while (new_capacity < minimum_capacity) {
    new_capacity *= 2;
  }

  resized_entries = realloc(menu->entries, sizeof(*menu->entries) * new_capacity);
  if (resized_entries == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  menu->entries = resized_entries;
  menu->entry_capacity = new_capacity;
  return RL_OK;
}

RL_Menu *RL_CreateMenu(void) {
  struct RL_Menu *rl_menu_i;

  rl_menu_i = calloc(1, sizeof *rl_menu_i);

  if (rl_menu_i == NULL) {
    return NULL;
  }

  if (rl_menu_reserve_i(rl_menu_i, 4) != RL_OK) {
    RL_DestroyMenu(rl_menu_i);
    return NULL;
  }

  return rl_menu_i;
}

RL_Error RL_MenuAddEntry(RL_Menu *menu, const char *label,
                         RL_MenuCallback callback, void *userdata) {
  RL_MenuEntryInternal *entry;

  if (menu == NULL || label == NULL || callback == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  if (rl_menu_reserve_i(menu, menu->entry_count + 1) != RL_OK) {
    return RL_UNDEFINED_ERROR;
  }

  entry = &menu->entries[menu->entry_count];
  entry->label = rl_strdup_i(label);
  if (entry->label == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  entry->callback = callback;
  entry->userdata = userdata;
  menu->entry_count++;

  return RL_OK;
}

RL_Error RL_DestroyMenu(RL_Menu *menu) {
  size_t entry_index;

  if (menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  for (entry_index = 0; entry_index < menu->entry_count; entry_index++) {
    free(menu->entries[entry_index].label);
  }
  free(menu->entries);
  free(menu);

  return RL_OK;
}

size_t RL_MenuGetEntryCount(const RL_Menu *menu) {
  if (menu == NULL) {
    return 0;
  }

  return menu->entry_count;
}

const char *RL_MenuGetEntryLabel(const RL_Menu *menu, size_t index) {
  if (menu == NULL || index >= menu->entry_count) {
    return NULL;
  }

  return menu->entries[index].label;
}

RL_MenuCallback RL_MenuGetEntryCallback(const RL_Menu *menu, size_t index) {
  if (menu == NULL || index >= menu->entry_count) {
    return NULL;
  }

  return menu->entries[index].callback;
}

void *RL_MenuGetEntryUserData(const RL_Menu *menu, size_t index) {
  if (menu == NULL || index >= menu->entry_count) {
    return NULL;
  }

  return menu->entries[index].userdata;
}

RL_Error RL_MenuSetRenderer(RL_Menu *menu, const RL_MenuRenderer *renderer,
                            void *userdata) {
  if (menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  menu->renderer = renderer;
  menu->renderer_userdata = userdata;
  return RL_OK;
}
