#ifndef CAOSS_OPCODES_H
#define CAOSS_OPCODES_H
#include "cpu.h"

mem_opcode get_mem_opcode(const char* mnemonic);

/**
 * Obtain the opcode of the mnemonic of an ALU instruction.
 *
 * @param mnemonic  The text representation of the mnemonic
 * @return A value of the alu_opcode enumeration, if the mnemonic is known, -1 otherwise.
 */
alu_opcode get_alu_opcode(const char* mnemonic);


#endif //CAOSS_OPCODES_H