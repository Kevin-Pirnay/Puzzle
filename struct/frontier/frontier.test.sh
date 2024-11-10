#!/bin/sh

gcc frontier.c ../state/state.c ../../init/init.c ../../utility/utility.c -o test

./test

