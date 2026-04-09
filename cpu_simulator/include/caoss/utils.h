#ifndef CAOSS_UTILS_H
#define CAOSS_UTILS_H

#include "types.h"
#include "cpu.h"


/**
 * Is the ALU operation a binary operation?
 *
 * @param opcode
 * @return
 */
int is_binary_operation(alu_opcode opcode);


unsigned char* int2bin(caoss_word num, unsigned char *buffer, unsigned size, op_size data_op_size);

void error(char* msg);

void print_alu_instruction(caoss_word instruction, alu_opcode opcode, byte size, byte reg_in_1, byte reg_in_2, byte reg_out);

void print_memory_instruction(caoss_word instruction, ls_opcode opcode, caoss_word address, byte reg);

void print_load_immediate(caoss_word instruction, caoss_word value, byte reg);

void print_interrupt(caoss_word instruction, caoss_word int_number);

void print_branch_instruction(caoss_word instruction, br_opcode opcode, caoss_word offset);

void print_jump(caoss_word instruction, caoss_word address);

#endif //CAOSS_UTILS_H
