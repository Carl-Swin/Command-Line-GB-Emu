#pragma once

#include "common.h"
#include "instructions.h"

typedef struct cpu_registers {
    // Optimized
    //u16 pc;
    //u16 sp;

    u8 a;
    u8 f;
    u8 b;
    u8 c;
    u8 d;
    u8 e;
    u8 h;
    u8 l;
    u16 pc;
    u16 sp;
} cpu_reg;

typedef struct cpu_context {
    /* Optimized
    cpu_reg regs;
    
    inst_param *cur_inst;
    u16 fetched_data;
    u16 mem_dest;
    u8 cur_opcode;

    bool halted : 1;
    bool stepping : 1;
    bool dest_is_mem : 1;
    bool int_master_enable : 1;
    /*/
    cpu_reg regs;
    
    u16 fetched_data;
    u16 mem_dest;
    bool dest_is_mem;
    u8 cur_opcode;
    inst_param *cur_inst;

    bool halted;
    bool stepping;
    
    bool int_master_enable;
    //*/
} cpu_ctx;

void cpu_init();
bool cpu_step();

u16 cpu_read_reg(reg_type rt);
