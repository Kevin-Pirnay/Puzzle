#pragma once

#include "../struct/state/state.h"
#include "../struct/frontier/frontier.h"

char generate_next_state_according_to_the_cost_function_and_add_it_to_the_frontier(const State *const current, Frontier *const frontier);
