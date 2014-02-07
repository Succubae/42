#!/bin/sh

echo "rm -f corewar"
rm -f corewar
echo "make re"
make re
#echo "./corewar -dump 200 troubadour.cor turtle.cor turtle.cor troubadour.cor"
#./corewar -dump 200 troubadour.cor turtle.cor turtle.cor troubadour.cor
#echo "./corewar troubadour.cor turtle.cor turtle.cor troubadour.cor"
#./corewar troubadour.cor turtle.cor turtle.cor troubadour.cor
#echo "./corewar -dump 200 troubadour.cor troubadour.cor"
#./corewar -dump 200 troubadour.cor troubadour.cor
#echo "./corewar -dump 20000 fluttershy.cor"
./corewar -dump $1 fluttershy.cor turtle.cor fluttershy.cor turtle.cor
#./corewar -dump $1 troubadour.cor
#echo "./corewar -dump 20000 turtle.cor"
#./corewar -dump 20000 turtle.cor
