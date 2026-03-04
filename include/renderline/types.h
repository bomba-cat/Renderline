#ifndef RENDERLINE_TYPES_H
#define RENDERLINE_TYPES_H

#include <stddef.h>
#include <stdint.h>

typedef struct RL_GameInfo RL_GameInfo;
typedef struct RL_Window RL_Window;
typedef struct RL_Font RL_Font;
typedef struct RL_Menu RL_Menu;

typedef struct RL_Color {
  uint8_t r;
  uint8_t g;
  uint8_t b;
  uint8_t a;
} RL_Color;

typedef enum RL_Error {
  RL_OK = 0,
  RL_UNDEFINED_ERROR = 1,
} RL_Error;

#endif
