#include "./init/init.h"
#include "./struct/frontier.h"

/* ********************************* Test ********************************* */


/* ********************************* generate_initial_state ********************************* */


// int main()
// {
//     State s = generate_initial_state();

//     print_state(&s);

//     return 0;
// }


/* ********************************* add_state_to_the_frontier ********************************* */


int main()
{
    Frontier f = init_frontier_(2);

    State s1 = generate_initial_state();

    print_state(&s1);

    State s2 = generate_initial_state();

    print_state(&s2);

    State s3 = generate_initial_state();

    print_state(&s3);

    add_state_to_the_frontier(&s1, &f);

    add_state_to_the_frontier(&s2, &f);

    add_state_to_the_frontier(&s3, &f);

    print_frontier(&f, 2);

    free_frontier_(&f);

    return 0;
}


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


// int main()
// {
//     char matrix[DIM] = { 0, 1, 2, 3, 4, 5, 6, 7, 8 };

//     State s = generate_state(matrix, 0,0);

//     char result = evaluate_goal_state(&s);

//     printf("result : %d\n", result);

//     return 0;
// }