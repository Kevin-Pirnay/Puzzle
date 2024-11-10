#pragma once

#define INDEX 4


typedef struct
{
    char nb_states;

    char indeces[INDEX];
}
 Next_Indeces;

Next_Indeces generate_next_indeces(const char index, const char side);
