# Star Wars ASCII Movie Player

C++ player for the ASCII Star Wars movie (15,000+ frames). Frames are stored in a doubly linked list I wrote, so you can play forward, backward, pause, and copy or delete frames while it's running.

## Run

```
cmake -S . -B build
cmake --build build
./build/main
```

Enter `input/starwar.ani` as the file and a delay like `60`.

Controls: `f` forward, `b` backward, `p` pause, `c` copy frame, `d` delete frame, `x` exit

The player builds on Mac and Windows. On Linux only the tests build.

## Tests

```
./build/tests/tests
```
