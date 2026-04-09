#ifndef CAOSS_INSTRUCTIONS_H
#define CAOSS_INSTRUCTIONS_H

typedef enum {
    BYTE = 0,
    WORD = 1,
} op_size;

typedef enum {
    LOAD,
    STORE,
    LOAD_IMMEDIATE,
    BRANCH,
    ALU_BYTE, ALU_WORD,
    JUMP,
    INT
} opcode;

typedef enum {
    ADD,
    SUB,
    AND,
    OR,
    NEG, // Two's complement
    NOT, // One's complement
    SRA, // arithmetic shift
    SLL // arithmetic shift
} alu_opcode;

typedef enum {
    LOAD_MEM,
    STORE_MEM,
} ls_opcode;

typedef enum {
    BZ,
    BNZ,
    BN,
    BNN,
    BC,
    BNC,
    BO,
    BNO
} br_opcode;


void cpu_run();
void show_registers();

#endif //CAOSS_INSTRUCTIONS_H
