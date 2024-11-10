#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "./init/init.h"
#include "./extend/extend.h"

#define LIMIT 100

int main()
{
    srand(time(NULL));

    Frontier f = init_frontier_(100);

    char error = generate_initial_state_and_add_it_to_the_frontier(&f);

    if ( error ) return 1;

    int count = 0;

    while (1)
    {
        State s;

        error = pop_from_the_frontier(&f, &s);

        if ( error ) { printf("not found\n!!!"); break; }

        print_state_matrix(&s);

        if ( evaluate_goal_state(&s) ) printf("found!\n");

        else generate_next_state_according_to_the_cost_function_and_add_it_to_the_frontier(&s, &f);

        if ( count == LIMIT ) { printf("not found\n!!!"); break; }

        printf("%d\n", count++);
    }

    free_frontier_(&f);
    
    return 0;
}