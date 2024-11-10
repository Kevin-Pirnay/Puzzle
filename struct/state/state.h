#pragma once

#define DIM     9


typedef struct
{
    char matrix[DIM];

    char zero_index;

    char parent_zero_index;
}
 State;

State generate_state(const char *const matrix, const char zero_index, const char parent_zero_index);

void print_state(const State *const state);

void print_state_matrix(const State *const state);

char verify_state_struc_memory_integrity(const State *const state);

char evaluate_goal_state(const State *const state);