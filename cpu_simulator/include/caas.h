#ifndef CAAS_CAAS_H
#define CAAS_CAAS_H

#include "caoss/types.h"
#include "caoss/cpu.h"

/**
 * Encode the header of the binary file
 */
void encode_header();

/**
 * Encode a global data definitions
 * @param size Size of the data to be stored
 * @param value Value to be stored
 */
void encode_global(op_size size, caoss_word value);

/**
 * Update the number of global data definitions in the header
 */
void update_number_of_globals();

/**
 * Encode ALU binary instruction
 *
 * @param alu_op Opcode of the instruction
 * @param size Size of the instruction
 * @param reg1 First operand
 * @param reg2 Second operand
 * @param reg_out Result register
 */
void encode_binary_alu_instruction(alu_opcode alu_op, op_size size, byte reg1, byte reg2, byte reg_out);

/**
 * Encode ALU binary instruction
 *
 * @param opcode Opcode of the instruction
 * @param size Size of the instruction
 * @param reg Operand register
 * @param reg_out Result register
 */
void encode_unary_alu_instruction(alu_opcode opcode, op_size size, byte reg, byte reg_out);

/**
 * Encode a load/store memory operation
 * @param opcode The opcode
 * @param address The memory address to read or write from/to
 * @param reg The register to load ot store
 */
void encode_load_store(ls_opcode opcode, caoss_address address, byte reg);

/**
 * Encode a load immediate operation
 * @param size The size of the operation
 * @param value The value to load
 * @param reg The target register
 */
void encode_load_immediate(op_size size, caoss_word value, byte reg);

void encode_branch_instruction(br_opcode op, caoss_word offset);

void encode_jump(caoss_address address);

/**
 * Encode an interrupt operation
 *
 * @param interrupt_number The number of the interrupt
 */
void encode_interrupt(caoss_word interrupt_number);


#endif //CAAS_CAAS_H
