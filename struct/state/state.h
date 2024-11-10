#pragma once

#define DIM     9
#define P_INDEX 3


typedef struct
{
    char matrix[DIM];

    char parent_zero_indeces[P_INDEX];
    
    char zero_index;
}
 State;

State generate_state(const char *const matrix, const char zero_index, const char parent_zero_index,const char *const previous_parent_zero_indeces);

void print_state(const State *const state);

void print_state_matrix(const State *const state);

char verify_state_struc_memory_integrity(const State *const state);

char evaluate_goal_state(const State *const state);