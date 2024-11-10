#!/bin/sh

struct="./struct/costs/costs.c ./struct/frontier/frontier.c ./struct/state/state.c ./struct/next_indeces/next_indeces.c"

utility="./utility/utility.c"

init="./init/init.c"

extend="./extend/extend.c"

files="main.c $struct $utility $init $extend"

gcc $files

#./a.out