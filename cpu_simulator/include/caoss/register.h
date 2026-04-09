#ifndef CAOSS_ALU_REGISTER_H
#define CAOSS_ALU_REGISTER_H

#include "types.h"

extern caoss_word registers[N_REGISTERS];

caoss_word read_register(byte reg);

void write_register(byte reg, caoss_word value);

#endif //CAOSS_ALU_REGISTER_H