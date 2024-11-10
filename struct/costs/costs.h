#pragma once

#include "../next_indeces/next_indeces.h"

typedef struct
{
    int costs[INDEX];
}
 Costs;


int evaluate_the_cost_of_a_matrix(const char *const matrix);

Costs evaluate_the_cost_of_each_next_state(const char *const storage, const char nb_element);

char select_the_cost_index_with_min_cost(Costs c, const char nb_element);