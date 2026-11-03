# Star Wars ASCII Movie Player

[![build](https://github.com/ryonchan/StarWarsMoviePlayer/actions/workflows/build.yml/badge.svg)](https://github.com/ryonchan/StarWarsMoviePlayer/actions/workflows/build.yml)

A C++20 player for the full ASCII-art *Star Wars: Episode IV*: **15,475 frames** you can play forward, play backward, pause, and edit live by duplicating or deleting frames mid-playback. Every frame is stored in a templated doubly linked list with a custom bidirectional iterator. No STL containers are used.

![Demo of the player running forward, backward, and editing frames](docs/demo.gif)

## Highlights

- **Custom templated container.** `smcList<T>` is a doubly linked list with head and tail pointers. It supports deep-copy construction and assignment, iterator-based `insert` and `erase`, and throws exceptions on invalid access.
- **Bidirectional iterator drives playback.** Playing forward or backward is `++` or `--` on an iterator, so each step costs O(1) in either direction. Deleting or duplicating the current frame is also O(1), because the list splices nodes at the iterator instead of shifting a 15,000-element array.
- **Run-length-encoded parser.** The movie file stores 3,200 unique frames, each with a repeat count. The loader expands them into 15,475 playback frames and handles input quirks such as lines ending in `\` and blank frames.
- **Tested in CI.** 56 Catch2 assertions cover the list (head, middle, and tail edge cases, copy semantics, exceptions) and the player. GitHub Actions builds the project and runs the tests on every push.

## Why a linked list?

| Operation | `smcList` + iterator | `std::vector` |
|---|---|---|
| Step forward / backward | O(1) | O(1) |
| Delete current frame | **O(1)** | O(n) |
| Duplicate current frame | **O(1)** | O(n) |
| Jump to frame *k* | O(n) | **O(1)** |

The trade-off is random access: jumping straight to frame 9,000 is O(n). The player only ever moves one frame at a time and edits at the cursor, so the linked list is the better fit for this workload.

## Project structure

```
src/SMCDoubleList.hpp    templated doubly linked list + iterator
src/movie.h, movie.cpp   MoviePlayer: parses the file, holds the playback cursor, edit operations
main.cpp                 render loop and keyboard input
tests/studentTests.cpp   Catch2 unit tests
input/                   .ani movie files (starwar.ani is the full film)
```

## Build and run

Requires CMake 3.20+ and a C++20 compiler. The player window builds on macOS and Windows. On Linux, only the tests build.

```bash
cmake -S . -B build
cmake --build build
./build/main
```

When prompted, enter `input/starwar.ani` as the file and `60` as the delay in milliseconds between frames.

| Key | Action |
|---|---|
| `f` | Play forward |
| `b` | Play backward |
| `p` | Pause |
| `c` | Duplicate current frame |
| `d` | Delete current frame |
| `x` | Exit |

### Tests

```bash
./build/tests/tests
```

## Credits

Built for a data structures course at Santa Monica College. The course provided the ITPLib window library, the `MoviePlayer` interface, and the display loop in `main.cpp`. I implemented the linked list, its iterator, and the `MoviePlayer` class.

ASCII Star Wars animation by Simon Jansen, [asciimation.co.nz](https://www.asciimation.co.nz).
