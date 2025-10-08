# Contributing to Renderline

Thanks for your interest in contributing! Renderline is a **portable C library for building simple visual novels across multiple platforms**.
To keep it clean, consistent and reliable (and to get your PRs accepted), follow these guidelines.

---

## Code Style

* **Language**: C99 (strict).
* **Indentation**: 2 spaces (should get taken care of by the clang formatter).
* **Braces**: `function() { ... }` (no space before parentheses).
* **Naming**:

  * Public API functions and types are prefixed with `RL_`.
  * Internal runtime variables are prefixed with `rl_` and suffixed with `_i`.
  * Structs should use `typedef struct RL_Foo RL_Foo;` to provide abstraction.

Example:

```c
typedef struct RL_Foo RL_Foo;

RL_Error RL_Bar(const char *path, RL_Foo **out);
```

---

## Error Handling

* **All public API functions return an `RL_Error` enum**.
* Functions that return data must use **output parameters + error codes**:

  ```c
  RL_Error RL_Bar(const char *path, RL_Foo **out);
  ```
* Never use global error state. Keep everything thread-safe.

---

## Memory Management

* If a struct owns dynamic memory, provide:

  * An **initializer** (`RL_InitFoo`).
  * A **destructor** (`RL_DestroyFoo`).
  * Optional **setter** functions that handle deep copies safely.

* Shallow struct assignment (`a = b;`) is forbidden for structs that own pointers.

---

## Abstraction

* Do not expose internal struct fields in the public headers.
* Use **opaque pointers** and provide API functions for access.
* Only files in `src/` may touch internal struct definitions.

---

## Formatting

* All code must be formatted using **clangd** (with the repo’s `.clang-format` file).
* Before committing, run:

  ```bash
  clang-format --dry-run --Werror {all edited sources}
  clang-format -i {all edited sources}
  ```
* Pull requests with inconsistent formatting will be rejected (Don't worry you get your chance again once you format it).

---

## Project Structure

* `include/` -> Public API headers.
* `src/` -> Internal engine code.

---

## Commits & PRs

* Keep commits **atomic** (one logical change per commit).
    Though we all forget to commit every now and then so it's not that troubling, as long as you haven't changed 5000 lines of code at once.
* Write somewhat clear commit messages (`Fix memory leak in RL_Bar();`).
