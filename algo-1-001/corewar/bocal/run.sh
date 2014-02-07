#!/bin/sh

#./corewar -dump $1 -v 7 troubadour.cor
#./corewar -dump 200 troubadour.cor troubadour.cor | tail -n 128 | cut -d : -f 2- | cut -c 2-
#echo "./corewar -dump 20000 fluttershy.cor"
./corewar -dump $1 -v 1 fluttershy.cor turtle.cor fluttershy.cor turtle.cor | tail -n 128 | cut -d : -f 2- | cut -c 2-
#./corewar -dump $1 -v 4 troubadour.cor | tail -n 128 | cut -d : -f 2- | cut -c 2-
#./corewar -dump 200 -v 1 troubadour.cor turtle.cor turtle.cor troubadour.cor
