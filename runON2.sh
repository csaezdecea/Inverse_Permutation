#!/bin/bash

echo "****Results ON2****" > resON2.dat

K=2

for N in {16..20}; do
    for i in {1..4}; do
        ./build/InverseON2 "$N" >> resON2.dat
        echo "run $i of logN = $N complete"
    done
done

