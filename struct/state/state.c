#include "state.h"

#include <stdio.h>

#include "../../utility/utility.h"


State generate_state(const char *const matrix, const char zero_index, const char parent_zero_index)
{
    State new_state = { .parent_zero_index = parent_zero_index, .zero_index = zero_index };

    cpy_in_memory(new_state.matrix, matrix, DIM);

    return new_state;
}

void print_state(const State *const state)
{
    printf("\n");

    printf("matrix : \n");

    print_array(state->matrix, DIM);

    printf("index zero : %d\n", state->zero_index);

    printf("parent index zero : %d\n", state->parent_zero_index);

    printf("\n");
}

void print_state_matrix(const State *const state)
{
    printf("\n");

    printf("matrix : \n");

    for( char i = 0; i < DIM; i++ )
    {
        if ( i % 3 == 0 ) printf("\n");

        printf("%d ", state->matrix[i]);
    }

    printf("\n");

    printf("index zero : %d\n", state->zero_index);

    printf("parent index zero : %d\n", state->parent_zero_index);

    printf("\n");
}

char verify_state_struc_memory_integrity(const State *const state)
{
    char result = 0b0;

    char last_byte = *((char *) state + sizeof(State) - 1);

    if ( last_byte == state->parent_zero_index ) result = 0b1;

    return result;
}

char evaluate_goal_state(const State *const state)
{
    char result = 0b1;

    for (char i = 0; i < DIM; i++)
    {
        if ( i != state->matrix[i] ) { result = 0b0; break; }
    }

    return result;
}