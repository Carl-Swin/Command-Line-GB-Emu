// gcc -w main/*.c lib/*.c *.dll

#include "../include/emu.h"

int main(int argc, char **argv) {
    return emu_run(argc, argv);
}
