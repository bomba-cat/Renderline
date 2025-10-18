#include "../../include/renderline.h"
#include "rl_internal.h"

RL_Menu *RL_CreateMenu() {
  struct RL_Menu *rl_menu_i = malloc(sizeof *rl_menu_i);

  if (rl_menu_i == NULL) {
    return NULL;
  }

  rl_menu_i->entries = malloc(sizeof *rl_menu_i->entries);
  rl_menu_i->functions = malloc(sizeof *rl_menu_i->functions);
  if (rl_menu_i->entries == NULL || rl_menu_i->functions == NULL) {
    RL_DestroyMenu(rl_menu_i);
    return NULL;
  }

  rl_menu_i->entries[0] = NULL;
  rl_menu_i->functions[0] = NULL;

  return rl_menu_i;
}

RL_Error rl_get_functions_size_i(void *(**functions)(void), int *count) {
  if (functions == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  do {
    (*count)++;
  } while (functions[*count - 1] != NULL);

  return RL_OK;
}

RL_Error rl_get_entries_size_i(char **entries, int *count) {
  if (entries == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  do {
    (*count)++;
  } while (entries[*count - 1] != NULL);

  return RL_OK;
}

RL_Error RL_AddMenuEntry(RL_Menu *menu, char *entry, void *(*func)(void)) {
  if (menu == NULL || entry == NULL || func == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  int rl_entries_count_i = 0;
  int rl_functions_count_i = 0;
  if (rl_get_functions_size_i(menu->functions, &rl_functions_count_i) > 0 ||
      rl_get_entries_size_i(menu->entries, &rl_entries_count_i) > 0) {
    return RL_UNDEFINED_ERROR;
  }

  /* TODO: fix invalid realloc size */
  void *rl_entries_new_ptr_i =
      realloc(menu->entries, sizeof(char **) * (rl_entries_count_i + 1));
  void *rl_functions_new_ptr_i = realloc(
      menu->functions, sizeof(void *(**)(void)) * (rl_functions_count_i + 1));
  if (rl_entries_new_ptr_i == NULL || rl_functions_new_ptr_i == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  /* Prevention of memory leak was the reason for creating the
   * temporary pointer. If the check didn't fail then we can
   * safely set it to the new pointer. */
  menu->entries = rl_entries_new_ptr_i;
  menu->functions = rl_functions_new_ptr_i;

  menu->entries[rl_entries_count_i] = strdup(entry);
  menu->entries[rl_entries_count_i + 1] = NULL;

  menu->functions[rl_functions_count_i] = func;
  menu->functions[rl_functions_count_i + 1] = NULL;

  if (strcmp(menu->entries[rl_entries_count_i], entry)) {
    return RL_UNDEFINED_ERROR;
  }

  return RL_OK;
}

RL_Error RL_DestroyMenu(RL_Menu *menu) {
  if (menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  for (size_t entry = 1; menu->entries[entry] != NULL; entry++) {
    free(menu->entries[entry]);
    menu->entries[entry] = NULL;
  }
  free(menu->entries);
  free(menu->functions);
  free(menu);
  menu = NULL;

  return RL_OK;
}
