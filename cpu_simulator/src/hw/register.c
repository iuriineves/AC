#include <caoss/register.h>

caoss_word read_register(const byte reg) {
    return registers[reg];
}

void write_register(const byte reg, const caoss_word value) {
    registers[reg] = value;
}


