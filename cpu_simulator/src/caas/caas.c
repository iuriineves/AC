#include <stdio.h>

#include <caas.h>
#include "caas_lexer.h"
#include "caas_parser.h"

#include <caoss/utils.h>

/**
 * Number of globals
 */
caoss_word num_globals = 0;


void encode_header() {
#ifdef DEBUG
    printf ("Write header\n");
#endif
    fwrite(&num_globals, 2, 1, yyout);
}


void encode_global(op_size size, const caoss_word value) {
    size++;
    if (value > ((1 << (size+1)*8)-1)) {
       fprintf(stderr, "line %d: value %d to big too be represented in the selected data size", yylineno, value);
       exit(1);
    }

    fwrite(&size, 1, 1, yyout);
    fwrite(&value, size, 1, yyout);

#ifdef DEBUG
    printf("Global data %d\n", value);
#endif

    num_globals++;
}


void encode_load_store(const ls_opcode opcode, const caoss_word address, const byte reg) {
    if (address < 0) {
        fprintf(stderr, "line %d: value %d < 0 which is not a valid memory address.", yylineno, address);
        exit(1);
    }
    const caoss_word inst =  (opcode << 13) | ((address << 3) & 0x1FFF) | reg;
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_memory_instruction(inst, opcode, address, reg);
#endif
}

void encode_load_immediate(const op_size size, const caoss_word value, const byte reg) {
    const caoss_word inst = (LOAD_IMMEDIATE << 13) |  ((value << 3) & 0x1FFF) |  reg;
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_load_immediate(inst, value, reg);
#endif
}

void encode_branch_instruction(const br_opcode op, const caoss_word offset) {
    const caoss_word inst = (BRANCH << 13) |  (op << 10) |  (offset & 0x3FF);
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_branch_instruction(inst, op, offset);
#endif
}

void encode_binary_alu_instruction(const alu_opcode alu_op, const op_size size, const byte reg1, const byte reg2, const byte reg_out) {
    const opcode op = size == BYTE ? ALU_BYTE : ALU_WORD;
    const caoss_word inst = (op << 13) | (alu_op << 9) |
            (reg1 << 6) | (reg2 << 3) | reg_out;
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_alu_instruction(inst, alu_op, size, reg1, reg2, reg_out);
#endif
}

void encode_unary_alu_instruction(const alu_opcode opcode, const op_size size, const byte reg, const byte reg_out) {
    encode_binary_alu_instruction(opcode, size, reg, 1, reg_out);
}

void encode_jump(const caoss_address address) {
    const caoss_word inst = (JUMP << 13) | (address & 0x1FFF);
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_jump(inst, address);
#endif
}

void encode_interrupt(const caoss_word interrupt_number) {
    const caoss_word inst = (INT << 13) | (interrupt_number & 0x1FFF);
    fwrite(&inst, sizeof(caoss_word), 1, yyout);

#ifdef DEBUG
    print_interrupt(inst, interrupt_number);
#endif
}

void update_number_of_globals() {
    fseek(yyout, 0, SEEK_SET);
    fwrite(&num_globals, 2, 1, yyout);

#ifdef DEBUG
    printf ("Update header with %d global data initializations.\n", num_globals);
#endif
}


int main(const int argc , char* argv[]) {

    if (argc != 3) {
        printf("usage: %s source_file_name executable_name\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if(yyin == NULL) {
        perror("caas");
        return 1;
    }

    yyout = fopen(argv[2], "w");
    if(yyout == NULL) {
        perror("caas");
        return 1;
    }

    yyparse();
}



