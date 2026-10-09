#include "../include/bus.h"
#include "../include/cpu.h"
#include "../include/emu.h"
#include "../include/instructions.h"

cpu_ctx ctx = {0};

void cpu_init() {
    ctx.regs.pc = 0x100;
}

static void fetch_instruction() {
    ctx.cur_opcode = bus_read(ctx.regs.pc++);
    ctx.cur_inst = instruction_by_opcode(ctx.cur_opcode);

    if (ctx.cur_inst == NULL) {
        fprintf(stderr, "NULL Instruction, Current opcode: %02x\n", ctx.cur_opcode);
        exit(-1);
    }
}
static void fetch_data() {
    ctx.mem_dest = 0;
    ctx.dest_is_mem = false;

    switch (ctx.cur_inst->mode) {
        case AM_IMP: return;

        case AM_R: {
            ctx.fetched_data = cpu_read_reg(ctx.cur_inst->reg_1);
            return;
        }
        case AM_R_D8: {
            ctx.fetched_data = bus_read(ctx.regs.pc);
            emu_cycles(1);
            ctx.regs.pc++;
            return;
        }
        case AM_D16: {
            u16 lo = bus_read(ctx.regs.pc);
            emu_cycles(1);

            u16 hi = bus_read(ctx.regs.pc + 1);
            emu_cycles(1);

            ctx.fetched_data = lo | (hi << 8);
            ctx.regs.pc += 2;
            return;
        }
        default: {
            fprintf(stderr, "Unknown Addressing Mode: %d (%02X)\n", ctx.cur_inst->mode, ctx.cur_opcode);
            exit(-1);
        }
    }
}
static void execute() {
    printf("execute instructions: %02X\tPC: %04x\n", ctx.cur_opcode, ctx.regs.pc);

    NO_IMPL()
}

bool cpu_step() {
    if (!ctx.halted) {
        fetch_instruction();
        fetch_data();
        execute();
    }

    return true;
}
