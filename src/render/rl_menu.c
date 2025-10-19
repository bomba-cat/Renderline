#include "../../include/renderline.h"
#include "../core/rl_internal.h"

RL_Error RL_ShowMenu(RL_Window *window, RL_Menu *menu) {
  if (window == NULL || menu == NULL) {
    return RL_UNDEFINED_ERROR;
  }

  return RL_OK;
}
