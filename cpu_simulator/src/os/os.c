#include <stdio.h>
#include <stdlib.h>

#include <caoss.h>
#include <caoss/stats.h>

int load_program(char *file_name) {
    FILE* fp = fopen(file_name, "r");
    if (fp == NULL)
        return -1;

#ifdef DEBUG
    printf("Loading program %s\n", file_name);
#endif
    caoss_word num_globals;
    if (fread(&num_globals, 2, 1, fp) != 1) {
        return -1;
    }

#ifdef DEBUG
    printf("Number of global variables %d\n", num_globals);
#endif

    unsigned address = 0;
    for (int i = 0; i < num_globals; i++) {
        op_size size = 0;
        if ((fread(&size, 1, 1, fp) != 1)) {
            return -1;
        }

        if ((fread(&data[address], size, 1, fp) != 1)) {
            return -1;
        }
        dirty[address] = 1;
        if (size == 2)   dirty[address+1] = 1;
        address += size;
    }

    address = 0;
    while (fread(&code[address], sizeof(caoss_word), 1, fp) == 1)
        address+=2;

    fclose(fp);

    return 0;
}

void syscall(const caoss_word syscall_number) {

    switch (syscall_number) {
        case 0: // Exit
#ifdef DEBUG
            printf("System call 0: terminate program with status %d.\n", registers[0]);
#endif
            show_memory();
            show_registers();
            if (has_cache())
                print_cache_stats();
            exit(0);

        case 1: // load program
            //     load_program(program);
            break;

        default:
            fprintf(stderr, "%s: no such system call %d\n", CAOSS_ERROR, syscall_number);
            exit(1);
    }
}