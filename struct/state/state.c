#include "state.h"

#include <stdio.h>

#include "../../utility/utility.h"


void store_parent_zero_indeces(const char *const previous_parent_zero_indeces, const char parent_zero_index, char *const new_parent_zero_indeces)
{
    for ( char i = P_INDEX - 1; i > 0; i-- )
    {
        new_parent_zero_indeces[i] = previous_parent_zero_indeces[i - 1];
    }

    new_parent_zero_indeces[0] = parent_zero_index;
}

State generate_state(const char *const matrix, const char zero_index, const char parent_zero_index,const char *const previous_parent_zero_indeces)
{
    State new_state = { .zero_index = zero_index };

    store_parent_zero_indeces(previous_parent_zero_indeces, parent_zero_index, new_state.parent_zero_indeces);

    cpy_in_memory(new_state.matrix, matrix, DIM);

    return new_state;
}

void print_state(const State *const state)
{
    printf("\n");

    printf("matrix : \n");

    print_array(state->matrix, DIM);

    printf("index zero : %d\n", state->zero_index);

    printf("parent index zero :\n");

    print_array(state->parent_zero_indeces, P_INDEX);

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

    printf("parent index zero :\n");

    print_array(state->parent_zero_indeces, P_INDEX);

    printf("\n");
}

char verify_state_struc_memory_integrity(const State *const state)
{
    char result = 0b0;

    char last_byte = *((char *) state + sizeof(State) - 1);

    if ( last_byte == state->zero_index ) result = 0b1;

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