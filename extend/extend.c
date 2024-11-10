#include "extend.h"

#include "stdio.h"

#include "../struct/next_indeces/next_indeces.h"
#include "../utility/utility.h"
#include "../init/init.h"
#include "../struct/costs/costs.h"

#define DIM_INDEX   36
#define SIDE        3


void switch_indeces(char *const matrix, const char index_to_switch, const char zero_index)
{
    char temp = matrix[index_to_switch];

    matrix[index_to_switch] = matrix[zero_index];

    matrix[zero_index] = temp;
}

void generate_next_matrices_according_to_the_next_indeces_and_current_matrix(Next_Indeces *const next_indeces, const char *const current_matrix, const char current_zero_index, const char previous_zero_index, char *const storage)
{
    char nb_indeces = next_indeces->nb_states;

    char j = 0;

    for( char i = 0; i < nb_indeces; i++ )
    {
        if ( previous_zero_index ==  next_indeces->indeces[i]) { next_indeces->nb_states--; continue; }

        void *curr_ptr_sto = (storage + (j * DIM));

        cpy_in_memory(curr_ptr_sto, current_matrix, DIM);

        switch_indeces(curr_ptr_sto, next_indeces->indeces[i], current_zero_index);

        j++;
    }
}

char evaluate_the_cost_of_each_next_matrix_and_select_the_cost_index_with_min_cost(const char *const storage, const char nb_element)
{
    Costs c = evaluate_the_cost_of_each_next_state(storage, nb_element);

    return select_the_cost_index_with_min_cost(c, nb_element);
}

State generate_next_state_according_to_the_min_cost(const char min_cost_index, const char *const storage, const char parent_zero_index)
{
    const char *const matrix = storage + (min_cost_index * DIM);

    char zero_index = find_zero_index(matrix, DIM);

    return generate_state(matrix, zero_index, parent_zero_index);
}

char generate_next_state_according_to_the_cost_function_and_add_it_to_the_frontier(const State *const current, Frontier *const frontier)
{
    Next_Indeces n = generate_next_indeces(current->zero_index, SIDE);

    char next_matrices[DIM_INDEX];

    generate_next_matrices_according_to_the_next_indeces_and_current_matrix(&n, current->matrix, current->zero_index, current->parent_zero_index, next_matrices);

    char min_const_index = evaluate_the_cost_of_each_next_matrix_and_select_the_cost_index_with_min_cost(next_matrices, n.nb_states);

    State next_state = generate_next_state_according_to_the_min_cost(min_const_index, next_matrices, current->zero_index);

    return add_state_to_the_frontier(&next_state, frontier);
}



/* ********************************* Test ********************************* */


void print_storage(const char *const storage, const char nb_element)
{
    for ( char i = 0; i < nb_element; i++ )
    {
        const char *ptr = storage + (i * DIM);

        print_array(ptr, DIM);
    }
}


/* ********************************* Test ********************************* */


//#include <time.h>


// int main()
// {
//     srand(time(NULL));

//     Frontier f = init_frontier_(10);

//     generate_initial_state_and_add_it_to_the_frontier(&f);

//     State s;

//     pop_from_the_frontier(&f, &s);

//     Next_Indeces n = generate_next_indeces(s.zero_index, SIDE);

//     print_array(s.matrix, DIM);

//     char storage[DIM_INDEX];

//     generate_next_matrices_according_to_the_next_indeces_and_current_matrix(&n, s.matrix, s.zero_index, storage);

//     print_storage(storage, n.nb_states);

//     free_frontier_(&f);

//     return 0;
// }


/* ********************************* Test ********************************* */


// int main()
// {
//     srand(time(NULL));

//     Frontier f = init_frontier_(10);

//     generate_initial_state_and_add_it_to_the_frontier(&f);

//     State s;

//     pop_from_the_frontier(&f, &s);

//     generate_next_state_according_to_the_cost_function_and_add_it_to_the_frontier(&s, &f);

//     State r;

//     pop_from_the_frontier(&f, &r);

//     print_state(&r);

//     free_frontier_(&f);

//     return 0;
// }