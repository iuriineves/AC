#include <string.h>
#include <caoss/cpu.h>

ls_opcode get_ls_opcode(const char* mnemonic) {
    if (strcmp(mnemonic, "ld") == 0)
        return LOAD_MEM;

    if (strcmp(mnemonic, "st") == 0)
        return STORE_MEM;

    return -1;
}
/**
 * Obtain the opcode of the mnemonic of an ALU instruction.
 *
 * @param mnemonic  The text representation of the mnemonic
 * @return A value of the alu_opcode enumeration, if the mnemonic is known, -1 otherwise.
 */
alu_opcode get_alu_opcode(const char* mnemonic) {

    if (strcmp(mnemonic, "add") == 0)
        return ADD;
    if  (strcmp(mnemonic, "sub") == 0)
        return SUB;
    if  (strcmp(mnemonic, "and") == 0)
        return AND;
    if  (strcmp(mnemonic, "or") == 0)
        return OR;
    if  (strcmp(mnemonic, "neg") == 0)
        return NEG;
    if  (strcmp(mnemonic, "sll") == 0)
        return SLL;
    if  (strcmp(mnemonic, "sra") == 0)
        return SRA;
    if  (strcmp(mnemonic, "not") == 0)
        return NOT;

    return -1;
}


br_opcode get_branch_opcode(const char* mnemonic) {
    if (strcmp(mnemonic, "bz") == 0)
        return BZ;
    if  (strcmp(mnemonic, "bnz") == 0)
        return BNZ;

    if (strcmp(mnemonic, "bn") == 0)
        return BN;
    if  (strcmp(mnemonic, "bnn") == 0)
        return BNN;

    if (strcmp(mnemonic, "bc") == 0)
        return BC;
    if  (strcmp(mnemonic, "bnc") == 0)
        return BNC;

    if (strcmp(mnemonic, "bo") == 0)
        return BO;
    if  (strcmp(mnemonic, "bno") == 0)
        return BNO;

    return -1;
}