#include <caoss.h>
#include <caoss/utils.h>

#include <stdio.h>
#include <stdlib.h>

#include "caoss/register.h"

// Registers
caoss_word registers[N_REGISTERS];
caoss_address pc = 0;
caoss_instruction ir;
caoss_word flags;

/**
 * Uses read_code to load instruction at code[pc] to ir (the instruction register)
 */
void fetch() {
    read_code(pc, &ir);
}

void load_immediate_operation(const byte reg, caoss_word value) {
#ifdef DEBUG
    print_load_immediate(ir, value, reg);
#endif

    caoss_word shortval = ir & 0x1ff8;
    caoss_word number = shortval >> 3;
    registers[reg] = number;
}


void memory_operation(const ls_opcode op, const byte reg, const caoss_address address) {

#ifdef DEBUG
    print_memory_instruction(ir, op, address, reg);
#endif

    switch (op) {
        case LOAD_MEM:
            read_data(address, &registers[reg]);
            break;

        case STORE_MEM:
            write_data(registers[reg], address);
    }
}

void branch_operation(const br_opcode op, const caoss_word offset) {
#ifdef DEBUG
    print_branch_instruction(ir, op, offset);
#endif

    switch (op) {
        case BZ:
            // TODO - Lab 6
            break;

        case BNZ:
            // TODO - Lab 6
            break;

        case BN:
            // TODO - Lab 6
            break;

        case BNN:
            // TODO - Lab 6
            break;

        case BC:
            // TODO - Lab 6
            break;

        case BNC:
            // TODO - Lab 6
            break;

        case BO:
            // TODO - Lab 6
            break;

        case BNO:
            // TODO - Lab 6
            break;
    }
}


void alu_binary_operation(const alu_opcode op, const op_size size, const byte reg_out, const byte reg_in_1, const byte reg_in_2) {

#ifdef DEBUG
        print_alu_instruction(ir, op, size, reg_in_1, reg_in_2, reg_out);
#endif

    switch (op) {
        case ADD:
            add(size, reg_in_1, reg_in_2, reg_out);
            break;
        case SUB:
            sub(size, reg_in_1, reg_in_2, reg_out);
            break;
        case AND:
            and(size, reg_in_1, reg_in_2, reg_out);
            break;
        case OR:
            or(size, reg_in_1, reg_in_2, reg_out);
            break;
        case SRA:
            sra(size, reg_in_1, reg_in_2, reg_out);
            break;
        case SLL:
            sll(size, reg_in_1, reg_in_2, reg_out);
            break;

        default:
            error("Unknown opcode\n");
    }
}


void alu_unary_operation(alu_opcode op,  op_size size, byte reg_out,  byte reg_in_1) {

#ifdef DEBUG
    print_alu_instruction(ir, op, size, reg_in_1, 0, reg_out);
#endif

    switch (op) {
        case NEG:
            neg(size, reg_in_1, reg_out);
            break;
        case NOT:
            not(size, reg_in_1, reg_out);
            break;

        default:
            error("Unknown opcode\n");
    }
}

void jump_operation(const caoss_address address) {

#ifdef DEBUG
    print_jump(ir, address);
#endif

    // TODO - Lab 6
}

void interrupt_operation(const caoss_word int_number) {

#ifdef DEBUG
    print_interrupt(ir, int_number);
#endif

    switch (int_number) {
        case 0:
            syscall(registers[0]);
            break;

        default:
            fprintf(stderr, "%s: invalid interrupt %d\n", CAOSS_ERROR, int_number);
            exit(1);
    }
}

/**
 * Decode the instruction in ir
 */
opcode decode() {

#ifdef DEBUG
    const unsigned size = sizeof(caoss_word) * 9 ; // extra spaces for separating bytes
    unsigned char intNum[size];
    printf("Decoding instruction 0x%d (%s) at address %d\n", ir, int2bin(ir, intNum, size, WORD), pc);
#endif

    return (opcode)(ir >> 13);
}

/**
 * Decode the instruction in ir and call the respective function to carry out the operation's execution
 */
void execute(const opcode op) {

#ifdef DEBUG
    printf("Executing instruction of type %d\n", op);
#endif

    switch (op) {
        case LOAD:
        case STORE: {
            const caoss_word address = 0; // TODO - Lab 5
            const byte reg = 0; // TODO - Lab 5
            memory_operation((ls_opcode) op, reg, address);
            break;
        }

        case LOAD_IMMEDIATE: {
            caoss_word value = 0; // TODO - Lab 5
            const byte reg = 0; // TODO - Lab 5
            load_immediate_operation(reg, value);
            break;
        }

        case BRANCH: {
            const br_opcode br_op = 0; // TODO - Lab 5
            const caoss_word offset =  0; // TODO - Lab 5
            branch_operation(br_op, offset);
            break;
        }

        case ALU_BYTE:
        case ALU_WORD: {
            const op_size size = 0; // TODO - Lab 5
            const alu_opcode alu_op = 0; // TODO - Lab 5
            const byte reg_in_1 = 0; // TODO - Lab 5
            const byte reg_out = 0; // TODO - Lab 5

            if (is_binary_operation(alu_op)) {
                // Binary operation
                const byte reg_in_2 = 0; // TODO - Lab 5
                alu_binary_operation(alu_op, size, reg_out, reg_in_1, reg_in_2);
            }
            else {
                // Unary operation
                alu_unary_operation(alu_op, size, reg_out, reg_in_1);
            }
            break;
        }

        case JUMP: {
            const caoss_address address = 0; // TODO - Lab 5
            jump_operation(address);
            break;
        }

        case INT: {
            const caoss_word int_number = (ir & 0X1FFF);
            interrupt_operation(int_number);
            break;
        }

        default:
            error("instruction type not known.");
            exit(1);
    }
}

void cpu_run() {
    while (1) {
#ifdef DEBUG
        show_memory();
        show_registers();
        printf("\n-------------------------------------------------------------------------------------------------------\n");
#endif

        fetch();
        const opcode inst_type = decode();
        pc += 2; // go to the next word
        execute(inst_type);
    }
}


void show_registers() {
    const unsigned size = sizeof(caoss_word) * 9; // extra spaces for separating bytes and \0
    unsigned char intNum[size];

    printf("Registers:\n");
    printf("\tpc [%5u] \t [%s]\n", pc, int2bin(pc, intNum, size, WORD));
    printf("\tir [%5u] \t [%s]\n", ir, int2bin(ir, intNum, size, WORD));

    // flags
    printf("\tflags [%5u] \t [%s] \t", flags, int2bin(flags, intNum, size, WORD));
    printf("ZERO: %d  NEGATIVE: %d  CARRY: %d  OVERFLOW: %d\n\n",
        get_flag(ZERO), get_flag(NEGATIVE), get_flag(CARRY), get_flag(OVERFLOW)) ;


    for (int i = 0; i < N_REGISTERS; i++) {
        printf("\tr%d [%5d] [%5d] [%s]\n", i, registers[i], (signed_caoss_word) registers[i],
               int2bin(registers[i], intNum, size, WORD));
    }
}
