#pragma once

#include <stdlib.h>


void cpy_in_memory(void *const dest, const void *const src, int size);

void print_byte_by_bit(void* obj, size_t nb_bytes);

void print_array(const char *const array, const char size);

void shuffle(char *const matrix, const char dim);