# Building
## Dependencies
- SDL2
- SDL2_TTF
- `cmake`
- Ideally `make` instead of `ninja` or others

## CMake
```bash
cmake -B build
```

```bash
cmake --build build
```

## Public headers
- Include the umbrella header as `#include <renderline/renderline.h>`.
- Only the `include/renderline/` directory is part of the public API.
