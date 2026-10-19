# Star Wars ASCII Movie Player

![build](https://github.com/ryonchan/StarWarsMoviePlayer/actions/workflows/build.yml/badge.svg)

A C++20 movie player that plays ASCII-art animations, including the full ASCII *Star Wars* (15,475 frames), with real-time playback, rewind, and live frame editing.

<!-- Add a demo GIF here: record the player running on your Mac, save it as docs/demo.gif, then uncomment the line below. -->
<!-- ![Demo](docs/demo.gif) -->

## Features

- **Playback controls:** play forward, play backward, pause, and exit, with a configurable delay between frames
- **Live editing:** copy or delete the current frame while the movie is running
- **Custom data structure:** frames are stored in a hand-written, templated doubly linked list (`smcList<T>`) with its own bidirectional iterator, rather than an STL container
- **Compact file format:** each frame is stored once with a repeat count, so the 44,800-line `starwar.ani` (3,200 unique frames) expands to 15,475 frames on load

## How it works

| File | Role |
| --- | --- |
| `src/SMCDoubleList.hpp` | Templated doubly linked list with head/tail pointers and an iterator supporting `++`, `--`, and `*`, plus O(1) `insert` and `erase` at an iterator |
| `src/movie.h`, `src/movie.cpp` | `MoviePlayer`: parses `.ani` files into the list and tracks the current frame with an iterator |
| `main.cpp` | Event loop: draws the current frame, handles key presses, and moves the iterator each tick |
| `tests/studentTests.cpp` | Catch2 unit tests for the list and the player |

### `.ani` file format

Each frame is 14 lines: a repeat count, followed by 13 lines of ASCII art.

```
31
                 -===                    `"',
                ""o o                    O O|)   Going somewhere,
...(11 more lines)
```

## Controls

| Key | Action |
| --- | --- |
| `f` | Play forward |
| `b` | Play backward |
| `p` | Pause |
| `c` | Copy the current frame |
| `d` | Delete the current frame |
| `x` | Exit |

## Build and run

Requires CMake 3.20+ and a C++20 compiler.

```bash
cmake -S . -B build
cmake --build build
```

**macOS / Windows:** this also builds the `main` player executable, which uses the bundled graphics library in `ITPLib/`.

```bash
./build/main
# Input file: input/starwar.ani
# MS delay between frames: 60
```

**Linux:** the graphics library isn't available for Linux, so only the unit tests are built.

## Tests

Run from the repository root:

```bash
./build/tests/tests
```

Tests also run automatically on every push through GitHub Actions.
