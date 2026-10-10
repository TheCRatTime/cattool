# cattool
**cattool** - `GNU Cat` program copy.

## Description
This is a copy of GNU Cat, but faster.

There is a test:
- **Machine**: Android 6 Termux proot-distro
  Arch Linux 2 GB RAM
- **Shell**: `fish`
- **Compile command**: `gcc src/cattool.c -o cattool`
- **Time command**: `hyperfine`
Output:

```text
Summary
  ./cattool /usr/include/simdjson.h ran
    2.23 ± 2.44 times faster than cat /usr/include/simdjson.h
```

### Build
Needed:
- C Compiler
- CMake 3.10 and greater
- GNU Make

```bash
cmake -B build
cd build/
make
```

### License
Project is under Apache 2.0 license.

### Authors
TheCRatTime
