#ifndef CAOSS_TYPES_H
#define CAOSS_TYPES_H

typedef unsigned char byte;
typedef unsigned short caoss_word;
typedef short signed_caoss_word;

typedef caoss_word caoss_address;
typedef caoss_word caoss_instruction;

#define MAX_MEM_SIZE (1 << 10)
#define MAX_CODE_SIZE (1 << 16)
#define REGISTER_SIZE sizeof(caoss_word)*8
#define N_REGISTERS (1 << 3)
#define N_FLAGS 4

#define CAOSS_ERROR "caoss error"

#endif //CAOSS_TYPES_H
