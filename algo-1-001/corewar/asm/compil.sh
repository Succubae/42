#!/bin/sh

echo "./asm troubadour.s"
./asm troubadour.s
echo "cp troubadour.cor ../vm/"
cp troubadour.cor ../vm/
echo "cp troubadour.cor ../bocal/"
cp troubadour.cor ../bocal/
