#pragma once

#include "../struct/frontier/frontier.h"


char generate_initial_state_and_add_it_to_the_frontier(Frontier *const frontier);

State generate_initial_state();

char find_zero_index(const char *const matrix, const char dim);

void shuffle(char *const matrix, const char dim);
