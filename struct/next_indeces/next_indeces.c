#include "next_indeces.h"


void check_left(const char index, const char side, Next_Indeces *const states)
{
    if ( index % side == 0 ) return;

    states->indeces[states->nb_states] = index - 1;

    states->nb_states++;
}

void check_up(const char index, const char side, Next_Indeces *const states)
{
    if ( index < side ) return;

    states->indeces[states->nb_states] = index - side;

    states->nb_states++;
}

void check_rigth(const char index, const char side, Next_Indeces *const states)
{
    if ( (index - (side - 1)) % side == 0 ) return;

    states->indeces[states->nb_states] = index + 1;

    states->nb_states++;
}

void check_down(const char index, const char side, Next_Indeces *const states)
{
    if ( index >= side * (side - 1) ) return;

    states->indeces[states->nb_states] = index + side;

    states->nb_states++;
}

Next_Indeces generate_next_indeces(const char index, const char side)
{
    Next_Indeces states = { 0 };

    check_left(index, side, &states);

    check_up(index, side, &states);

    check_rigth(index, side, &states);

    check_down(index, side, &states);

    return states;
}
