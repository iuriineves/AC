#include <caoss/utils.h>

#include <stdio.h>
#include <caoss/cpu.h>
#include <caoss/types.h>

unsigned char* int2bin(caoss_word num, unsigned char *buffer, unsigned size, op_size data_op_size) {

    size--;
    buffer[size] = '\0';
    data_op_size++;

    while (size--) {
        if (size && (size < data_op_size*8) && ((size % 8) == 0))
            buffer[size--] = ' ';

        buffer[size] = ((char) (num & 1)) + '0';
        num >>= 1;
    }

    return buffer;
}


int is_binary_operation(alu_opcode opcode) {
    return opcode == ADD || opcode == SUB || opcode == AND || opcode == OR || opcode == SLL || opcode == SRA;
}


void error(char* msg) {
    fprintf (stderr, "%s: %s.", CAOSS_ERROR, msg);
}

void print_alu_instruction(const caoss_word instruction, const alu_opcode opcode, const byte size, const byte reg_in_1, const byte reg_in_2, const byte reg_out) {
    if (is_binary_operation(opcode))
        printf ("ALU instruction 0x%x --> operation = %d, size = %s, reg_in_1 = %d (r%d), reg_in_2 = %d (r%d), reg_out = %d (r%d)\n",
                instruction, opcode,
                size == BYTE ? "BYTE" : "WORD",
                reg_in_1, (reg_in_1),
                reg_in_2, (reg_in_2),
                reg_out, (reg_out));
    else
        printf ("ALU instruction 0x%x --> operation = %d, size = %s, reg_in_1 = %d (r%d), reg_in_2 = (ignored), reg_out = %d (r%d)\n",
                instruction, opcode,
                size == BYTE ? "BYTE" : "WORD",
                reg_in_1, (reg_in_1),
                reg_out, (reg_out));
}

void print_memory_instruction(const caoss_word instruction, const ls_opcode opcode, const caoss_word address, const byte reg ) {
    printf ("Memory instruction 0x%x --> opcode = %d, address = %d, register = %d (r%d)\n",
            instruction, opcode, address, reg, (reg));
}

void print_branch_instruction(const caoss_word instruction, const br_opcode opcode, const caoss_word offset ) {
    printf ("Branch instruction 0x%x --> opcode = %d, offset = %d\n",
            instruction, opcode, offset);
}

void print_load_immediate(const caoss_word instruction, const caoss_word value, const byte reg ) {
    printf ("Load immediate instruction 0x%x --> value = %d, register = %d (r%d)\n",
            instruction, (short) value, reg, (reg));
}

void print_jump(const caoss_word instruction, const caoss_word address) {
    printf ("Jump instruction 0x%x --> address = %d\n",
            instruction, address);
}
void print_interrupt(const caoss_word instruction, const caoss_word int_number) {
    printf ("Interrupt instruction 0x%x --> interrupt number = %d\n",
            instruction, int_number);
}