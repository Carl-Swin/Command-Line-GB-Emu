#pragma once

#include "common.h"

typedef struct emu_context{
    /* Optimized
    u64 ticks;
    bool paused : 1;
    bool running : 1;
    /*/
    bool paused;
    bool running;
    u64 ticks;
    //*/
} emu_ctx;

int emu_run(int argc, char **argv);

emu_ctx *emu_get_context();

void emu_cycles(int cpu_cycles);