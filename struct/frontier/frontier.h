#pragma once

#include "../state/state.h"


typedef struct
{
    State *array;

    int ptr;

    int end_ptr;

    int max_size;

    int nb_element;
}
 Frontier;

Frontier init_frontier_(int memory);

void free_frontier_(Frontier *frontier);

char add_state_to_the_frontier(const State *const state, Frontier *const frontier);

char pop_from_the_frontier(Frontier *const frontier, State *const result);

void print_frontier(const Frontier *const frontier, int nb_element);