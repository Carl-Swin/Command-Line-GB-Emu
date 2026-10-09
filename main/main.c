// gcc -w main/*.c lib/*.c *.dll
// gcc -w main/*.c lib/*.c -o gb-emu -lSDL3

#include "../include/emu.h"

int main(int argc, char **argv) {
    return emu_run(argc, argv);
}
