#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#include <caoss.h>
#include <caoss/utils.h>

int main(int argc , char* argv[]) {

    if (argc < 2) {
        fprintf(stderr, "usage: %s file_name\n", argv[0]);
        return 1;
    }

    const long mem_size = MAX_MEM_SIZE;

    if (setup_memory(mem_size) == -1) {
        perror(CAOSS_ERROR);
        return errno;
    }

    if (load_program(argv[1]) == -1) {
        perror(CAOSS_ERROR);
        return errno;
    }

    cpu_run();
}



