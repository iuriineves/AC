

#ifndef CAOSS_ALU_H
#define CAOSS_ALU_H

#include "types.h"
#include "cpu.h"
#include <stdbool.h>

typedef enum {
    ZERO,
    NEGATIVE,
    CARRY,
    OVERFLOW
} flag;

bool get_flag(flag f);

void add(op_size size, byte register_in1, byte register_in2, byte register_out);

void sub(op_size size, byte register_in1, byte register_in2, byte register_out);

void and(op_size size, byte register_in1, byte register_in2, byte register_out);

void or(op_size size, byte register_in1, byte register_in2, byte register_out);

void sll(op_size size, byte register_in1, byte register_in2, byte register_out);

void sra(op_size size, byte register_in1, byte register_in2, byte register_out);

void neg(op_size size, byte register_in, byte register_out);

void not(op_size size, byte register_in, byte register_out);

#endif //CAOSS_ALU_H
