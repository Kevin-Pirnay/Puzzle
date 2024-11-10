#include "frontier.h"

#include <stdlib.h>
#include <stdio.h>

#include "../../utility/utility.h"


Frontier init_frontier_(int memory)
{
    return (Frontier) 
    { 
        .ptr = 0, 
        .end_ptr = 0, 
        .nb_element = 0, 
        .max_size = memory, 
        .array = malloc(sizeof(State) * memory)
    };
}

void free_frontier_(Frontier *frontier)
{
    free(frontier->array);
}

char add_state_to_the_frontier(const State *const state, Frontier *const frontier)
{
    if ( frontier->end_ptr + 1 > frontier->max_size ) frontier->end_ptr = 0;
    
    char integrity = verify_state_struc_memory_integrity(state);

    if ( !integrity ) { printf("frontier state memory integrity breach!\n"); return 0b1; }

    void *ptr_frontier = (void *) &(frontier->array[frontier->end_ptr]);

    cpy_in_memory(ptr_frontier, state, sizeof(State));

    frontier->end_ptr++;

    frontier->nb_element++;

    return 0b0;
}

char pop_from_the_frontier(Frontier *const frontier, State *const result)
{
    if ( frontier->nb_element == 0 ) { printf("no more element in the frontier!\n"); return 0b1;}

    if ( frontier->ptr >= frontier->max_size ) frontier->ptr = 0;

    void *ptr_frontier = (void *) &(frontier->array[frontier->ptr]);

    cpy_in_memory(result, ptr_frontier, sizeof(State));

    frontier->ptr++;

    frontier->nb_element--;

    return 0b0;
}

void print_frontier(const Frontier *const frontier, int nb_element)
{
    int ptr  = 0;

    for ( int i = 0; i < nb_element; i++ )
    {
        State *s = &(frontier->array[ptr]);

        print_state(s);

        ptr++;
    }
}


/* ********************************* Test ********************************* */

// #include "../../init/init.h"

// int main()
// {
//     Frontier f1 = init_frontier_(100);
//     Frontier f2 = init_frontier_(10);

//     for ( char i = 0; i < 100; i++ )
//     {
//         State s = generate_initial_state();

//         add_state_to_the_frontier(&s, &f1);
//         add_state_to_the_frontier(&s, &f2);
//     }

//     State r1;

//     for ( char i = 0; i < 91; i++ )
//     {
//         pop_from_the_frontier(&f1, &r1);
//     }

//     State r2;

//     for ( char i = 0; i < 1; i++ )
//     {
//         pop_from_the_frontier(&f2, &r2);
//     }

//     print_state(&r1);

//     print_state(&r2);

//     free_frontier_(&f1);
//     free_frontier_(&f2);

//     return 0;
// }
