#include "utility.h"

#include <stdio.h>


void cpy_in_memory(void *const dest, const void *const src, int size)
{
    for(int i = 0; i < size; i++)
    {
        *((char* )dest + i) = *((char *)src + i);
    }
}

void print_byte_by_bit(void* obj, size_t nb_bytes)
{
    for(size_t i = 0; i < nb_bytes; i++)
    {
        char byte = *((char* )obj + i);

        for(char j = 7; j >= 0; j--)
        {
            char bit = (byte >> j) & 1;

            printf("%d", bit);
        }
        printf(" ");
    }
    printf("\n");
}

void print_array(const char *const array, const char size)
{
    int total = 0;

    for(char i = 0; i < size; i++)
    {
        printf("%d --> %d\n", i, array[i]);

        total += array[i];
    }

    printf("total : %d\n",total);
}

void shuffle(char *const matrix, const char dim)
{
    for(char i = 0; i < dim; i++)
    {
        char index = rand() % dim;

        char temp = matrix[i];

        matrix[i] = matrix[index];

        matrix[index] = temp;
    }
}
