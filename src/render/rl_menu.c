#include "../rl_internal.h"

RL_Error RL_ShowMenu(RL_Window *window, const RL_Menu *menu) {
  if (window == NULL || menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  if (menu->renderer != NULL && menu->renderer->show != NULL) {
    return menu->renderer->show(window, menu, menu->renderer_userdata);
  }

  return RL_UNDEFINED_ERROR;
}
