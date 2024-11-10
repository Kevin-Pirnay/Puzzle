#include "init.h"

#include <stdlib.h>

#include "../struct/state/state.h"
#include "../utility/utility.h"


void fill_matrix(char *const matrix, const char dim)
{
    for(char i = 0; i < dim; i++)
    {
        matrix[i] = i;
    }
}

void generate_random_matrix(char *const matrix, char dim)
{
    fill_matrix(matrix, dim);

    shuffle(matrix, dim);
}

char find_zero_index(const char *const matrix, const char dim)
{
    char index = -1;

    for(char i = 0; i < DIM; i++)
    {
        if ( matrix[i] == 0 ) { index = i; break; }
    }

    return index;
}

State generate_initial_state()
{
    char matrix[9];

    generate_random_matrix(matrix, DIM);

    char zero_index = find_zero_index(matrix, DIM);

    char previous_zero_indeces[] = { 0, 0 };

    return generate_state(matrix, zero_index, 0, previous_zero_indeces);
}

char generate_initial_state_and_add_it_to_the_frontier(Frontier *const frontier)
{
    State s = generate_initial_state();

    return add_state_to_the_frontier(&s, frontier);
}



/* ********************************* Test ********************************* */


/* ********************************* generate_random_matrix ********************************* */


// #include "../utility/utility.h"

// #define DIM 9


// int main()
// {
//     srand(time(NULL));

//     char matrix[9];

//     generate_random_matrix(matrix, DIM);

//     print_array(matrix, DIM);

//     return 0;
// }


/* ********************************* generate_initial_state ********************************* */


// int main()
// {
//     State s = generate_initial_state();

//     print_state(&s);

//     return 0;
// }


/* ********************************* add_state_to_the_frontier, print_frontier ********************************* */


// int main()
// {
//     Frontier f = init_frontier_(100);

//     State s1 = generate_initial_state();

//     State s2 = generate_initial_state();

//     State s3 = generate_initial_state();

//     add_state_to_the_frontier(&s1, &f);

//     add_state_to_the_frontier(&s2, &f);

//     add_state_to_the_frontier(&s3, &f);

//     print_frontier(&f, 3);

//     free_frontier_(&f);

//     return 0;
// }


/* ********************************* pop_from_the_frontier ********************************* */


// int main()
// {
//     Frontier f = init_frontier_(2); //test memory size reach

//     State s1 = generate_initial_state();

//     State s2 = generate_initial_state();

//     State s3 = generate_initial_state();

//     if ( add_state_to_the_frontier(&s1, &f) ) return 1;

//     if ( add_state_to_the_frontier(&s2, &f) ) return 2;

//     if ( add_state_to_the_frontier(&s3, &f) ) return 3;

//     State r;

//     if ( pop_from_the_frontier(&f, &r) ) return 4;

//     print_state(&r);

//     if ( pop_from_the_frontier(&f, &r) ) return 5;

//     print_state(&r);

//     if ( pop_from_the_frontier(&f, &r) ) return 6;

//     print_state(&r);

//     free_frontier_(&f);

//     return 0;
// }