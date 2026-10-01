#pragma once

#include "common.h"
#include "instructions.h"

typedef struct cpu_registers {
    u16 pc;
    u16 sp;
    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    //u16 pc;
    //u16 sp;
} cpu_reg;

typedef struct cpu_context {
    cpu_reg regs;
    
    inst_param *cur_inst;
    u16 fetched_data;
    u16 mem_dest;  // dest_is_mem
    u8 cur_opcode;

    bool halted : 1;
    bool stepping : 1;
    bool dest_is_mem : 1;
} cpu_ctx;

void cpu_init();
bool cpu_step();
