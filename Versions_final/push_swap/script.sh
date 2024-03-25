#!/bin/bash
make
ARG=$(shuf -i 1-500)
#ARG=$("1 2 4 6" "3123 23 13")
#./push_swap $(ARG) > commnand.txt
#./checker $(ARG) < commnand.txt
#ARG=shuf -i 1-500 -n 500; 
./push_swap $ARG | ./checker $ARG
