#ifndef RL_INTERNAL_H
#define RL_INTERNAL_H

#include <SDL2/SDL.h>
#include <string.h>

struct RL_GameInfo {
  char *name;
  char *description;
  char *version; /* The reason this is kept as a character is
                  * for games going with versions like: 0.1.2 */
};

extern struct RL_GameInfo rl_gameinfo_i;

#endif
