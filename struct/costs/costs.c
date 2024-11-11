#include "costs.h"

#include <stdlib.h>
#include <stdio.h>

#include "../state/state.h"
#include "../../utility/utility.h"


#define MAX_VALUE 1000


int evaluate_the_cost_of_a_matrix(const char *const matrix)
{
    int result = 0;

    for ( char i = 0; i < DIM; i++ )
    {
        result += abs(i - matrix[i]);
    }

    return result;
}

Costs evaluate_the_cost_of_each_next_state(const char *const storage, const char nb_element)
{
    Costs c = { 0 };

    for ( char i = 0; i < nb_element; i++ )
    {
        const char *current_ptr = storage + (i *DIM);

        c.costs[i] = evaluate_the_cost_of_a_matrix(current_ptr);
    }

    return c;
}

void reinit_min_indeces(char *const min_indeces, char *const nb_indeces)
{
    for (char i = 0; i < INDEX; i++)
    {
        min_indeces[i] = 0;
    }

    *nb_indeces = 0;
}

typedef struct
{
    int invert[INDEX];

    int total_of_invert;

    int total;
}
 Sum;

char select_the_cost_index_with_min_cost(Costs c, const char nb_element)
{
    Sum s = { 0 };

    for ( char i = 0; i < nb_element; i++ ) s.total += c.costs[i];

    for ( char i = 0; i < nb_element; i++ ) s.invert[i] = s.total - c.costs[i]; 
    
    for ( char i = 0; i < nb_element; i++ ) s.total_of_invert += s.invert[i];

    int random = 0;

    if ( s.total_of_invert ) random = rand() % s.total_of_invert;

    int total = 0;

    char index = 0;

    for ( char i = 0; i < nb_element; i++ )
    {
        total += s.invert[i];

        if ( random <= total ) { index = i; break; }
    }

    printf("random min cost selected : %d\n", c.costs[index]);

    return index;
}


// char select_the_cost_index_with_min_cost(Costs c, const char nb_element)
// {
//     int current_value = MAX_VALUE;

//     char min_indeces[INDEX];

//     char nb_indeces = 0;

//     for (char i = 0; i < nb_element; i++)
//     {
//         if ( c.costs[i] < current_value ) 
//         {
//             current_value = c.costs[i];

//             reinit_min_indeces(min_indeces, &nb_indeces);

//             min_indeces[nb_indeces] = i;

//             nb_indeces++;
//         }

//         else if ( c.costs[i] == current_value )
//         {
//             min_indeces[nb_indeces] = i;

//             nb_indeces++;
//         }
//     }
//     shuffle(min_indeces, nb_indeces);
    
//     return min_indeces[0];
// }
