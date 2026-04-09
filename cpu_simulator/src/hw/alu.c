#include <caoss/alu.h>
#include <caoss/register.h>


extern caoss_word flags;
static caoss_word MSB = (1 << (REGISTER_SIZE-1));


/**
 * Get the value of flag f
 * @param f
 */
 
void set_flag(const flag f, const bool value) {
    if (value) 
        flags |= 1 << f;
    else
        flags &= ~(1 << f);
}
 
bool get_flag(const flag f) {
    return (flags & 1 << f);
}

void add(const op_size size, const byte register_in1, const byte register_in2, const byte register_out) {
     const caoss_word in1 = read_register(register_in1);
     const caoss_word in2 = read_register(register_in2);
     const caoss_word result = in1 + in2;
     
     write_register(register_out, result);
     
     
     set_flag(ZERO, result == 0);
     set_flag(NEGATIVE, result & MSB);
     set_flag(CARRY, result < in1);
     set_flag(OVERFLOW, (~(in1 ^ in2) & (in1 ^ result) & MSB) != 0);
}

void sub(const op_size size, const byte register_in1, const byte register_in2, const byte register_out) {
    // TODO - Lab 5
}

void and(const op_size size, const byte register_in1, const byte register_in2, const byte register_out) {
    // TODO - Lab 5
}

void or(const op_size size, const byte register_in1, const byte register_in2, const byte register_out) {
    // TODO - Lab 5
}

void sll(op_size size, byte register_in1, byte register_in2, byte register_out) {
    // TODO - Lab 5
}

void sra(op_size size, byte register_in1, byte register_in2, byte register_out) {
    // TODO - Lab 5
}

void neg(op_size size, byte register_in, byte register_out) {
    // TODO - Lab 5
}

void not(op_size size, byte register_in, byte register_out) {
    // TODO - Lab 5
}
