#include <stdio.h>

#include <caoss/cache.h>


void show_cache() {
    printf("No cache defined.\n");
}

void read_cache(caoss_address address, caoss_word* reg) { }

void write_cache(caoss_word value, caoss_address address) { }


unsigned setup_cache(int nlines, int blocksize) {
    return 0;
}

unsigned char has_cache() {
    return 0;
}